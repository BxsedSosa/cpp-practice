#include "../includes/Deck.h"
#include "../includes/Card.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

std::vector<char> suits = {'D', 'C', 'S', 'H'};
std::vector<std::string> values = {"A", "2", "3",  "4", "5", "6", "7",
                                   "8", "9", "10", "J", "Q", "K"};

void Deck::display_deck() {
  for (int i = 0; i < game_deck.size(); i++) {
    std::cout << "Card - Suit: " << game_deck[i].get_suit()
              << " Value: " << game_deck[i].get_value() << '\n';
  }
}

int Deck::get_cards_left() { return game_deck.size(); }

void Deck::make_decks(int decks) {
  std::vector<Card> deck;
  for (int j = 0; j < decks; j++) {
    for (int i = 0; i < suits.size(); i++) {
      for (int k = 0; k < values.size(); k++) {
        deck.push_back(Card(suits[i], values[k]));
      }
    }
  }
  game_deck = shuffle_deck(deck);
}

std::vector<Card> Deck::shuffle_deck(std::vector<Card> deck) {
  std::random_device seed;
  std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed()));
  return deck;
}

std::vector<Card> Deck::get_deck() { return this->game_deck; }

Card Deck::draw_top_card() {
  int last_idx = game_deck.size() - 1;
  Card card = game_deck[last_idx];
  game_deck.pop_back();
  return card;
}
