#include "water.h"
#include "main.h"
#include <limits.h>

Water::Water(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    GLfloat vertex_buffer_data[1000000] = {};
    int cur=0;
    int inc = 60;
    for(int i = -3000; i<=3000; i+=inc){
        for(int j=-3000; j<=3000; j+=inc){
            vertex_buffer_data[cur++] = j;
            vertex_buffer_data[cur++] = 0;
            vertex_buffer_data[cur++] = i;

            vertex_buffer_data[cur++] = j;
            vertex_buffer_data[cur++] = 0;
            vertex_buffer_data[cur++] = i+inc;

            vertex_buffer_data[cur++] = j+inc;
            vertex_buffer_data[cur++] = 0;
            vertex_buffer_data[cur++] = i;
        }
    }
    

    GLfloat vertex_buffer_data2[1000000] = {};
    cur=0;
    for(int i = -3000; i<=3000; i+=inc){
        for(int j=-3000; j<=3000; j+=inc){
            vertex_buffer_data2[cur++] = j+inc;
            vertex_buffer_data2[cur++] = 0;
            vertex_buffer_data2[cur++] = i;

            vertex_buffer_data2[cur++] = j;
            vertex_buffer_data2[cur++] = 0;
            vertex_buffer_data2[cur++] = i+inc;

            vertex_buffer_data2[cur++] = j+inc;
            vertex_buffer_data2[cur++] = 0;
            vertex_buffer_data2[cur++] = i+inc;
        }
    }

    this->object = create3DObject(GL_TRIANGLES,3*100*100, vertex_buffer_data, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,3*100*100, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
}

void Water::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
}

void Water::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}


