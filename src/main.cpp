#include "main.h"
#include "timer.h"
#include "ball.h"
#include "cylinder.h"
#include "sphere.h"
#include "ellipse.h"
#include "airplane.h"
#include "water.h"
#include "dashboard.h"
#include "island.h"
#include "navigation.h"
#include "fuel.h"
#include "volcano.h"
#include "rings.h"
#include "parachute.h"
#include "compass.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

// Initialisation
Airplane airplane;
Water sea;
Dashboard dashboard;
vector<Island> island;
Navigation navigation;
vector<Sphere> bomb;
vector<Ellipse> missiles;
vector<Ellipse> airplane_missiles;
vector<Fuel> fuel;
vector<Volcano> volcano;
vector<Rings> rings;
vector<int> checkpoint = {7,14,21,1,8,15,22,2,9,16,23,3,10,17,24,4,11,18,25,5,12,19,26,6,13,20,27};
vector<Parachute> parachute;
Compass compass;
pid_t pid = 0;
bool sound = true;


//Variable declaration
const double pi = 4 * atan(1);
int view=1;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0, camera_x = 0,camera_y = 8,camera_z = 18,target_x = 0 ,target_y = 8, target_z = 0;

//keypress initialisation
bool keypress = false;
bool keypress_c = false;
bool keypress_b = false;
bool keypress_m = false;
bool keypress_k = false;
bool keypress_l = false;
bool looping_flag = false;
bool rolling_flag = false;

//timer declaration
Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);
    
    glm::vec3 eye ( camera_x, camera_y, camera_z );
    // glm::vec3 eye ( 1, 1, 1 );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (target_x, target_y, target_z);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D

    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    
    // Scene render
    sea.draw(VP);
    airplane.draw(VP);
    dashboard.draw(VP,view);
    navigation.draw(VP);
    compass.draw(VP,view);
    dashboard.print_speed(((int) (airplane.speed * 10)), (int) (airplane.alt), (int) (airplane.fuel));

    for(int i=0;i<island.size();i++)
        island[i].draw(VP);

    for(int i=0;i<bomb.size();i++)
        bomb[i].draw(VP);

    for(int i=0;i<missiles.size();i++)
        missiles[i].draw(VP);

    for(int i=0;i<airplane_missiles.size();i++)
        airplane_missiles[i].draw(VP);

    for(int i=0;i<fuel.size();i++)
        fuel[i].draw(VP);

    for(int i=0;i<volcano.size();i++)
        volcano[i].draw(VP);

    for(int i=0;i<rings.size();i++)
        rings[i].draw(VP);

    for(int i=0;i<parachute.size();i++)
        parachute[i].draw(VP);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) < (a.length + b.length)/2) && (abs(a.z - b.z) < (a.width + b.width)/2) && (abs(a.y - b.y) < (a.height + b.height)/2);
}

bool detect_collision_volcano(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) < (a.length + b.length)/2) && (abs(a.z - b.z) < (a.width + b.width)/2) ;
}

int increment;

void missile_move(){
    for(int i=0;i<missiles.size();i++){
        Ellipse missile = missiles[i];

        if(missile.position.x < (island[navigation.checkpoint].position.x - 400 ) || missile.position.x > (island[navigation.checkpoint].position.x + 400) || missile.position.y < (island[navigation.checkpoint].position.y - 400 ) || missile.position.y > (island[navigation.checkpoint].position.y + 400 ))
            missiles.erase(missiles.begin()+i);
        
        if(detect_collision_volcano(missiles[i].bounding_box(), airplane.bounding_box())){
            missiles.erase(missiles.begin()+i);
            airplane.score -= 1;
            if(airplane.score < 0){
                cout << "YOU ARE DEAD\n";
                quit(window);
            }
        }
        else
            missiles[i].set_position(missile.position.x - 4 * sin((missile.theta) *(pi/180)) * sin(missile.phi * (pi/180)), missile.position.y + 4 * cos(missile.theta *(pi/180)), missile.position.z - 4 * sin((missile.theta) *(pi/180)) * cos(missile.phi * (pi/180)));
    }
}

