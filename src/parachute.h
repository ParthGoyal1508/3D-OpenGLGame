#include "main.h"

#ifndef PARACHUTE_H
#define PARACHUTE_H


class Parachute {
public:
    Parachute() {}
    Parachute(float x, float y, float z, float radius1, float radius2, float radius3, color_t color);
    glm::vec3 position;
    glm::vec3 start;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    void set_position(float x, float y, float z);
    void make_cuboid(GLfloat vertex_buffer_data[], float x, float y, float z);
    int active=1;
    bounding_box_t bounding_box();

  private:
    VAO *object;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif // PARACHUTE_H
