#pragma once

#include "raylib.h"
#include <string>

class Square{
  private:
    Vector2 pos;
    Vector2 size;
    int mass;
    std::string color;

  public:
    Square(float, float, float, float);
    Vector2 getPos();
    Vector2 getSize();
    int getMass();
    std::string getColor();
};
