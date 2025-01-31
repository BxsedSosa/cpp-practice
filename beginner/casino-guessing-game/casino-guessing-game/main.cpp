#include "Casino.h"
#include "Player.h"

int main() {
  Casino casino;
  Player player;

  casino.startGame(player);

  if (casino.checkForWinner(player.getGuess())) {
    casino.playerWon(player);
  } else {
    casino.playerLost(player);
  }

  return 0;
}
