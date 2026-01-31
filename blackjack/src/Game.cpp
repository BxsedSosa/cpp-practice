#include "../includes/Game.h"
#include <iostream>
#include <string>
#include <vector>

void Game::start_game() {
  std::string choice;
  dealer.create_deck(6);
  while (std::cin >> choice) {
    if (choice == "1") {
      player.set_new_card(dealer.draw_card());
    } else if (choice == "2") {
      dealer.set_new_card(dealer.draw_card());
    } else if (choice == "3") {
      break;
    }
  }
}

Dealer Game::get_dealer() { return dealer; }
Player Game::get_player() { return player; }

std::vector<Card> Game::get_dealer_cards() {
  return dealer.get_hand().get_cards();
}

std::vector<Card> Game::get_player_cards() {
  return player.get_hand().get_cards();
}
