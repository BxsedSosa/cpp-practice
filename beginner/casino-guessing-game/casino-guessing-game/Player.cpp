#include "Player.h"
#include <iostream>

bool validateMaxNumber(int maxNum) { return maxNum < 10; }

bool validatePlayerBet(int chips, int bet) { return bet > chips && bet > 0; }

bool validatePlayerGuess(int guess, int maxNum) {
  return guess > maxNum && guess < 0;
}

int Player::getChips() { return this->chips; }
int Player::getBet() { return this->bet; }

void Player::setBet() {
  int bet;

  std::cout << "You have " << this->chips << "\nPlease enter a bet:\n>>> $";
  std::cin >> bet;

  while (validatePlayerBet(this->getChips(), bet)) {
    std::cout << bet << " is larger or small than your chips\nYou have "
              << this->chips << "\nPlease enter a bet:\n>>> $";
    std::cin >> bet;
  }

  this->bet = bet;
}

void Player::setGuess(int maxNum) {
  int guess;

  std::cout << "Please enter a number between 1 and " << maxNum << ":\n>>> ";
  std::cin >> guess;

  while (validatePlayerGuess(guess, maxNum)) {
    std::cout << guess << " is greater than " << maxNum
              << "or less than 1\nPlease enter a number between 1 and "
              << maxNum << ":\n>>> ";
    std::cin >> guess;
  }

  this->guess = guess;
}

void Player::setMaxNumber() {
  int maxNumber;

  std::cout << "Please enter a number at 10 or higher:\n>>> ";
  std::cin >> maxNumber;

  while (validateMaxNumber(maxNumber)) {
    std::cout
        << maxNumber
        << " is less than 10!\nPlease enter a number at 10 or higher:\n>>> ";
    std::cin >> maxNumber;
  }

  this->maxNumber = maxNumber;
}
