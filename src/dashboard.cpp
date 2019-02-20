#include "dashboard.h"
#include "main.h"

using namespace std;

// GLfloat vertex_buffer_data1[200000];
// int cur1 = 0;

void Dashboard::seven_segment(GLfloat vertex_buffer_data1[], int f1, int f2, int f3, int f4, int f5, int f6, int f7, float x, float y, float z, int digit){

    float width = 0.7;
    float l = x;
    float r = x + width;
    float d = y;
    float width2 =0.2;

    int cur1=0;

    if(digit == 1){
        f1=0;f2=1;f3=1;f4=0;f5=0;f6=0;f7=0;
    }
    if(digit == 2){
        f1=1;f2=1;f3=0;f4=1;f5=1;f6=0;f7=1;
    }
    if(digit == 3){
        f1=1;f2=1;f3=1;f4=1;f5=0;f6=0;f7=1;
    }
    if(digit == 4){
        f1=0;f2=1;f3=1;f4=0;f5=0;f6=1;f7=1;
    }
    if(digit == 5){
        f1=1;f2=0;f3=1;f4=1;f5=0;f6=1;f7=1;
    }
    if(digit == 6){
        f1=1;f2=0;f3=1;f4=1;f5=1;f6=1;f7=1;
    }
    if(digit == 7){
        f1=1;f2=1;f3=1;f4=0;f5=0;f6=0;f7=1;
    }
    if(digit == 8){
        f1=1;f2=1;f3=1;f4=1;f5=1;f6=1;f7=1;
    }
    if(digit == 9){
        f1=1;f2=1;f3=1;f4=1;f5=0;f6=1;f7=1;
    }
    if(digit == 0){
        f1=1;f2=1;f3=1;f4=1;f5=1;f6=1;f7=0;
    }

    if(f4 == 1){
        //point 1
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;
        //point 2
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 3
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;
        //point 4
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 5
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;
        //point 6
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width2;
        vertex_buffer_data1[cur1++]=z;
    } 

    if(f7 == 1){
        //point 1
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
        //point 2
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 3
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
        //point 4
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 5
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
        //point 6
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width+width2;
        vertex_buffer_data1[cur1++]=z;
    } 

    if(f1 == 1){
        //point 1
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
        //point 2
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 3
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
        //point 4
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width+width2;
        vertex_buffer_data1[cur1++]=z;
        //point 5
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
        //point 6
        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width+width2;
        vertex_buffer_data1[cur1++]=z;
    } 

    if(f5 == 1){
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
    }

    if(f3 == 1){
        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;
    }

    if(f6 == 1){
        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=l+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
    }

    if(f2 == 1){
       vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r;
        vertex_buffer_data1[cur1++]=d+width;
        vertex_buffer_data1[cur1++]=z;

        vertex_buffer_data1[cur1++]=r+width2;
        vertex_buffer_data1[cur1++]=d+2*width;
        vertex_buffer_data1[cur1++]=z;
    }
}