void missile_release(){
    increment = (increment+1)%60;
    if(increment == 0){
        if((airplane.position.x < island[navigation.checkpoint].position.x + 400) &&(airplane.position.x > island[navigation.checkpoint].position.x - 400)){
            if((airplane.position.z < island[navigation.checkpoint].position.z + 400) &&(airplane.position.z > island[navigation.checkpoint].position.z - 400)){
                int i = navigation.checkpoint;

                Ellipse ellipse =Ellipse(island[i].position.x,island[i].position.y+85,island[i].position.z,1,1,1,COLOR_RED);

                double posx= island[i].position.x;
                double posy= island[i].position.y;
                double posz= island[i].position.z;

                double angle = acos((airplane.position.z -posz)*(-1)/sqrt(((posx-airplane.position.x)*(posx-airplane.position.x))+((posz-airplane.position.z)*(posz-airplane.position.z)))) * (180/pi);   
                
                angle = abs(angle);
                if(posx < airplane.position.x)
                    angle *= -1;
                ellipse.phi = angle;
                
                angle = acos((airplane.position.y - (posy+90))/sqrt((posx-airplane.position.x)*(posx-airplane.position.x)+((posy+90)-airplane.position.y)*((posy+90)-airplane.position.y)+(posz-airplane.position.z)*(posz-airplane.position.z)))  * (180/pi);
                ellipse.theta = angle;

                missiles.push_back(ellipse);
            }        
        }
    }
}

bool bomb_collision(int i){
    if((bomb[i].position.x < island[navigation.checkpoint].position.x + 10) && (bomb[i].position.x > island[navigation.checkpoint].position.x - 10))
        if((bomb[i].position.z < island[navigation.checkpoint].position.z + 10) && (bomb[i].position.z > island[navigation.checkpoint].position.z - 10))
            if(bomb[i].position.y < island[navigation.checkpoint].position.y + 85)
                return true;
    return false;
}

void checkbomb_collision(){
    for(int i=0;i<bomb.size();i++){
        if(bomb_collision(i)){
            cout << "change\n";
            bomb.erase(bomb.begin()+i);
            island[navigation.checkpoint].checkpointcomplete = 1;
            island[navigation.checkpoint].ischeckpoint = 0;
            int j = checkpoint[0];
            checkpoint.erase(checkpoint.begin()+0); 
            navigation.checkpoint = j;
            island[navigation.checkpoint].ischeckpoint = 1;
            fuel.push_back(Fuel(island[navigation.checkpoint].position.x + 20, 20, island[navigation.checkpoint].position.z +25, COLOR_FIRE));
            airplane.score += 30;
        }
    }
}

bool airplane_missilecollision(int i){
    Ellipse missile = airplane_missiles[i];
    if((missile.position.x < island[navigation.checkpoint].position.x + 10) && (missile.position.x > island[navigation.checkpoint].position.x - 10))
        if((missile.position.z < island[navigation.checkpoint].position.z + 10) && (missile.position.z > island[navigation.checkpoint].position.z - 10))
            if(missile.position.y < island[navigation.checkpoint].position.y + 95)
                return true;
    return false;
}

void checkairplanemissile_collision(){
     for(int i=0;i<airplane_missiles.size();i++){
        if(airplane_missilecollision(i)){
            cout << "change\n";
            airplane_missiles.erase(airplane_missiles.begin()+i);
            island[navigation.checkpoint].checkpointcomplete = 1;
            island[navigation.checkpoint].ischeckpoint = 0;
            int j = checkpoint[0];
            checkpoint.erase(checkpoint.begin()+0); 
            navigation.checkpoint = j;
            island[navigation.checkpoint].ischeckpoint = 1;
            fuel.push_back(Fuel(island[navigation.checkpoint].position.x + 20, 20, island[navigation.checkpoint].position.z +25, COLOR_FIRE));
            airplane.score += 20;
        }
    }
}

