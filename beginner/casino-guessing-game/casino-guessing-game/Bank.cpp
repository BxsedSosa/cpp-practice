#include "Bank.h"

void Bank::takeChips(Player &player) {
  int difference = player.getChips() - player.getBet();
  player.setChips(player.getChips() - difference);

  this->chips += difference;
}

void Bank::setChips(int chips) { this->chips = chips; }

void Bank::giveChips(Player &player) {
  this->chips -= player.getBet();
  player.setChips(player.getChips() + player.getBet());
}

int Bank::getChips() { return this->chips; }
