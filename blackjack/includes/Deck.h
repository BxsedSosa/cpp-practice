#pragma once

#include "Card.h"
#include <vector>

class Deck {

private:
  std::vector<Card> game_deck;

public:
  void make_decks(int decks);
  void display_deck();
  std::vector<Card> shuffle_deck(std::vector<Card> deck);
  std::vector<Card> get_deck();
  int get_cards_left();
  Card draw_top_card();
};
