#pragma once

#include <string>

class Card {
private:
  char suit;
  std::string value;

public:
  Card(char s, std::string v);
  char get_suit();
  std::string get_value();
};
