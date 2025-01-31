#pragma once

#include "Player.h"

class Bank {
private:
  int chips;

public:
  void setChips(int chips);
  void takeChips(Player &player);
  void giveChips(Player &player);

  int getChips();
};
