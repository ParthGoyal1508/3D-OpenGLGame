#include "main.h"

#ifndef Navigation_H
#define Navigation_H


class Navigation {
public:
    Navigation() {}
    Navigation(float x, float y, float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    float rotation;
    float rotation2;
    float rotation3;
    int checkpoint=0;
    void tick();
private:
    VAO *object;
};

#endif // Navigation_H
