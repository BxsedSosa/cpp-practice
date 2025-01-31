#pragma once

class Player {
private:
  int chips;
  int maxNumber;
  int bet;
  int guess;

public:
  void setChips(int chips);
  void setGuess(int maxNum);
  void setBet();
  void setMaxNumber();

  int getChips();
  int getBet();
  int getGuess();
};
