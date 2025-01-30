#include "Player.hpp"
#include <iostream>

bool validatePlayerBet(int chips, int bet) { return bet > chips && bet > 0; }

void Player::setBet() {
  int bet;

  std::cout << "You have " << this->chips << "\nPlease enter a bet:\n>>> $";
  std::cin >> bet;

  while (validatePlayerBet(this->getChips(), bet)) {
    std::cout << bet << " is larger or small than your chips\nYou have "
              << this->chips << "\nPlease enter a bet:\n>>> $";
    std::cin >> bet;
  }

  this->bet = bet;
}
