#include <iostream>
#include <vector>

int getRandomNumber() {
  srand(time(0));
  return std::rand() % 3;
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
  std::cout << "Random number: " << randomNum << '\n';

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

bool determineWinner() { return true; }

int main() {
  std::string playerInput = getPlayerInput();
  std::string cpuSelection = getCpuSelection();

  std::cout << "Player Input = " << playerInput
            << " Cpu Input = " << cpuSelection << '\n';
  return 0;
}
