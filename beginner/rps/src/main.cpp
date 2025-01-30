#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int getRandomNumber() {
  srand(time(0));
  return std::rand() % 3;
}

std::vector<std::string>
getHashKeys(std::unordered_map<std::string, std::string> hashMap) {
  std::vector<std::string> keys;
  for (auto pair : hashMap) {
    keys.push_back(pair.first);
  }
  return keys;
}

std::unordered_map<std::string, std::string> getWinningCombos() {
  std::unordered_map<std::string, std::string> winningCombos;

  winningCombos["rock"] = "sisscors";
  winningCombos["paper"] = "rock";
  winningCombos["sisscors"] = "paper";

  return winningCombos;
}

bool validatePlayerInput(std::string playerInput) {
  std::vector<std::string> validInputs = {"rock", "paper", "scissors"};

  for (std::string validInput : validInputs) {
    if (playerInput == validInput) {
      return false;
    }
  }

  return true;
}

std::string getPlayerInput() {
  std::string playerInput;
  std::cout
      << "Please enter a selection of:\n1. Rock\n2. Paper\n3. Scissors\n>>> ";
  std::cin >> playerInput;

  while (validatePlayerInput(playerInput)) {

    std::cout << playerInput
              << " is not a valid input!\nPlease enter a selection of:\n1. "
                 "Rock\n2. Paper\n3. Scissors\n>>> ";
    std::cin >> playerInput;
  }

  return playerInput;
}

std::string getCpuSelection() {
  int randomNum = getRandomNumber();

  switch (randomNum) {
  case 0:
    return "rock";
  case 1:
    return "paper";
  case 2:
    return "sisscors";
  }

  return "";
}

bool determineWinner(std::string playerSelection, std::string cpuSelection) {
  std::unordered_map<std::string, std::string> winningCombos =
      getWinningCombos();

  if (cpuSelection == winningCombos[playerSelection]) {
    return true;
  }

  return false;
}

int main() {
  std::string playerInput = getPlayerInput();
  std::string cpuSelection = getCpuSelection();

  if (determineWinner(playerInput, cpuSelection)) {
    std::cout << "Player Wins!\nPlayer picked: " << playerInput
              << "\nCpu picked: " << cpuSelection << "\n";
  } else {
    std::cout << "Cpu Wins!\nPlayer picked: " << playerInput
              << "\nCpu picked: " << cpuSelection << "\n";
  }

  return 0;
}
