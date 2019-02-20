#include "sphere.h"
#include "main.h"
#include "math.h"

Sphere::Sphere(float x, float y, float z, float radius, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->radius = radius;
    this->rotation = 0;

    const int n = 20;
    const int reqd = n * 100;
    GLfloat vertex_buffer_data[1000000] = {};

    //phi = angle1, theta = angle2
    double angle1 = 0;
    double angle2 = 0;

    const double pi = 4 * atan(1);
    double diff1 = (2 * pi) / (double)n;
    double diff2 = (pi) / (double)n;
    
    int cur = 0;

    for (int i = 0; i < n ; i++)
    {
        angle1 = 0;
        for (int j = 0; j < 2*n; j++)
        {
            //Origin
            vertex_buffer_data[cur++] = 0.0f;
            vertex_buffer_data[cur++] = 0.0f;
            vertex_buffer_data[cur++] = 0.0f;

            //Point with lower angle
            vertex_buffer_data[cur++] = radius * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius * cos(angle2);

            //Point with higher angle
            angle1 += diff1;
            vertex_buffer_data[cur++] = radius * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius * sin(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius * cos(angle2);
        }
        angle2 += diff2;
    }
    this->object = create3DObject(GL_TRIANGLES, (3 * 2* n) * n , vertex_buffer_data, color, GL_FILL);

}

void Sphere::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));;
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Sphere::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Sphere::tick() {
    const double pi = 4 * atan(1);
    double distraction = this->radius * sin(r_angle * pi / 180) + this->radius * cos(r_angle * pi / 180); 
    this->r_angle += 0.5;
    this->position.x = this->start.x + distraction;
    this->position.z = this->start.z + distraction;
}

bounding_box_t Sphere::bounding_box()
{
    bounding_box_t bbox = {this->position.x, this->position.y, this->position.z, this->radius * 2, this->radius * 2, this->radius * 2};
    return bbox;
}
