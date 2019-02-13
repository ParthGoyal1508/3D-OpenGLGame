#include "main.h"

#ifndef ELLIPSE_H
#define ELLIPSE_H


class Ellipse {
public:
    Ellipse() {}
    Ellipse(float x, float y, float z, float radius1, float radius2, float radius3, color_t color);
    glm::vec3 position;
    glm::vec3 start;
    void draw(glm::mat4 VP);
    void tick();
    void set_position(float x, float y, float z);
    float size;
    float rotation;
    float radius;
    float r_angle;
    // bounding_box_t bounding_box();

  private:
    VAO *object;
};

#endif // ELLIPSE_H
