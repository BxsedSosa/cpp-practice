#pragma once

#include "raylib.h"
class Circle {
  private:
    Vector2 coors;
    float radius;
    float xSpeed;
    float ySpeed;

  public:
    Circle(float, float, float);
    Vector2 getVec();
    float getxCor();
    float getyCor();
    float getRadius();
    void setxCor(float);
    void setyCor(float);
    void setRadius(float);
    void drag();
    void movement();
    void outOfBounds();
    void bounce();
    bool isMouseInCircle();
};