void bomb_gravity(){
    for(int i=0;i<bomb.size();i++){
        if(bomb[i].position.y < sea.position.y)
            bomb.erase(bomb.begin()+i);
        else
            bomb[i].set_position(bomb[i].position.x, bomb[i].position.y-0.2,bomb[i].position.z);
    }
}

void release_bomb(){
    bomb.push_back(Sphere(airplane.position.x, airplane.position.y,airplane.position.z,1,COLOR_RED));
}

void airplane_missilemove(){
    for(int i=0;i<airplane_missiles.size();i++){
        Ellipse missile = airplane_missiles[i];
        if(missile.position.x < -3000 || missile.position.x > 3000 || missile.position.z < -3000 || missile.position.z > 3000 || missile.position.y < -80)
            airplane_missiles.erase(airplane_missiles.begin()+i);
        airplane_missiles[i].set_position(missile.position.x - 3 * sin(missile.theta * (pi/180)) * sin(missile.phi * (pi/180)), missile.position.y - 3 * cos(missile.theta * (pi/180)), missile.position.z - 3 * sin(missile.theta * (pi/180)) * cos(missile.phi * (pi/180)));
    }
}

void airplane_releasemissile(){

    int i = navigation.checkpoint;
    double posx= island[i].position.x;
    double posy= island[i].position.y;
    double posz= island[i].position.z;

    if(airplane.position.x > (posx - 400) && airplane.position.x < (posx+400) && airplane.position.z > (posz - 400) && airplane.position.z < (posz + 400)){
        Ellipse missile = Ellipse(airplane.position.x, airplane.position.y, airplane.position.z,2,1,1,COLOR_BLUE);

        double angle = acos((posz - airplane.position.z)*(-1)/sqrt(((posx-airplane.position.x)*(posx-airplane.position.x))+((posz-airplane.position.z)*(posz-airplane.position.z)))) * (180/pi);   

        angle = abs(angle);
        if(airplane.position.x < posx)
            angle *= -1;
        missile.phi = angle;

        angle = acos(((posy+90)-airplane.position.y) * (-1)/sqrt((posx-airplane.position.x)*(posx-airplane.position.x)+((posy+90)-airplane.position.y)*((posy+90)-airplane.position.y)+(posz-airplane.position.z)*(posz-airplane.position.z)))  * (180/pi);
        missile.theta = angle;

        airplane_missiles.push_back(missile);
    }

    else{
        Ellipse missile = Ellipse(airplane.position.x, airplane.position.y, airplane.position.z,2,1,1,COLOR_BLUE);

        missile.theta=90;
        missile.phi=airplane.rotation;

        airplane_missiles.push_back(missile);
    }
   
}

void looping(){
    if(looping_flag){
        airplane.rotation += 10;
        if(airplane.rotation >= 360){
            looping_flag = false;
            airplane.rotation = 0;
        }
    }
}

void rolling(){
    if(rolling_flag){
        airplane.rotation2 += 10;
        if(airplane.rotation2 >= 360){
            rolling_flag = false ;
            airplane.rotation2 = 0;
        }
    }
}

