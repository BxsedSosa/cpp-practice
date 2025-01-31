#include "Game.h"
#include <iostream>

void Game::setRandomNumber() {
  srand(time(0));
  this->randomNumber = rand() % this->maxRange + 1;
}

void Game::setMaxRange(int maxRange) { this->maxRange = maxRange; }
