#include "../includes/Square.h"
#include "raylib.h"
#include <string>

Square::Square(float xPos, float yPos, float width, float height) {
  this->pos = {xPos, yPos};
  this->size = {width, height};
  this->mass = 1000;
}

std::string Square::getColor () { return this->color;}
Vector2 Square::getPos() {return this->pos;}
Vector2 Square::getSize() {return this->size;}
int Square::getMass() {return this->mass;}

