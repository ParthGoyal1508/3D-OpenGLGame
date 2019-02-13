#include "navigation.h"
#include "main.h"
#include <limits.h>


Navigation::Navigation(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->rotation2 = 0;
    this->rotation3 = 00;

    GLfloat vertex_buffer_data[] = {
        0.85f, 0.0f, 0.0f,
        -0.85f, 0.0f, 0.0f,
        0.0f, 0.0f, -2.0f,
        1.0f, 0.0f, -0.5f,
        -1.0f, 0.0f, -0.5f,
        0.0f, 0.0f, -2.5f,
    };
    
    this->object = create3DObject(GL_TRIANGLES,6, vertex_buffer_data, COLOR_ENEMY, GL_FILL);

}

void Navigation::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 rotate3    = glm::rotate((float) (this->rotation3 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    Matrices.model *= (translate * rotate );
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Navigation::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Navigation::tick(){
    this->rotation2 += 1;
}

