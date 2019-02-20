#include "compass.h"
#include "main.h"

Compass::Compass(float x, float y, float z, float radius, color_t color) {
    float height =0.1;
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
        vertex_buffer_data[cur++] = 0.0f;
        vertex_buffer_data[cur++] = 0.0f;
        vertex_buffer_data[cur++] = -height/2;

        //Point with lower angle
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = -height/2;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = -height/2;
    }

    angle = 0;
    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data[cur++] = 0.0f;
        vertex_buffer_data[cur++] = 0.0f;
        vertex_buffer_data[cur++] = height/2;

        //Point with lower angle
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = height/2;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = height/2;
    }

    angle = 0;
    for (int i=0; i < n; i++){
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = -height/2;

        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = height/2;

        angle+=diff;
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = -height/2;

        angle-=diff;
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = height/2;

        angle+=diff;
        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = -height/2;

        vertex_buffer_data[cur++] = radius * cos(angle);
        vertex_buffer_data[cur++] = radius * sin(angle);
        vertex_buffer_data[cur++] = +height/2;

    };

    GLfloat vertex_buffer_data2[100000];
    cur =0;
    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data2[cur++] = 0.0f;
        vertex_buffer_data2[cur++] = 0.0f;
        vertex_buffer_data2[cur++] = height/2+0.01;

        //Point with lower angle
        vertex_buffer_data2[cur++] = 0.4 * cos(angle);
        vertex_buffer_data2[cur++] = 0.4 * sin(angle);
        vertex_buffer_data2[cur++] = height/2+0.01;

        //Point with higher angle
        angle += diff;
        vertex_buffer_data2[cur++] = 0.4 * cos(angle);
        vertex_buffer_data2[cur++] = 0.4 * sin(angle);
        vertex_buffer_data2[cur++] = height/2+0.01;
    }

    GLfloat vertex_buffer_data3[100000];
    cur =0;

    vertex_buffer_data3[cur++]=-0.2f;
    vertex_buffer_data3[cur++]=0.0f;
    vertex_buffer_data3[cur++]=0.505f;

    vertex_buffer_data3[cur++]=0.4f;
    vertex_buffer_data3[cur++]=0.0f;
    vertex_buffer_data3[cur++]=0.505f;

    vertex_buffer_data3[cur++]=0.1f;
    vertex_buffer_data3[cur++]=1.5f;
    vertex_buffer_data3[cur++]=0.505f;


    this->object = create3DObject(GL_TRIANGLES, n*12, vertex_buffer_data, COLOR_DARKBLACK, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, n*3, vertex_buffer_data2, COLOR_BLUE, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data3, COLOR_RED, GL_FILL);
}

void Compass::draw(glm::mat4 VP, int view) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation * (-1) * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 rotate3   = glm::rotate((float) (this->rotation2 * (-1) * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * rotate2 * rotate3);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(view == 1 || view == 2 || view == 3 ){
        draw3DObject(this->object);
        draw3DObject(this->object3);
    }
    
    // draw3DObject(this->object2);
}

void Compass::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Compass::tick() {
    this->rotation += 1;
}