void tick_input(GLFWwindow *window) {

    airplane.speed_decreaseflag = 1;

    int c  = glfwGetKey(window, GLFW_KEY_C);//camera change
    int a  = glfwGetKey(window, GLFW_KEY_A);//tilt left
    int d  = glfwGetKey(window, GLFW_KEY_D);//tilt right
    int space  = glfwGetKey(window, GLFW_KEY_SPACE);// move up
    int s  = glfwGetKey(window, GLFW_KEY_S);//move down
    int mouse_right  = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);//bomb
    int mouse_left = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);//missile
    int left = glfwGetKey(window, GLFW_KEY_Q);//move left
    int right = glfwGetKey(window, GLFW_KEY_E);//move right
    int w = glfwGetKey(window, GLFW_KEY_W);//move forward
    int k = glfwGetKey(window, GLFW_KEY_K);//looping the loop
    int l = glfwGetKey(window, GLFW_KEY_L);//barrel roll
    
    if (c && !keypress_c){
        view=(view)%5+1;
        keypress_c = true;
    }
    if (c == GLFW_RELEASE && keypress_c==true){
        keypress_c =false;
    }

    if (a){
        airplane.tilt_left();
    }

    if (d){
        airplane.tilt_right();
    }

    if (space){
        airplane.move_upward();
    }

    if (s){
        airplane.move_downward();
    }

    if (left){
        airplane.move_left();
    }
    
    if (right){
        airplane.move_right();
    }

    if (w){
        airplane.speed_increase();
        airplane.speed_decreaseflag = 0;
    }
    
    if (mouse_right &&!keypress_b){
        keypress_b = true;
        release_bomb();
    }
    if (mouse_right == GLFW_RELEASE && keypress_b == true){
        keypress_b = false;
    }

    if (mouse_left && !keypress_m){
        keypress_m = true;
        airplane_releasemissile();
    }
    if (mouse_left == GLFW_RELEASE && keypress_m == true){
        keypress_m = false;
    }

    if (k && !keypress_k){
        looping_flag =true;
        keypress_k =true;
        looping();
    }

    if(k == GLFW_RELEASE && keypress_k == true){
        keypress_k = false;
    }

    if (l && !keypress_l){
        rolling_flag = true;
        keypress_l =true;
        rolling();
    }

    if(l == GLFW_RELEASE && keypress_l == true){
        keypress_l = false;
    }
    
    
}



void airplanemissileparachute_collision(){
    for(int i=0;i<airplane_missiles.size();i++){
        for(int j=0;j<parachute.size();j++){
            if(detect_collision(airplane_missiles[i].bounding_box(),parachute[j].bounding_box())){
                parachute[j].active =0;
                airplane_missiles.erase(airplane_missiles.begin()+i);
                airplane.score += 15;
    }
        }
    }
}

void ringplane_collision(){
    for(int i=0;i<rings.size();i++){
        if(detect_collision(rings[i].bounding_box(),airplane.bounding_box())){
            if(rings[i].active == 1)
                airplane.score += 10;
            rings[i].active = 0;
        }
    }
}

void fuelplane_collision(){
    for(int i=0;i<fuel.size();i++){
        if(detect_collision(fuel[i].bounding_box(),airplane.bounding_box())){
            airplane.fuel += 10;
            if(airplane.fuel > 100)
                airplane.fuel = 100;
            fuel.erase(fuel.begin()+i);
        }
    }
}



void detect_volcano_collision(){
    for(int i=0;i<volcano.size();i++){
        if(detect_collision_volcano(airplane.bounding_box(),volcano[i].bounding_box())){
            cout << "GAME OVER, YOU ARE DEAD\n";
            quit(window);
        }
    }
}

void set_navigation(){
    int i = navigation.checkpoint;
    double posx= island[i].position.x;
    double posz= island[i].position.z;
    double angle = acos((posz-navigation.position.z)*(-1)/sqrt(((posx-navigation.position.x)*(posx-navigation.position.x))+((posz-navigation.position.z)*(posz-navigation.position.z)))) * (180/pi);   
    angle = abs(angle);
    if(posx > navigation.position.x)
        angle *= -1;
    navigation.rotation = angle;
}

