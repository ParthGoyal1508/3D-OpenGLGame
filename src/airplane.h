#include "main.h"

#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airplane
{
  public:
    Airplane() {}
    Airplane(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation = 0;
    float rotation2 = 0;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed = 3.00;
    void make_cylinder(float x, float y, float z, float radius1, float radius2, float height);
    void make_ellipse(float x, float y, float z, float radius1, float radius2, float radius3);
    void make_wings(float x, float y, float z);
    void tilt_left();
    void tilt_right();
    void move_left();
    void move_right();
    void move_forward();
    void move_backward();
    void move_upward();
    void move_downward();
  private:
    VAO *object;
    VAO *object2;
};

#endif // AIRPLANE_H
