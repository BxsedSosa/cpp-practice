#pragma once

#include "Card.h"
#include <vector>

class Hand {
private:
  std::vector<Card> hand;

public:
  std::vector<Card> get_cards();
  void set_new_card(Card new_card);
};
