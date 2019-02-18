#include "volcano.h"
#include "main.h"
#include <limits.h>

void Volcano::make_cuboid(GLfloat vertex_buffer_data[], float x, float y, float z){
    float l=150,b=150,h=3;
    int cur =0;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;
    
    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;
    
    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;
    
    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;
    
    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z-b/2;
    
    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y-h/2;
    vertex_buffer_data[cur++]=z+b/2;


    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;

    vertex_buffer_data[cur++]=x-l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z+b/2;

    vertex_buffer_data[cur++]=x+l/2;
    vertex_buffer_data[cur++]=y+h/2;
    vertex_buffer_data[cur++]=z-b/2;

}

void Volcano::make_frustum(GLfloat vertex_buffer_data[], float x, float y, float z, float radius1, float radius2, float height){
    
    const int n = 40;

    double angle = 0;
    const double pi = 4 * atan(1);
    double diff = (2 * pi) / (double)n;
    int cur = 0;
    
    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = 0.0f;
        vertex_buffer_data[cur++] = -height/2;
        vertex_buffer_data[cur++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = -height/2;
        vertex_buffer_data[cur++] = radius1 * sin(angle);


        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = -height/2;
        vertex_buffer_data[cur++] = radius1 * sin(angle);
    }

    angle = 0;
    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = 0.0f;
        vertex_buffer_data[cur++] = height/2;
        vertex_buffer_data[cur++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = height/2;
        vertex_buffer_data[cur++] = radius2 * sin(angle);

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = height/2;
        vertex_buffer_data[cur++] = radius2 * sin(angle);
    }

    angle = 0;
    for (int i=0; i < n; i++){
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = -height/2;
        vertex_buffer_data[cur++] = radius1 * sin(angle);

        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = height/2;
        vertex_buffer_data[cur++] = radius2 * sin(angle);

        angle+=diff;
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = -height/2;
        vertex_buffer_data[cur++] = radius1 * sin(angle);

        angle-=diff;
        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = height/2;
        vertex_buffer_data[cur++] = radius2 * sin(angle);

        angle+=diff;
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = -height/2;
        vertex_buffer_data[cur++] = radius1 * sin(angle);

        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = +height/2;
        vertex_buffer_data[cur++] = radius2 * sin(angle);

    };
}

Volcano::Volcano(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    GLfloat vertex_buffer_data[100000];
    GLfloat vertex_buffer_data1[100000];

    this->make_cuboid(vertex_buffer_data,0,0,0);
    this->make_frustum(vertex_buffer_data1,40,10,0,100,25,125);
    
    this->object = create3DObject(GL_TRIANGLES,36, vertex_buffer_data,color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,12*40, vertex_buffer_data1,color, GL_FILL);

}

void Volcano::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // glm::mat4 rotate3    = glm::rotate((float) (this->rotation3 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
}

void Volcano::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Volcano::tick(){
    this->rotation += 1;
}

bounding_box_t Volcano::bounding_box() {
    bounding_box_t bbox = {this->position.x, this->position.y, this->position.z, 150, 9, 150};
    return bbox;
}

