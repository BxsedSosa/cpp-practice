#include "../includes/Hand.h"
#include "../includes/Card.h"
#include <vector>

std::vector<Card> Hand::get_cards() { return hand; }
void Hand::set_new_card(Card new_card) { hand.push_back(new_card); }
