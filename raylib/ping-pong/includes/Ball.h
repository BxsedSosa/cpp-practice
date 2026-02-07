#pragma once

#include <raylib.h>

class Ball {
private:
  Vector2 pos;
  float radius;
  Color color;
  int ySpeed;
  int xSpeed;

public:
  Ball(Vector2, float, Color);
  void draw();
  void movement();
  void resetToCenter();
  bool touchBorder();
  bool isScored();
};