Dashboard::Dashboard(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    x+=10;
    y+=10;

    
    //speed 

    GLfloat vertex_buffer_data1[200];
    this->seven_segment(vertex_buffer_data1,1,0,1,1,0,1,1,x,y,z-20,11);
    this->object[0] = create3DObject(GL_TRIANGLES, 5*6, vertex_buffer_data1, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data2[200];
    this->seven_segment(vertex_buffer_data2,1,1,0,0,1,1,1,x+1.3,y,z-20,11);
    this->object[1] = create3DObject(GL_TRIANGLES, 5*6, vertex_buffer_data2, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data3[200];
    this->seven_segment(vertex_buffer_data3,1,0,0,1,1,1,1,x+1.3*2,y,z-20,11);
    this->object[2] = create3DObject(GL_TRIANGLES, 5*6, vertex_buffer_data3, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data4[200];
    this->seven_segment(vertex_buffer_data4,1,0,0,1,1,1,1,x+1.3*3,y,z-20,11);
    this->object[3] = create3DObject(GL_TRIANGLES, 5*6, vertex_buffer_data4, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data5[200];
    this->seven_segment(vertex_buffer_data5,0,1,1,1,1,0,1,x+1.3*4,y,z-20,11);
    this->object[4] = create3DObject(GL_TRIANGLES, 5*6, vertex_buffer_data5, COLOR_DASHBOARD, GL_FILL);

    //alt

    GLfloat vertex_buffer_data6[200];
    this->seven_segment(vertex_buffer_data6,1,1,1,0,1,1,1,x,y-3,z-20,11);
    this->object[5] = create3DObject(GL_TRIANGLES, 6*6, vertex_buffer_data6, COLOR_DASHBOARD, GL_FILL);
    

    GLfloat vertex_buffer_data7[200];
    this->seven_segment(vertex_buffer_data7,0,0,0,1,1,1,0,x+1.3,y-3,z-20,11);
    this->object[6] = create3DObject(GL_TRIANGLES, 3*6, vertex_buffer_data7, COLOR_DASHBOARD, GL_FILL);
    

    GLfloat vertex_buffer_data8[200];
    this->seven_segment(vertex_buffer_data8,0,0,0,1,1,1,1,x+1.3*2,y-3,z-20,11);
    this->object[7] = create3DObject(GL_TRIANGLES, 4*6, vertex_buffer_data8, COLOR_DASHBOARD, GL_FILL);


    //fuel

    GLfloat vertex_buffer_data9[200];
    this->seven_segment(vertex_buffer_data9,1,0,0,0,1,1,1,x,y-6,z-20,11);
    this->object[8] = create3DObject(GL_TRIANGLES, 4*6, vertex_buffer_data9, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data10[200];
    this->seven_segment(vertex_buffer_data10,0,1,1,1,1,1,0,x+1.3,y-6,z-20,11);
    this->object[9] = create3DObject(GL_TRIANGLES, 5*6, vertex_buffer_data10, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data11[200];
    this->seven_segment(vertex_buffer_data11,1,0,0,1,1,1,1,x+1.3*2,y-6,z-20,11);
    this->object[10] = create3DObject(GL_TRIANGLES, 5*6, vertex_buffer_data11, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data12[200];
    this->seven_segment(vertex_buffer_data12,0,0,0,1,1,1,0,x+1.3*3,y-6,z-20,11);
    this->object[11] = create3DObject(GL_TRIANGLES, 3*6, vertex_buffer_data12, COLOR_DASHBOARD, GL_FILL);

    //speed values
    GLfloat vertex_buffer_data13[200];
    this->seven_segment(vertex_buffer_data13,1,1,1,1,1,1,1,(this->position.x+10+1.3*7),(this->position.y+10),(this->position.z-20),11);
    this->object[12] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data13, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data14[200];
    this->seven_segment(vertex_buffer_data14,1,1,1,1,1,1,1,(this->position.x+10+1.3*8),(this->position.y+10),(this->position.z-20),11);
    this->object[13] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data14, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data15[200];
    this->seven_segment(vertex_buffer_data15,1,1,1,1,1,1,1,(this->position.x+10+1.3*9),(this->position.y+10),(this->position.z-20),11);
    this->object[14] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data15, COLOR_DASHBOARD, GL_FILL);
    
    //alt values
    GLfloat vertex_buffer_data16[200];
    this->seven_segment(vertex_buffer_data16,1,1,1,1,1,1,1,(this->position.x+10+1.3*7),(this->position.y+10-3),(this->position.z-20),11);
    this->object[15] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data16, COLOR_DASHBOARD, GL_FILL);
    
    GLfloat vertex_buffer_data17[200];
    this->seven_segment(vertex_buffer_data17,1,1,1,1,1,1,1,(this->position.x+10+1.3*8),(this->position.y+10-3),(this->position.z-20),11);
    this->object[16] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data17, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data18[200];
    this->seven_segment(vertex_buffer_data18,1,1,1,1,1,1,1,(this->position.x+10+1.3*9),(this->position.y+10-3),(this->position.z-20),11);
    this->object[17] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data18, COLOR_DASHBOARD, GL_FILL);

    //speed values
    GLfloat vertex_buffer_data19[200];
    this->seven_segment(vertex_buffer_data19,1,1,1,1,1,1,1,(this->position.x+10+1.3*7),(this->position.y+10-6),(this->position.z-20),11);
    this->object[18] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data19, COLOR_DASHBOARD, GL_FILL);
    
    GLfloat vertex_buffer_data20[200];
    this->seven_segment(vertex_buffer_data20,1,1,1,1,1,1,1,(this->position.x+10+1.3*8),(this->position.y+10-6),(this->position.z-20),11);
    this->object[19] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data20, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data21[200];
    this->seven_segment(vertex_buffer_data21,1,1,1,1,1,1,1,(this->position.x+10+1.3*9),(this->position.y+10-6),(this->position.z-20),11);
    this->object[20] = create3DObject(GL_TRIANGLES, 7*6, vertex_buffer_data21, COLOR_DASHBOARD, GL_FILL);


}



void Dashboard::draw(glm::mat4 VP, int view) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * rotate2);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(view == 1 || view == 2 || view == 3 ){
        for(int i=0;i<21;i++)
            draw3DObject(this->object[i]);
    }
}

void Dashboard::print_speed(int speed, int alt, int fuel){

    float x = -2;
    float y = 0;
    float z = -2;

    int arr[10];
    int i=0;
    arr[0]=0;arr[1]=0;arr[2]=0;

    int digitdata[20];

    digitdata[0]=6*6;digitdata[1]=2*6;digitdata[2]=5*6;digitdata[3]=5*6;digitdata[4]=4*6;digitdata[5]=5*6;digitdata[6]=6*6;digitdata[7]=4*6;digitdata[8]=7*6;digitdata[9]=6*6;
    
    if(speed == 0)
    {
        //pass
    }
    while (speed != 0)
    {
        int digit = speed % 10;
        arr[i] = digit;
        i++;
        speed /= 10;
    }
    // cout << arr[0] <<" "<<arr[1]<<" "<<arr[2]<<endl;

    //speed values
    GLfloat vertex_buffer_data22[200];
    this->seven_segment(vertex_buffer_data22,1,0,1,1,0,0,1,(x+10+1.3*7),(y+10),(z-20),arr[2]);
    this->object[12] = create3DObject(GL_TRIANGLES, digitdata[arr[2]], vertex_buffer_data22, COLOR_DASHBOARD, GL_FILL);
    
    GLfloat vertex_buffer_data23[200];
    this->seven_segment(vertex_buffer_data23,1,0,1,1,0,0,1,(x+10+1.3*8),(y+10),(z-20),arr[1]);
    this->object[13] = create3DObject(GL_TRIANGLES,  digitdata[arr[1]], vertex_buffer_data23, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data24[200];
    this->seven_segment(vertex_buffer_data24,1,0,1,1,1,1,1,(x+10+1.3*9),(y+10),(z-20),arr[0]);
    this->object[14] = create3DObject(GL_TRIANGLES,  digitdata[arr[0]], vertex_buffer_data24, COLOR_DASHBOARD, GL_FILL);
    
    //alt values
    arr[0]=0;arr[1]=0;arr[2]=0;
    i=0;
    if(alt == 0)
    {
        //pass
    }
    while (alt != 0)
    {
        int digit = alt % 10;
        arr[i] = digit;
        i++;
        alt /= 10;
    }

    GLfloat vertex_buffer_data25[200];
    this->seven_segment(vertex_buffer_data25,1,0,1,1,0,1,1,(x+10+1.3*7),(y+10-3),(z-20),arr[2]);
    this->object[15] = create3DObject(GL_TRIANGLES, digitdata[arr[2]], vertex_buffer_data25, COLOR_DASHBOARD, GL_FILL);
    
    GLfloat vertex_buffer_data26[200];
    this->seven_segment(vertex_buffer_data26,1,0,1,1,0,1,1,(x+10+1.3*8),(y+10-3),(z-20),arr[1]);
    this->object[16] = create3DObject(GL_TRIANGLES, digitdata[arr[1]], vertex_buffer_data26, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data27[200];
    this->seven_segment(vertex_buffer_data27,1,0,1,1,0,1,1,(x+10+1.3*9),(y+10-3),(z-20),arr[0]);
    this->object[17] = create3DObject(GL_TRIANGLES, digitdata[arr[0]], vertex_buffer_data27, COLOR_DASHBOARD, GL_FILL);

    //fuel values
    arr[0]=0;arr[1]=0;arr[2]=0;
    i=0;
    if( fuel == 0)
    {
        //pass
    }
    while (fuel != 0)
    {
        int digit = fuel % 10;
        arr[i] = digit;
        i++;
        fuel /= 10;
    }
    GLfloat vertex_buffer_data28[200];
    this->seven_segment(vertex_buffer_data28,1,0,1,1,0,1,1,(x+10+1.3*7),(y+10-6),(z-20),arr[2]);
    this->object[18] = create3DObject(GL_TRIANGLES, digitdata[arr[2]], vertex_buffer_data28, COLOR_DASHBOARD, GL_FILL);
    
    GLfloat vertex_buffer_data29[200];
    this->seven_segment(vertex_buffer_data29,1,0,1,1,0,1,1,(x+10+1.3*8),(y+10-6),(z-20),arr[1]);
    this->object[19] = create3DObject(GL_TRIANGLES, digitdata[arr[1]], vertex_buffer_data29, COLOR_DASHBOARD, GL_FILL);

    GLfloat vertex_buffer_data30[200];
    this->seven_segment(vertex_buffer_data30,1,0,1,1,0,1,1,(x+10+1.3*9),(y+10-6),(z-20),arr[0]);
    this->object[20] = create3DObject(GL_TRIANGLES, digitdata[arr[0]], vertex_buffer_data30, COLOR_DASHBOARD, GL_FILL);
}

void Dashboard::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}


