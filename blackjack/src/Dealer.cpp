#include "../includes/Dealer.h"
#include "../includes/Deck.h"

void Dealer::create_deck(int decks) { this->game_deck.make_decks(decks); }
void Dealer::show_shoe() { this->game_deck.display_deck(); }
int Dealer::cards_left_in_deck() { return this->game_deck.get_cards_left(); };
Card Dealer::draw_card() { return game_deck.draw_top_card(); }
