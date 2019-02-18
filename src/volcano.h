#include "main.h"

#ifndef Volcano_H
#define Volcano_H


class Volcano {
public:
    Volcano() {}
    Volcano(float x, float y, float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    float rotation;
    int ischeckpoint=0;
    int checkpointcomplete=0;
    void make_ellipse(float x, float y, float z,float radius1, float radius2, float radius3);
    void make_cuboid(GLfloat vertex_buffer_data[], float x, float y, float z);
    void make_sphere(float x, float y, float z, float radius);
    void make_frustum(GLfloat vertex_buffer_data[], float x, float y, float z, float radius1, float radius2, float height);
    void tick();
    bounding_box_t bounding_box();

private:
    VAO *object;
    VAO *object2;
};

#endif // Volcano_H
