#pragma once

#include "Deck.h"
#include "Player.h"
#include <vector>

class Dealer : public Player {
private:
  Deck game_deck;
  int balance = 999999999;

public:
  void create_deck(int decks);
  void show_shoe();
  Card draw_card();
  int cards_left_in_deck();
};
