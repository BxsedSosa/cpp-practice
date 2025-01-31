#pragma once

class Player {
private:
  int chips = 100;
  int bet;
  int guess;

public:
  void setChips(int chips);
  void setGuess(int maxNum);
  void setBet();

  int getChips();
  int getBet();
  int getGuess();
};
