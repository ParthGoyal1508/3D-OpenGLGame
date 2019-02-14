#include "dashboard.h"
#include "main.h"

using namespace std;

GLfloat vertex_buffer_data1[100000];
int cur1 = 0;

void Dashboard::seven_segment(int f1, int f2, int f3, int f4, int f5, int f6, int f7, float x, float y, float z){

    float width = 0.7;
    float l = x;
    float r = x + width;
    float d = y;
    float width2 =0.2;

    if(f4 == 1){
        //point 1
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;
        //point 2
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 3
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;
        //point 4
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 5
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;
        //point 6
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width2;
        vertex_buffer_data1[cur1++]=z;
    } 

    if(f7 == 1){
        //point 1
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
        //point 2
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 3
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
        //point 4
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 5
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
        //point 6
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width+width2;
        vertex_buffer_data1[cur1++]=z;
    } 

    if(f1 == 1){
        //point 1
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
        //point 2
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 3
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
        //point 4
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 5
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
        //point 6
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width+width2;
        vertex_buffer_data1[cur1++]=z;
    } 

    if(f5 == 1){
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
    }

    if(f3 == 1){
        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
    }

    if(f6 == 1){
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
    }

    if(f2 == 1){
       vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
    }
}


Dashboard::Dashboard(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    x+=10;
    y+=10;
    
    vertex_buffer_data1[cur1++] = x-1;
    vertex_buffer_data1[cur1++] = y-6;
    vertex_buffer_data1[cur1++] = z-25;

    vertex_buffer_data1[cur1++] = x+15;
    vertex_buffer_data1[cur1++] = y-6;
    vertex_buffer_data1[cur1++] = z-25;

    vertex_buffer_data1[cur1++] = x-1;
    vertex_buffer_data1[cur1++] = y+6;
    vertex_buffer_data1[cur1++] = z-25;

    vertex_buffer_data1[cur1++] = x-1;
    vertex_buffer_data1[cur1++] = y+6;
    vertex_buffer_data1[cur1++] = z-25;

    vertex_buffer_data1[cur1++] = x+15;
    vertex_buffer_data1[cur1++] = y-6;
    vertex_buffer_data1[cur1++] = z-25;

    vertex_buffer_data1[cur1++] = x+15;
    vertex_buffer_data1[cur1++] = y+6;
    vertex_buffer_data1[cur1++] = z-25;


    //speed 
    this->seven_segment(1,0,1,1,0,1,1,x,y,z-20);
    this->seven_segment(1,1,0,0,1,1,1,x+1.3,y,z-20);
    this->seven_segment(1,0,0,1,1,1,1,x+1.3*2,y,z-20);
    this->seven_segment(1,0,0,1,1,1,1,x+1.3*3,y,z-20);
    this->seven_segment(0,1,1,1,1,0,1,x+1.3*4,y,z-20);

    //alt
    this->seven_segment(1,1,1,0,1,1,1,x,y-3,z-20);
    this->seven_segment(0,0,0,1,1,1,0,x+1.3,y-3,z-20);
    this->seven_segment(0,0,0,1,1,1,1,x+1.3*2,y-3,z-20);

    //fuel
    this->seven_segment(1,0,0,0,1,1,1,x,y-6,z-20);
    this->seven_segment(0,1,1,1,1,1,0,x+1.3,y-6,z-20);
    this->seven_segment(1,0,0,1,1,1,1,x+1.3*2,y-6,z-20);
    this->seven_segment(0,0,0,1,1,1,0,x+1.3*3,y-6,z-20);

    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data1, COLOR_GREEN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 42*12, vertex_buffer_data1 + (6)*3, COLOR_DASHBOARD, GL_FILL);

}



void Dashboard::draw(glm::mat4 VP, int view) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(view == 1 || view == 2 || view == 3){
        // draw3DObject(this->object);
        draw3DObject(this->object2);
    }
}

void Dashboard::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}


