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

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Airplane airplane;
Water sea;
Dashboard dashboard;
vector<Island> island;
Navigation navigation;
vector<Sphere> bomb;
Sphere sph;
vector<int> checkpoint = {7,14,21,1,8,15,22,2,9,16,23,3,10,17,24,4,11,18,25,5,12,19,26,6,13,20,27};


const double pi = 4 * atan(1);
int view=1;

bool keypress = false;
bool keypress_c = false;
bool keypress_b = false;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0, camera_x = 0,camera_y = 8,camera_z = 18,target_x = 0 ,target_y = 8, target_z = 0;

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
    for(int i=0;i<island.size();i++)
        island[i].draw(VP);
    navigation.draw(VP);
    for(int i=0;i<bomb.size();i++)
        bomb[i].draw(VP);
    //sph.draw(VP);
    // cout << airplane.position.y <<endl;
}

bool bomb_collision(int i){
    // cout << "X "<<bomb[i].position.x << " " <<island[navigation.checkpoint].position.x <<endl;
    // cout << "Z "<<bomb[i].position.z << " " <<island[navigation.checkpoint].position.z <<endl;
    if((bomb[i].position.x < island[navigation.checkpoint].position.x + 10) && (bomb[i].position.x > island[navigation.checkpoint].position.x - 10))
        if((bomb[i].position.z < island[navigation.checkpoint].position.z + 10) && (bomb[i].position.z > island[navigation.checkpoint].position.z - 10))
            if(bomb[i].position.y < island[navigation.checkpoint].position.y + 85)
                return true;
    return false;
}

void checkbomb_collision(){
            // cout << "should change\n";
            // cout << "checkpoint no "<<navigation.checkpoint <<endl;
            // cout << "is checkpoint "<< island[navigation.checkpoint].ischeckpoint <<endl;
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

void tick_input(GLFWwindow *window) {
    int c  = glfwGetKey(window, GLFW_KEY_C);
    int a  = glfwGetKey(window, GLFW_KEY_A);
    int d  = glfwGetKey(window, GLFW_KEY_D);
    int w  = glfwGetKey(window, GLFW_KEY_W);
    int s  = glfwGetKey(window, GLFW_KEY_S);
    int b  = glfwGetKey(window, GLFW_KEY_B);
    int left = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    
    if (c && !keypress_c){
        view=(view)%4+1;
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


    if (w){
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

    if (up){
        airplane.move_forward();
    }
    
    if (down){
        airplane.move_backward();
    }

    if (b && !keypress_b){
        keypress_b = true;
        release_bomb();
    }
    if(b == GLFW_RELEASE && keypress_b == true){
        keypress_b = false;
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
//     cout << "angle "<<navigation.rotation<<endl;
//     cout << "posx "<<posx<<endl;
//     cout << "posz "<<posz<<endl;
//     cout << "navigation posx "<<navigation.position.x<<endl;
//     cout << "navigation posz "<<navigation.position.z<<endl;
}

void view_camera(){

    // cout << "rot "<< airplane.rotation <<endl;
    // cout << "x "<< airplane.position.x <<endl;
    // cout << "z "<< airplane.position.z <<endl;

    //follow view
    if (view == 1){
        camera_x = airplane.position.x + 20 * sin(airplane.rotation * (pi/180)) ;
        camera_y = airplane.position.y + 8 ;
        camera_z = airplane.position.z + 20 * cos(airplane.rotation * (pi/180));

        target_x = airplane.position.x ;
        target_y = airplane.position.y + 8;
        target_z = airplane.position.z;

        dashboard.set_position(target_x, target_y + 10, target_z);
        // dashboard.position.x = target_x ;
        // dashboard.position.y = target_y + 10;
        // dashboard.position.z = target_z ;
        dashboard.rotation = airplane.rotation;

        navigation.set_position(airplane.position.x - 5 * sin(airplane.rotation * (pi/180)),target_y + 12,airplane.position.z  - 5 * cos(airplane.rotation * (pi/180)));
    }

    //camera view
    else if (view == 2){
        camera_x = airplane.position.x + 20 * sin(airplane.rotation * (pi/180));
        camera_y = airplane.position.y + 50;
        camera_z = airplane.position.z + 20 * cos(airplane.rotation * (pi/180));

        target_x = airplane.position.x;
        target_y = airplane.position.y ;
        target_z = airplane.position.z; 

        dashboard.set_position(target_x + 5 * sin(airplane.rotation * (pi/180)), target_y + 2, target_z + 5 * cos(airplane.rotation * (pi/180)));
        dashboard.rotation = airplane.rotation;
        // dashboard.set_position(airplane.position.x,airplane.position.y + 2 ,airplane.position.z);
        navigation.set_position(airplane.position.x - 20 * sin(airplane.rotation * (pi/180)),target_y + 10,airplane.position.z  - 20 * cos(airplane.rotation * (pi/180)));
    }

    //plane view
    else if( view == 3){
        camera_x = airplane.position.x - 1 * sin(airplane.rotation * (pi/180));
        camera_y = airplane.position.y ;
        camera_z = airplane.position.z - 1 * cos(airplane.rotation * (pi/180));

        target_x = airplane.position.x - 20 * sin(airplane.rotation * (pi/180)) ;
        target_y = airplane.position.y ;
        target_z = airplane.position.z - 20 * cos(airplane.rotation * (pi/180));

        // dashboard.position.x = target_x;
        // dashboard.position.y = target_y + 7;
        // dashboard.position.z = target_z ;
        dashboard.set_position(target_x, target_y + 7, target_z);
        dashboard.rotation = airplane.rotation;

       navigation.set_position(airplane.position.x - 20 * sin(airplane.rotation * (pi/180)),target_y + 10,airplane.position.z  - 20 * cos(airplane.rotation * (pi/180)));

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
    else if( view == 5){
        //write code here
    }
    
}

void tick_elements() {
    view_camera();
    set_navigation();
    bomb_gravity();
    checkbomb_collision();
    // navigation.tick();
    airplane.tick();
    for(int i=0;i<island.size();i++)
        island[i].tick(); 
    // camera_rotation_angle += 1;
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
    // navigation.checkpoint = 0;
    sph = Sphere(0,0,-100,10,COLOR_ENEMY);
    navigation = Navigation(0,0,-100,COLOR_ENEMY);

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

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    // Matrices.projection = glm::ortho(left, right, bottom, top, -50.0f, 500.0f);
    Matrices.projection = glm::perspective(45.0f, 1.0f, 10.0f, 10000.0f);
}
