#include <raylib.h>

#include "../includes/Circle.h"
#include "../includes/Square.h"

// #define UP_KEY 265
// #define DOWN_KEY 264
// #define RIGHT_KEY 262
// #define LEFT_KEY 263

/*
 * 263 up
 * 265 left
 * 264 down
 * 262 right
 */

Circle::Circle(float xCor, float yCor, float radius) {
  Vector2 coors;
  this->radius = radius;
  this->xSpeed = 2.0f;
  this->ySpeed = 2.0f;
  this->mass = 100;
  setxCor(xCor);
  setyCor(yCor);
}

Vector2 Circle::getVec() { return this->coors; }
float Circle::getxCor() { return this->coors.x; }
float Circle::getyCor() { return this->coors.y; }
float Circle::getRadius() { return this->radius; }

void Circle::setxCor(float xCor) { this->coors.x = xCor; }
void Circle::setyCor(float yCor) { this->coors.y = yCor; }
void Circle::setRadius(float radius) { this->radius = radius; }

void Circle::drag() {
  if (isMouseInCircle()) {
    Vector2 mousePos = GetMousePosition();
    this->coors.x = mousePos.x;
    this->coors.y = mousePos.y;
  }
}

void Circle::movement() {
  this->coors.x += this->xSpeed;
  this->coors.y += this->ySpeed;
}

void Circle::outOfBounds() {
  if (this->coors.x > GetScreenWidth() - this->radius ||
      this->coors.x < this->radius) {
    this->xSpeed *= -1.0f;
  }

  if (this->coors.y > GetScreenHeight() - this->radius ||
      this->coors.y < this->radius) {
    this->ySpeed *= -1.0f;
  }
}

void Circle::bounce() {}

bool Circle::isMouseInCircle() {
  Vector2 mousePos = GetMousePosition();
  bool withinYpos = mousePos.y > this->coors.y - this->radius &&
                    mousePos.y < this->coors.y + this->radius;
  bool withinXpos = mousePos.x > this->coors.x - this->radius &&
                    mousePos.x < this->coors.x + this->radius;

  return IsMouseButtonDown(MOUSE_BUTTON_LEFT) && (withinXpos && withinYpos);
}

void Circle::gravity(Square floor) {
  /*
   * if ball is not on the ground, hit needs to fall 1 px at a time
   */
}
