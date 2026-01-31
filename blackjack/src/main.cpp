#include "../includes/Display.h"
#include "../includes/Game.h"

int main() {
  Game game;
  Display display;
  game.start_game();
  display.card(display.join_cards(game.get_dealer_cards()));
  return 0;
}
