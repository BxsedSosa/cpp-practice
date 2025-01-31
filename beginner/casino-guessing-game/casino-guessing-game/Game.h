#pragma once

class Game {
private:
  int maxRange;
  int randomNumber;

public:
  void setMaxRange(int maxRange);
  void setRandomNumber();

  int getRandomNumber() { return this->randomNumber; }
};
