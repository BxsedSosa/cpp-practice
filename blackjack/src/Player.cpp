#include "../includes/Player.h"
#include "../includes/Hand.h"
#include <iostream>
#include <vector>

int Player::get_balance() { return balance; }
void Player::set_balance(int amount) { balance += amount; }
Hand Player::get_hand() { return hand; }

void Player::set_new_card(Card new_card) { hand.set_new_card(new_card); }

void Player::display_hand() {
  std::vector<Card> temp = hand.get_cards();
  for (int i = 0; i < temp.size(); i++) {
    std::cout << "Hand - Suit=" << temp[i].get_suit()
              << " Value=" << temp[i].get_value() << '\n';
  }
}