void view_camera(){

    //follow view
    if (view == 1){
        camera_x = airplane.position.x + 20 * sin(airplane.rotation * (pi/180)) ;
        camera_y = airplane.position.y + 8 ;
        camera_z = airplane.position.z + 20 * cos(airplane.rotation * (pi/180));

        target_x = airplane.position.x ;
        target_y = airplane.position.y + 8;
        target_z = airplane.position.z;

        dashboard.set_position(target_x, target_y + 10, target_z);
        compass.set_position(target_x - 5 * sin(airplane.rotation * (pi/180)) -  10 * cos(airplane.rotation * (pi/180)), target_y + 10, target_z - 5 * cos(airplane.rotation * (pi/180)) + 10 * sin(airplane.rotation * (pi/180)));
        navigation.set_position(airplane.position.x - 5 * sin(airplane.rotation * (pi/180)),target_y + 12,airplane.position.z  - 5 * cos(airplane.rotation * (pi/180)));
        
        dashboard.rotation = airplane.rotation;
        compass.rotation = airplane.rotation;
        compass.rotation2 = 0;
        dashboard.rotation2 = 0;

    }

    //top view
    else if (view == 2){
        camera_x = airplane.position.x + 20 * sin(airplane.rotation * (pi/180));
        camera_y = airplane.position.y + 50;
        camera_z = airplane.position.z + 20 * cos(airplane.rotation * (pi/180));

        target_x = airplane.position.x;
        target_y = airplane.position.y ;
        target_z = airplane.position.z; 

        dashboard.set_position(target_x + 5 * sin(airplane.rotation * (pi/180)), target_y + 2, target_z + 5 * cos(airplane.rotation * (pi/180)));
        dashboard.rotation = airplane.rotation;
        compass.set_position(target_x - 20 * sin(airplane.rotation * (pi/180)) -  20 * cos(airplane.rotation * (pi/180)), target_y + 10, target_z - 20 * cos(airplane.rotation * (pi/180)) + 20 * sin(airplane.rotation * (pi/180)));
        navigation.set_position(airplane.position.x - 20 * sin(airplane.rotation * (pi/180)),target_y + 10,airplane.position.z  - 20 * cos(airplane.rotation * (pi/180)));

        compass.rotation = 0;
        compass.rotation2 = 90;
    }

    //plane view
    else if( view == 3){
        camera_x = airplane.position.x - 1 * sin(airplane.rotation * (pi/180));
        camera_y = airplane.position.y ;
        camera_z = airplane.position.z - 1 * cos(airplane.rotation * (pi/180));

        target_x = airplane.position.x - 20 * sin(airplane.rotation * (pi/180)) ;
        target_y = airplane.position.y ;
        target_z = airplane.position.z - 20 * cos(airplane.rotation * (pi/180));

        dashboard.set_position(target_x, target_y + 10, target_z);
        compass.set_position(target_x - 5 * sin(airplane.rotation * (pi/180)) -  10 * cos(airplane.rotation * (pi/180)), target_y + 10, target_z - 5 * cos(airplane.rotation * (pi/180)) + 10 * sin(airplane.rotation * (pi/180)));
        navigation.set_position(airplane.position.x - 20 * sin(airplane.rotation * (pi/180)),target_y + 8,airplane.position.z  - 20 * cos(airplane.rotation * (pi/180)));

        dashboard.rotation = airplane.rotation;
        compass.rotation = airplane.rotation;
        compass.rotation2 = 0;
        dashboard.rotation2 = 0;

    }

    //tower view
    else if( view == 4){
        camera_x = airplane.position.x - 100 ;
        camera_y = airplane.position.y + 50;
        camera_z = airplane.position.z + 100;

        target_x = airplane.position.x ;
        target_y = airplane.position.y;
        target_z = airplane.position.z;

        navigation.set_position(airplane.position.x - 20 * sin(airplane.rotation * (pi/180)),target_y ,airplane.position.z  - 20 * cos(airplane.rotation * (pi/180)));

    }

    //helicopter-cam view
    else if( view == 5 && keypress_c == true){
        // write code here
        camera_x = airplane.position.x + 20 * sin(airplane.rotation * (pi/180)) ;
        camera_y = airplane.position.y + 8 ;
        camera_z = airplane.position.z + 20 * cos(airplane.rotation * (pi/180));

        target_x = airplane.position.x ;
        target_y = airplane.position.y + 8;
        target_z = airplane.position.z;

        dashboard.set_position(target_x, target_y + 10, target_z);
        compass.set_position(target_x - 5 * sin(airplane.rotation * (pi/180)) -  10 * cos(airplane.rotation * (pi/180)), target_y + 10, target_z - 5 * cos(airplane.rotation * (pi/180)) + 10 * sin(airplane.rotation * (pi/180)));
        navigation.set_position(airplane.position.x - 5 * sin(airplane.rotation * (pi/180)),target_y + 12,airplane.position.z  - 5 * cos(airplane.rotation * (pi/180)));
        
        dashboard.rotation = airplane.rotation;
        compass.rotation = airplane.rotation;
        compass.rotation2 = 0;
        dashboard.rotation2 = 0;

    }
    
}

