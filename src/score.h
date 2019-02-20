#include "main.h"

#ifndef SCORE_H
#define SCORE_H
#define GLM_ENABLE_EXPERIMENTAL


class Score {
public:
    Score() {}
    Score(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float rotation2;
    void print_score(int score, glm::mat4 VP);
    void draw(glm::mat4 VP, int digit);
    void set_position(float x, float y, float z);
    void tick();
private:
    VAO *object[7];
};

#endif // SCORE_H