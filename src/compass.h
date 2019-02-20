#include "main.h"

#ifndef COMPASS_H
#define COMPASS_H

class Compass
{
  public:
    Compass() {}
    Compass(float x, float y, float z, float radius, color_t color);
    glm::vec3 position;
    float rotation;
    float rotation2;
    void draw(glm::mat4 VP, int view);
    void set_position(float x, float y, float z);
    void tick();
    double speed;

  private:
    VAO *object;
    VAO *object2;
    VAO *object3;
};

#endif // COMPASS_H
