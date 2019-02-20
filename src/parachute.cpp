#include "parachute.h"
#include "main.h"

void Parachute::make_cuboid(GLfloat vertex_buffer_data3[], float x, float y, float z){
    float l=5,b=5,h=5;
    int cur3=0;

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

Parachute::Parachute(float x, float y, float z, float radius1, float radius2, float radius3, color_t color) {

    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    GLfloat vertex_buffer_data[100000];

    const int n = 40;

    //phi = angle1, theta = angle2
    double angle1 = 0;
    double angle2 = 0;

    const double pi = 4 * atan(1);
    double diff1 = (2 * pi) / (double)n;
    double diff2 = (pi/2) / (double)n;
    
    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        angle1 = 0;
        for (int j = 0; j < 2*n; j++)
        {
            //first triangle
            vertex_buffer_data[cur++] = radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius3 * cos(angle2);
            vertex_buffer_data[cur++] = radius2 * sin(angle1) * sin(angle2);

            angle1 += diff1;
            vertex_buffer_data[cur++] = radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius3 * cos(angle2);
            vertex_buffer_data[cur++] = radius2 * sin(angle1) * sin(angle2);

            angle2 += diff2;
            vertex_buffer_data[cur++] = radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius3 * cos(angle2);
            vertex_buffer_data[cur++] = radius2 * sin(angle1) * sin(angle2);

            //second triangle
            vertex_buffer_data[cur++] = radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius3 * cos(angle2);
            vertex_buffer_data[cur++] = radius2 * sin(angle1) * sin(angle2);

            angle1 -= diff1;
            vertex_buffer_data[cur++] = radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius3 * cos(angle2);
            vertex_buffer_data[cur++] = radius2 * sin(angle1) * sin(angle2);

            angle2 -= diff2;
            vertex_buffer_data[cur++] = radius1 * cos(angle1) * sin(angle2);
            vertex_buffer_data[cur++] = radius3 * cos(angle2);
            vertex_buffer_data[cur++] = radius2 * sin(angle1) * sin(angle2);

            angle1 += diff1;
        }
        angle2 += diff2;
    }

    GLfloat vertex_buffer_data2[100000];
    cur=0;
    float angle = 0;
    double diff = (2 * pi) / (double)n;

    for (int i = 0; i < n; i++){
        //Origin
        vertex_buffer_data2[cur++] = 0.0f;
        vertex_buffer_data2[cur++] = 0.0f;
        vertex_buffer_data2[cur++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data2[cur++] = radius1 * cos(angle);
        vertex_buffer_data2[cur++] = 0.0f;
        vertex_buffer_data2[cur++] = radius1 * sin(angle);

        //Point with higher angle
        angle += diff;
        vertex_buffer_data2[cur++] = radius1 * cos(angle);
        vertex_buffer_data2[cur++] = 0.0f;
        vertex_buffer_data2[cur++] = radius1 * sin(angle);
    }

    GLfloat vertex_buffer_data3[100000];
    this->make_cuboid(vertex_buffer_data3, 0,-10,0);

    GLfloat vertex_buffer_data4[100000];
    cur =0;
    
    angle = 45* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    angle += 9* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    vertex_buffer_data4[cur++]=2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=2.5;

    vertex_buffer_data4[cur++]=2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=2.5;

    vertex_buffer_data4[cur++]=2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=2.0;

    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    angle = 135* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    angle += 9* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    vertex_buffer_data4[cur++]=-2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=2.5;

    vertex_buffer_data4[cur++]=-2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=2.5;

    vertex_buffer_data4[cur++]=-2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=2.0;

    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    angle = 225* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    angle += 9* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    vertex_buffer_data4[cur++]=-2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=-2.5;

    vertex_buffer_data4[cur++]=-2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=-2.5;

    vertex_buffer_data4[cur++]=-2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=-2.0;

    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    angle = 315* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    angle += 9* (pi/180);
    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);

    vertex_buffer_data4[cur++]=2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=-2.5;

    vertex_buffer_data4[cur++]=2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=-2.5;

    vertex_buffer_data4[cur++]=2.5;
    vertex_buffer_data4[cur++]=-7.5;
    vertex_buffer_data4[cur++]=-2.0;

    vertex_buffer_data4[cur++]=radius1*cos(angle);
    vertex_buffer_data4[cur++]=0.0f;
    vertex_buffer_data4[cur++]=radius1*sin(angle);




    
    this->object = create3DObject(GL_TRIANGLES, 12 * n * n, vertex_buffer_data, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3 * n, vertex_buffer_data2, COLOR_GREEN, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 3 * 10, vertex_buffer_data3, COLOR_GREEN, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 24 , vertex_buffer_data4, COLOR_RED, GL_FILL);
}

void Parachute::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}

void Parachute::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Parachute::tick() {
    if(this->active == 1)
        this->rotation += 1;
}

bounding_box_t Parachute::bounding_box() {
    bounding_box_t bbox = {this->position.x, this->position.y-10, this->position.z, 5,5,5};
    return bbox;
}


