#pragma once

class Casino {
private:
  int maxRange;
  int randomNumber;

public:
  void setMaxRange(int maxRange);
  int getRandomNumber();
  int givePlayerChips();
};
