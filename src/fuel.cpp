#include "fuel.h"
#include "main.h"
#include <limits.h>


void Fuel::make_cylinder(GLfloat vertex_buffer_data[],float x, float y, float z, float radius1, float radius2, float height){
    const int n = 40;

    double angle = 0;
    const double pi = 4 * atan(1);
    double diff = (2 * pi) / (double)n;
    int cur = 0;

    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = x + 0.0f;
        vertex_buffer_data[cur++] = y + 0.0f;
        vertex_buffer_data[cur++] = z - height/2;

        //Point with lower angle
        vertex_buffer_data[cur++] = x + radius1 * cos(angle);
        vertex_buffer_data[cur++] = y + radius1 * sin(angle);
        vertex_buffer_data[cur++] = z - height/2;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = x + radius1 * cos(angle);
        vertex_buffer_data[cur++] = y + radius1 * sin(angle);
        vertex_buffer_data[cur++] = z - height/2;
    }

    angle = 0;
    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = x + 0.0f;
        vertex_buffer_data[cur++] = y + 0.0f;
        vertex_buffer_data[cur++] = z + height/2;

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

void Fuel::make_ellipse(GLfloat vertex_buffer_data[],float x, float y, float z, float radius1, float radius2, float radius3)
{
    const int n = 20;

    //phi = angle1, theta = angle2
    double angle1 = 0;
    double angle2 = 0;

    const double pi = 4 * atan(1);
    double diff1 = (2 * pi) / (double)n;
    double diff2 = (pi) / (double)n;
    
    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        angle1 = 0;
        for (int j = 0; j < 2*n; j++)
        {
            //first triangle
            vertex_buffer_data[cur++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z + radius3 * cos(angle2);

            angle1 += diff1;
            vertex_buffer_data[cur++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z + radius3 * cos(angle2);

            angle2 += diff2;
            vertex_buffer_data[cur++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z + radius3 * cos(angle2);

            //second triangle
            vertex_buffer_data[cur++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z + radius3 * cos(angle2);

            angle1 -= diff1;
            vertex_buffer_data[cur++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z + radius3 * cos(angle2);

            angle2 -= diff2;
            vertex_buffer_data[cur++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = z + radius3 * cos(angle2);

            angle1 += diff1;
        }
        angle2 += diff2;
    }

}

Fuel::Fuel(float x, float y, float z, color_t color)
{
    // this->position.y += this-> speed;
    this->position = glm::vec3(x, y, z);
    this->rotation = 90;
    this->rotation2 = 0;

    GLfloat vertex_buffer_data[100000];
    GLfloat vertex_buffer_data2[100000];
    GLfloat vertex_buffer_data3[100000];

    this->make_cylinder(vertex_buffer_data, 0, 0, -4, 2, 0.2, 4);
    this->make_cylinder(vertex_buffer_data2, 0 , 0 ,0, 0.2, 2, 4);
    this->make_ellipse(vertex_buffer_data3, 0 , 0 ,-2, 1, 1, 1);
    
    this->object = create3DObject(GL_TRIANGLES,12*40, vertex_buffer_data, COLOR_ENEMY, GL_LINE);
    this->object2 = create3DObject(GL_TRIANGLES,12*40, vertex_buffer_data2, COLOR_ENEMY, GL_LINE);
    this->object3 = create3DObject(GL_TRIANGLES,12*20*20, vertex_buffer_data3, COLOR_ENEMY, GL_LINE);

}

void Fuel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    Matrices.model *= (translate * rotate * rotate2);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Fuel::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Fuel::tick(){
    this->rotation2 += 1;
}

bounding_box_t Fuel::bounding_box() {
    bounding_box_t bbox = {this->position.x, this->position.y+2, this->position.z, 4, 8, 4};
    return bbox;
}


