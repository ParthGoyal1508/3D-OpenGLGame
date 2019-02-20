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
    float rotation2 = 0;
    void seven_segment(GLfloat vertex_buffer_data[], int f1, int f2, int f3, int f4, int f5, int f6, int f7, float x, float y, float z, int digit);
    void draw(glm::mat4 VP, int view);
    void set_position(float x, float y, float z);
    void print_speed(int speed, int alt, int fuel);
  private:
    VAO *object[21];
};

#endif // DASHBOARD_H
