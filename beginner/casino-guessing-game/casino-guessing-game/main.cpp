#include "Player.h"
#include <iostream>

int main() {
  Player player;

  player.setBet();
  std::cout << "Player bet: " << player.getBet()
            << "\nPlayer Chips: " << player.getChips() << '\n';
  return 0;
}