int score_increment=0;
void airplanescore_increment(){
    score_increment = (score_increment+1)%200;
    if(score_increment == 0)
        airplane.score += 1;
}

void airplane_alt(){
    airplane.alt = (int) (airplane.position.y - sea.position.y);
    if(airplane.alt == 0){
        cout << "GAME OVER, YOU ARE DEAD\n";
        quit(window);
    }
}

int fuel_decrement=0;
void fuel_update(){
    fuel_decrement = (fuel_decrement+1)%100;
    if(fuel_decrement == 0 && airplane.speed_decreaseflag == 0){
        airplane.fuel -= 1;
        if(airplane.fuel <= 0){
            cout << "GAME OVER, FUEL EXHAUSTED AND YOU ARE DEAD\n";
            quit(window);
        }
    }
}

void tick_elements() {
    view_camera();
    set_navigation();
    bomb_gravity();
    checkbomb_collision();
    missile_release();
    missile_move();
    airplane_missilemove();
    checkairplanemissile_collision();
    fuelplane_collision();
    detect_volcano_collision();
    ringplane_collision();
    airplanemissileparachute_collision();
    airplane.tick();
    fuel[0].tick();
    for(int i=0;i<island.size();i++)
        island[i].tick(); 
    for(int i=0;i<parachute.size();i++)
        parachute[i].tick(); 
    airplanescore_increment();
    airplane_alt();
    airplane.move_forward();
    airplane.speed_decrease();
    fuel_update();
    looping();
    rolling();
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    airplane = Airplane(0,0,-2, COLOR_RED);
    sea  =  Water(0, -80, 0, COLOR_BLUE);
    dashboard = Dashboard(-2,0,-2);
    for(int i=0;i<7;i++){
        double x = fRand(0,3000);
        double z = fRand(0,3000);
        island.push_back(Island(x,-140,z, COLOR_GREEN));
    }
    for(int i=0;i<7;i++){
        double x = fRand(0,3000);
        double z = fRand(-3000,0);
        island.push_back(Island(x,-140,z, COLOR_GREEN));
    }
    for(int i=0;i<7;i++){
        double x = fRand(-3000,0);
        double z = fRand(-3000,0);
        island.push_back(Island(x,-140,z, COLOR_GREEN));
    }
    for(int i=0;i<7;i++){
        double x = fRand(-3000,0);
        double z = fRand(0,3000);
        island.push_back(Island(x,-140,z, COLOR_GREEN));
    }
    island[0].ischeckpoint = 1;
    navigation = Navigation(0,0,-100,COLOR_ENEMY);
    fuel.push_back(Fuel(island[0].position.x+20,20,island[0].position.z+25,COLOR_FIRE));
    for(int i=0;i<2;i++){
        double x =fRand(-1500,1500);
        double z =fRand(0,3000);
        volcano.push_back(Volcano(x,sea.position.y,z, COLOR_FIRE));
    }
    for(int i=0;i<2;i++){
       double x = fRand(1500,3000);
        double z = fRand(-3000,0);
        volcano.push_back(Volcano(x,sea.position.y,z, COLOR_FIRE));
    }
    for(int i=0;i<2;i++){
        double x =fRand(-1500,0);
        double z =fRand(-3000,0);
        volcano.push_back(Volcano(x,sea.position.y,z, COLOR_FIRE));
    }
    for(int i=0;i<2;i++){
        double x =fRand(-3000,0);
        double z =fRand(0,3000);
        volcano.push_back(Volcano(x,sea.position.y,z, COLOR_FIRE));
    }
    for(int i=0;i<20;i++){
        double x =fRand(-3000,3000);
        double z =fRand(-3000,3000);
        rings.push_back(Rings(x,50,z,10,8,COLOR_GREEN));
    }
    for(int i=0;i<5;i++){
        double x = fRand(0,3000);
        double z = fRand(0,3000);
        parachute.push_back(Parachute(x,50,z,10,10,10,COLOR_BLUE));
    }
    for(int i=0;i<5;i++){
        double x = fRand(0,3000);
        double z = fRand(-3000,0);
        parachute.push_back(Parachute(x,50,z,10,10,10,COLOR_BLUE));
    }
    for(int i=0;i<5;i++){
        double x = fRand(-3000,0);
        double z = fRand(-3000,0);
        parachute.push_back(Parachute(x,50,z,10,10,10,COLOR_BLUE));
    }
    for(int i=0;i<5;i++){
        double x = fRand(-3000,0);
        double z = fRand(0,3000);
        parachute.push_back(Parachute(x,50,z,10,10,10,COLOR_BLUE));
    }
    compass = Compass(-10,10,-10,2,COLOR_BLACK);
    

    cout << cos(-52.39)<<endl;
    cout << cos(52.39)<<endl;

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}



