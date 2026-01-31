#pragma once

#include "Card.h"
#include <vector>

class Display {
private:
  std::string flat_line = " ------- ";
  std::string body = "|       |";

public:
  std::vector<std::string> create_card(Card);
  std::vector<std::string> join_cards(std::vector<Card>);
  void card(std::vector<std::string>);
};
