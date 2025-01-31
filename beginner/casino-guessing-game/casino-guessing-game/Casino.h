#pragma once

#include <iostream>

#include "Bank.h"
#include "Game.h"
#include "Player.h"

class Casino {
private:
  Bank bank;
  Game game;

public:
  void startGame(Player &player);
  void playerWon(Player &player);
  void playerLost(Player &player);
  bool checkForWinner(int playerGuess);
};
