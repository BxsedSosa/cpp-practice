#pragma once

#include "Card.h"
#include "Hand.h"
#include <vector>

class Player {
private:
  Hand hand;
  int balance = 100;

public:
  int get_balance();
  void set_balance(int amount);
  void set_new_card(Card new_card);
  Hand get_hand();
  void display_hand();
};
