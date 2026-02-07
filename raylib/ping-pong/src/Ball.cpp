#include "../includes/Ball.h"
#include <raylib.h>

Ball::Ball(Vector2 pos, float radius, Color color) {
  this->pos = pos;
  this->radius = radius;
  this->color = color;
  this->ySpeed = 3.0f;
  this->xSpeed = 3.0f;
}

void Ball::draw() { DrawCircleV(this->pos, this->radius, this->color); }

void Ball::movement() {

  if (touchBorder()) {
    this->ySpeed *= -1.0f;
  }

  if (isScored()) {
    resetToCenter();
  }

  this->pos.x += this->xSpeed;
  this->pos.y += this->ySpeed;
}

void Ball::resetToCenter() {
  int screenHeight = GetScreenHeight();
  int screenWidth = GetScreenWidth();

  this->pos.y = screenHeight / 2;
  this->pos.x = screenWidth / 2;
  this->xSpeed *= -1;
}

bool Ball::touchBorder() {
  int screenHeight = GetScreenHeight();
  return this->pos.y < (0 + this->radius) ||
         this->pos.y > (screenHeight - this->radius);
}

bool Ball::isScored() {
  int screenWidth = GetScreenWidth();
  return this->pos.x < (0 + this->radius) ||
         this->pos.x > (screenWidth - this->radius);
}
