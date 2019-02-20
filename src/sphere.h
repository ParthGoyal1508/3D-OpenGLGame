#include "main.h"

#ifndef SPHERE_H
#define SPHERE_H


class Sphere {
public:
    Sphere() {}
    Sphere(float x, float y, float z, float radius, color_t color);
    glm::vec3 position;
    glm::vec3 start;
    void draw(glm::mat4 VP);
    void tick();
    void set_position(float x, float y, float z);
    float size;
    float rotation;
    float radius;
    float r_angle;
    bounding_box_t bounding_box();

  private:
    VAO *object;
};

#endif // SPHERE_H