int main(int argc, char **argv) {
    srand(time(0));
    int width  = 800;
    int height = 800;

    window = initGLFW(width, height);

    initGL (window, width, height);

    pid = fork();
    if (pid == 0)
    {
        while (sound)
        {
            audio_init();
            audio_play();
            audio_close();
        }
        _exit(0);
    }

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            tick_elements();

            char str1[30];
            sprintf(str1, "%lu", checkpoint.size()+1);
            char final_str[120] = "Checkpoints Remaining : ";
            strcat(final_str, str1);

            char str2[10];
            sprintf(str2, "%d", (airplane.score));
            strcat(final_str, "      Score : ");
            strcat(final_str, str2);

            char str3[10];
            sprintf(str3, "%d", ((int) (airplane.speed * 10)));
            strcat(final_str, "      Speed : ");
            strcat(final_str, str3);

            char str4[10];
            sprintf(str4, "%d", ((int) airplane.alt));
            strcat(final_str, "      Alt : ");
            strcat(final_str, str4);

            char str5[10];
            sprintf(str5, "%d", ((int) airplane.fuel));
            strcat(final_str, "      Fuel : ");
            strcat(final_str, str5);

            char str6[10];
            sprintf(str6, "%d", ((int) view));
            strcat(final_str, "      View : ");
            strcat(final_str, str6);
            

            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            glfwSetWindowTitle(window, final_str);

            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}


void reset_screen() {
    // Matrices.projection = glm::ortho(left, right, bottom, top, -50.0f, 500.0f);
    Matrices.projection = glm::perspective(45.0f, 1.0f, 10.0f, 10000.0f);
}

void heli_camera(float x, float y){
    if (view == 5){
        target_x = airplane.position.x + x - 400;
            if(y - 400 <= 0 ){
                target_y = airplane.position.y+ (400-y)/2;
            }
    }
    else{
        return;
    }
}

void zoom_camera(int type){

    if(view==5){
         float n = target_z-camera_z;
        if(type==1){
            if(camera_z - target_z > 10)
                camera_z-=5;
        }
        else if(type==-1){
            if(camera_z - target_z < 200)
                camera_z+=5;
        }
        camera_x = (target_x - camera_x) * (camera_z - target_z) / n + target_x;
        camera_y = (target_y - camera_y) * (camera_z - target_z) / n + target_y;
    }
    else {
       return;
    }
}
