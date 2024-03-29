#include "main.h"

#ifndef Island_H
#define Island_H


class Island {
public:
    Island() {}
    Island(float x, float y, float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    float rotation;
    int ischeckpoint=0;
    int checkpointcomplete=0;
    void make_ellipse(float x, float y, float z,float radius1, float radius2, float radius3);
    void make_cuboid(float x, float y, float z);
    void make_sphere(float x, float y, float z, float radius);
    void tick();
    float radius1, radius2, radius3;
    bounding_box_t bounding_box();

private:
    VAO *object;
    VAO *object2;
    VAO *object3;
    VAO *object4;

};

#endif // Island_H
