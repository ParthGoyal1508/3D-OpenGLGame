#include "main.h"

#ifndef DASHBOARD_H
#define DASHBOARD_H

class Dashboard
{
  public:
    Dashboard() {}
    Dashboard (float x, float y, float z);
    glm::vec3 position;
    float rotation = 0;
    void seven_segment(int f1, int f2, int f3, int f4, int f5, int f6, int f7, float x, float y, float z);
    void draw(glm::mat4 VP, int view);
    void set_position(float x, float y, float z);
  private:
    VAO *object;
    VAO *object2;
};

#endif // DASHBOARD_H
