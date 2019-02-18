#include "main.h"

#ifndef Fuel_H
#define Fuel_H


class Fuel {
public:
    Fuel() {}
    Fuel(float x, float y, float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void make_cylinder(GLfloat vertex_buffer_data[], float x, float y, float z, float radius1, float radius2, float height);
    void make_ellipse(GLfloat vertex_buffer_data[], float x, float y, float z, float radius1, float radius2, float radius3);
    float rotation;
    float rotation2;
    void tick();
    bounding_box_t bounding_box();
private:
    VAO *object;
    VAO *object2;
    VAO *object3;
};

#endif // Navigation_H
