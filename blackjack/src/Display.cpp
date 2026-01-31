#include "../includes/Display.h"
#include <iostream>
#include <vector>

std::vector<std::string> Display::create_card(Card card) {
  std::vector<std::string> display_card;
  for (int i = 0; i < 7; i++) {
    if (i == 0 || i == 6) {
      display_card.push_back(flat_line);
    } else if (i == 1) {
      std::string new_body = body;
      new_body[1] = card.get_suit();
      display_card.push_back(new_body);
    } else if (i == 6) {
      std::string new_body = body;
      new_body[6] = card.get_suit();
      display_card.push_back(new_body);
    } else if (i == 3) {
      std::string new_body = body;
      new_body[4] = card.get_value().c_str()[0];
      display_card.push_back(new_body);
    } else {
      display_card.push_back(body);
    }
  }
  return display_card;
}

std::vector<std::string> Display::join_cards(std::vector<Card> cards) {
  std::vector<std::string> cards_display;
  std::vector<std::vector<std::string>> cards_strings;

  for (int i = 0; i < cards.size(); i++) {
    cards_strings.push_back(create_card(cards[i]));
  }

  std::cout << cards_strings.size() << '\n';

  for (int i = 0; i < cards_strings[0].size(); i++) {
    std::string new_string;
    for (int k = 0; k < cards_strings.size(); k++) {
      if (k == 0) {
        new_string = cards_strings[k][i];
      } else {
        new_string = new_string + " " + cards_strings[k][i];
      }
    }
    cards_display.push_back(new_string);
  }

  return cards_display;
}

/*
" ------- "
"|♢      |"
"|       |"
"|   9   |"
"|       |"
"|      ♢|"
" ------- "
*/

void Display::card(std::vector<std::string> display_cards) {
  for (int i = 0; i < display_cards.size(); i++) {
    std::cout << display_cards[i] << '\n';
  }
}
