#include "../includes/Card.h"
#include <string>

Card::Card(char s, std::string v) {
  suit = s;
  value = v;
}

char Card::get_suit() { return suit; }
std::string Card::get_value() { return value; }
