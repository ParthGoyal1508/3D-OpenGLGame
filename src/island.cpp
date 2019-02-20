#include "island.h"
#include "main.h"
#include <limits.h>

GLfloat vertex_buffer_data2[1000000] = {};
GLfloat vertex_buffer_data3[1000000] = {};
GLfloat vertex_buffer_data4[1000000] = {};
int cur2 =0;
int cur3 =0;
int cur4 =0;

//36*n*n
void Island::make_ellipse(float x ,float y ,float z ,float radius1, float radius2, float radius3){
    const int n = 40;

    this->radius1 = radius1;
    this->radius2 = radius2;
    this->radius3 = radius3;

    //phi = angle1, theta = angle2
    double angle1 = 0;
    double angle2 = 0;

    const double pi = 4 * atan(1);
    double diff1 = (2 * pi) / (double)n;
    double diff2 = (pi) / (double)n;
    
    int cur2 = 0;

    for (int i = 0; i < n; i++)
    {
        angle1 = 0;
        for (int j = 0; j < 2*n; j++)
        {
            //first triangle
            vertex_buffer_data2[cur2++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = z + radius3 * cos(angle2);

            angle1 += diff1;
            vertex_buffer_data2[cur2++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = z + radius3 * cos(angle2);

            angle2 += diff2;
            vertex_buffer_data2[cur2++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = z + radius3 * cos(angle2);

            //second triangle
            vertex_buffer_data2[cur2++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = z + radius3 * cos(angle2);

            angle1 -= diff1;
            vertex_buffer_data2[cur2++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = z + radius3 * cos(angle2);

            angle2 -= diff2;
            vertex_buffer_data2[cur2++] = x + radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = y + radius2 * sin(angle1) * sin(angle2);
            vertex_buffer_data2[cur2++] = z + radius3 * cos(angle2);

            angle1 += diff1;
        }
        angle2 += diff2;
    }
}

void Island::make_cuboid(float x, float y, float z){
    float l=10,b=10,h=20;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;
    
    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;
    
    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;
    
    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;
    
    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z-b/2;
    
    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y-h/2;
    vertex_buffer_data3[cur3++]=z+b/2;


    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

    vertex_buffer_data3[cur3++]=x-l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z+b/2;

    vertex_buffer_data3[cur3++]=x+l/2;
    vertex_buffer_data3[cur3++]=y+h/2;
    vertex_buffer_data3[cur3++]=z-b/2;

}

void Island::make_sphere(float x, float y, float z, float radius){
    
    const int n = 10;
     
    //phi = angle1, theta = angle2
    double angle1 = 0;
    double angle2 = 0;

    const double pi = 4 * atan(1);
    double diff1 = (2 * pi) / (double)n;
    double diff2 = (pi) / (double)n;
    
    int cur = 0;

    for (int i = 0; i < n ; i++)
    {
        angle1 = 0;
        for (int j = 0; j < 2*n; j++)
        {
            //Origin
            vertex_buffer_data4[cur4++] = x + 0.0f;
            vertex_buffer_data4[cur4++] = y + 0.0f;
            vertex_buffer_data4[cur4++] = z + 0.0f;

            //Point with lower angle
            vertex_buffer_data4[cur4++] = x + radius * cos(angle1) * sin(angle2);
            vertex_buffer_data4[cur4++] = y + radius * sin(angle1) * sin(angle2);
            vertex_buffer_data4[cur4++] = z + radius * cos(angle2);

            //Point with higher angle
            angle1 += diff1;
            vertex_buffer_data4[cur4++] = x + radius * cos(angle1) * sin(angle2);
            vertex_buffer_data4[cur4++] = y + radius * sin(angle1) * sin(angle2);
            vertex_buffer_data4[cur4++] = z + radius * cos(angle2);
        }
        angle2 += diff2;
    }
}




Island::Island(float x, float y, float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    this->make_ellipse(0,0,0,80,80,80);
    this->make_cuboid(0,75,0);
    this->make_sphere(0,90,0,5);

    this->object = create3DObject(GL_TRIANGLES,6*40*80, vertex_buffer_data2, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,10 * 3, vertex_buffer_data3, COLOR_ENEMY, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES,6*10*10, vertex_buffer_data4, COLOR_DASHBOARD, GL_LINE);
    this->object4 = create3DObject(GL_TRIANGLES,6*10*10, vertex_buffer_data4, COLOR_BLUE, GL_LINE);

}

void Island::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(this->checkpointcomplete == 0 && this->ischeckpoint == 0)
    {
        draw3DObject(this->object3);
    }
    if(this->checkpointcomplete == 0 && this->ischeckpoint == 1){
         draw3DObject(this->object4);
    }
    draw3DObject(this->object);
    draw3DObject(this->object2);
    
}

void Island::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Island::tick(){
    this->rotation += 1;
}

bounding_box_t Island::bounding_box() {
    bounding_box_t bbox = {this->position.x, this->position.y+this->radius2+10, this->position.z, 5, 5, 5};
    return bbox;
}

