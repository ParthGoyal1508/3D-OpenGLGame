#include "airplane.h"
#include "cylinder.h"
#include "ellipse.h"
#include "main.h"

using namespace std;

GLfloat vertex_buffer_data[100000];
int cur = 0;
const double pi = 4 * atan(1);


//cylinder in z direction with 40*12
void Airplane::make_cylinder(float x, float y, float z, float radius1, float radius2, float height){
    const int n = 40;
    double angle = 0;
    double diff = (2 * pi) / (double)n;

    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = x+0.0f;
        vertex_buffer_data[cur++] = y+0.0f;
        vertex_buffer_data[cur++] = z-height/2;

        //Point with lower angle
        vertex_buffer_data[cur++] = x+radius1 * cos(angle);
        vertex_buffer_data[cur++] = y+radius1 * sin(angle);
        vertex_buffer_data[cur++] = z-height/2;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = x+radius1 * cos(angle);
        vertex_buffer_data[cur++] = y+radius1 * sin(angle);
        vertex_buffer_data[cur++] = z-height/2;
    }

    angle = 0;
    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = x+0.0f;
        vertex_buffer_data[cur++] = y+0.0f;
        vertex_buffer_data[cur++] = z+height/2;

        //Point with lower angle
        vertex_buffer_data[cur++] = x+radius2 * cos(angle);
        vertex_buffer_data[cur++] = y+radius2 * sin(angle);
        vertex_buffer_data[cur++] = z+height/2;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = x+radius2 * cos(angle);
        vertex_buffer_data[cur++] = y+radius2 * sin(angle);
        vertex_buffer_data[cur++] = z+height/2;
    }

    angle = 0;
    for (int i=0; i < n; i++){
        vertex_buffer_data[cur++] = x+radius1 * cos(angle);
        vertex_buffer_data[cur++] = y+radius1 * sin(angle);
        vertex_buffer_data[cur++] = z-height/2;

        vertex_buffer_data[cur++] = x+radius2 * cos(angle);
        vertex_buffer_data[cur++] = y+radius2 * sin(angle);
        vertex_buffer_data[cur++] = z+height/2;

        angle+=diff;
        vertex_buffer_data[cur++] = x+radius1 * cos(angle);
        vertex_buffer_data[cur++] = y+radius1 * sin(angle);
        vertex_buffer_data[cur++] = z-height/2;

        angle-=diff;
        vertex_buffer_data[cur++] = x+radius2 * cos(angle);
        vertex_buffer_data[cur++] = y+radius2 * sin(angle);
        vertex_buffer_data[cur++] = z+height/2;

        angle+=diff;
        vertex_buffer_data[cur++] = x+radius1 * cos(angle);
        vertex_buffer_data[cur++] = y+radius1 * sin(angle);
        vertex_buffer_data[cur++] = z-height/2;

        vertex_buffer_data[cur++] = x+radius2 * cos(angle);
        vertex_buffer_data[cur++] = y+radius2 * sin(angle);
        vertex_buffer_data[cur++] = z+height/2;

    };
}

//ellipse with (12 * n)*n
void Airplane::make_ellipse(float x, float y, float z, float radius1, float radius2, float radius3){
    const int n = 20;

    //phi = angle1, theta = angle2
    double angle1 = 0;
    double angle2 = 0;

    const double pi = 4 * atan(1);
    double diff1 = (2 * pi) / (double)n;
    double diff2 = (pi) / (double)n;
    
    for (int i = 0; i < n; i++)
    {
        angle1 = 0;
        for (int j = 0; j < 2*n; j++)
        {
            //first triangle
            vertex_buffer_data[cur++] = x+radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y+radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z+radius3 * cos(angle2);

            angle1 += diff1;
            vertex_buffer_data[cur++] = x+radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y+radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z+radius3 * cos(angle2);

            angle2 += diff2;
            vertex_buffer_data[cur++] = x+radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y+radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z+radius3 * cos(angle2);

            //second triangle
            vertex_buffer_data[cur++] = x+radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y+radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z+radius3 * cos(angle2);

            angle1 -= diff1;
            vertex_buffer_data[cur++] = x+radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y+radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z+radius3 * cos(angle2);

            angle2 -= diff2;
            vertex_buffer_data[cur++] = x+radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y+radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z+radius3 * cos(angle2);

            angle1 += diff1;
        }
        angle2 += diff2;
    }

}

//make wings
void Airplane::make_wings(float x, float y, float z){

    //first right wing
    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.5;
    vertex_buffer_data[cur++]=z;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.5;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x+6;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.5;
    vertex_buffer_data[cur++]=z;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.5;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x+6;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.5;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x+6;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.5;
    vertex_buffer_data[cur++]=z+2;


    //first left wing
    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.5;
    vertex_buffer_data[cur++]=z;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.5;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x-6;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.5;
    vertex_buffer_data[cur++]=z;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.5;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x-6;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.5;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x-6;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+2;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.5;
    vertex_buffer_data[cur++]=z+2;

    //second right wing
    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.25;
    vertex_buffer_data[cur++]=z+4;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.25;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x+4;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.25;
    vertex_buffer_data[cur++]=z+4;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.25;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x+4;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.25;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x+4;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.25;
    vertex_buffer_data[cur++]=z+5;

    //second left wing
    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.25;
    vertex_buffer_data[cur++]=z+4;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.25;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x-4;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.25;
    vertex_buffer_data[cur++]=z+4;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.25;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x-4;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y-0.25;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x-4;
    vertex_buffer_data[cur++]=y;
    vertex_buffer_data[cur++]=z+5;

    vertex_buffer_data[cur++]=x;
    vertex_buffer_data[cur++]=y+0.25;
    vertex_buffer_data[cur++]=z+5;
}

Airplane::Airplane(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    
    this->make_cylinder(0, 0, -2, 1, 1, 6);
    this->make_cylinder(0, 0, -6, 0.1, 1, 2);
    this->make_wings(0,0,-5);
    this->make_ellipse(0, 0, 1, 1, 1, 1);

    this->object = create3DObject(GL_TRIANGLES, 40*24 + 36, vertex_buffer_data, COLOR_SILVER, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 12*20*20, vertex_buffer_data + (40*24 + 36)*3, COLOR_SILVER, GL_FILL);

}



void Airplane::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * rotate2);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
}

void Airplane::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Airplane:: tilt_left(){
    if(this->rotation2 < 60)
        this->rotation2 += 0.5;
}

void Airplane:: tilt_right(){
    if(this->rotation2 > -60)
        this->rotation2 -= 0.5;
}

void Airplane::move_left(){
    this->rotation += 0.25;
    if(this->rotation2 < 60)
        this->rotation2 += 0.5;
}

void Airplane::move_right(){
    this->rotation -= 0.25;
    if(this->rotation2 > -60)
        this->rotation2 -= 0.5;
}

void Airplane::move_forward(){
    this->position.z -= this-> speed * cos(this->rotation * (pi/180) );
    this->position.x -= this-> speed * sin(this->rotation * (pi/180) );
}

void Airplane::move_backward(){
    this->position.z += this-> speed * cos(this->rotation * (pi/180) );
    this->position.x += this-> speed * sin(this->rotation * (pi/180) );
}

void Airplane::move_upward(){
    this->position.y += this-> speed;
}

void Airplane::move_downward(){
    this->position.y -= this-> speed;
}

void Airplane::tick() {
    if (this->rotation2 > 0)
        this->rotation2 -= 0.25;
    else if(this->rotation2 < 0)
        this->rotation2 += 0.25;
}

