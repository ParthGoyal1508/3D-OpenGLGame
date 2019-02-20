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
    float rotation3 = 0;
    float rotation4 = 0;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
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
    void speed_increase();
    void speed_decrease();
    int speed_decreaseflag=1;
    int score = 0;
    double speed = 0;
    float alt = 0;
    float fuel = 100;
    bounding_box_t bounding_box();

  private:
    VAO *object;
    VAO *object2;
};

#endif // AIRPLANE_H
