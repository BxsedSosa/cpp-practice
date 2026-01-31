#pragma once

#include "Dealer.h"
#include "Player.h"
#include <string>
#include <vector>

class Game {
private:
  Dealer dealer;
  Player player;

public:
  void start_game();
  Dealer get_dealer();
  Player get_player();
  std::vector<Card> get_dealer_cards();
  std::vector<Card> get_player_cards();
};
