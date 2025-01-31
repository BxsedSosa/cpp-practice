#include "Casino.h"

bool Casino::checkForWinner(int playerGuess) {
  return playerGuess == this->game.getRandomNumber();
}

void Casino::startGame(Player &player) {
  player.setBet();
  player.setMaxNumber();
  player.setGuess(player.getMaxNumber());

  this->game.setMaxRange(player.getMaxNumber());
  this->game.setRandomNumber();

  if (Casino::checkForWinner(player.getGuess())) {
    std::cout << "You won!\nCasinos number: " << game.getRandomNumber()
              << "\nYou picked: " << player.getGuess() << '\n';
  } else {
    std::cout << "You lose!\nCasinos number: " << game.getRandomNumber()
              << "\nYou picked: " << player.getGuess() << '\n';
  }
}

void Casino::playerWon(Player &player) { this->bank.giveChips(player); }

void Casino::playerLost(Player &player) { this->bank.takeChips(player); }
