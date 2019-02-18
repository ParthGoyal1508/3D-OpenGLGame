#include "rings.h"
#include "main.h"

Rings::Rings(float x, float y, float z, float radius1, float radius2, color_t color) {

    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    const int n = 40;

    GLfloat vertex_buffer_data[100000];

    double angle = 0;
    const double pi = 4 * atan(1);
    double diff = (2 * pi) / (double)n;
    int cur = 0;

    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = radius1 * sin(angle);
        vertex_buffer_data[cur++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = radius2 * sin(angle);
        vertex_buffer_data[cur++] = 0.0f;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = radius1 * sin(angle);
        vertex_buffer_data[cur++] = 0.0f;

        //Point with lower angle
        angle -= diff;
        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = radius2 * sin(angle);
        vertex_buffer_data[cur++] = 0.0f;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = radius1 * sin(angle);
        vertex_buffer_data[cur++] = 0.0f;

        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = radius2 * sin(angle);
        vertex_buffer_data[cur++] = 0.0f;

    }

    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = radius1 * sin(angle);
        vertex_buffer_data[cur++] = 1.0f;

        //Point with lower angle
        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = radius2 * sin(angle);
        vertex_buffer_data[cur++] = 1.0f;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = radius1 * sin(angle);
        vertex_buffer_data[cur++] = 1.0f;

        //Point with lower angle
        angle -= diff;
        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = radius2 * sin(angle);
        vertex_buffer_data[cur++] = 1.0f;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius1 * cos(angle);
        vertex_buffer_data[cur++] = radius1 * sin(angle);
        vertex_buffer_data[cur++] = 1.0f;

        vertex_buffer_data[cur++] = radius2 * cos(angle);
        vertex_buffer_data[cur++] = radius2 * sin(angle);
        vertex_buffer_data[cur++] = 1.0f;

    }


    this->object = create3DObject(GL_TRIANGLES, n*12, vertex_buffer_data, color, GL_FILL);
}

void Rings::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Rings::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Rings::tick() {
    this->rotation += 1;
}

