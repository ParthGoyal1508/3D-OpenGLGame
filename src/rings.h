#include "main.h"

#ifndef RINGS_H
#define RINGS_H


class Rings {
public:
    Rings() {}
    Rings(float x, float y, float z, float radius1, float radius2, color_t color);
    glm::vec3 position;
    glm::vec3 start;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    void set_position(float x, float y, float z);
    int active=1;
    bounding_box_t bounding_box();

  private:
    VAO *object;
    VAO *object1;
};

#endif // RINGS_H
