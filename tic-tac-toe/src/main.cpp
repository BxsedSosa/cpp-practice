#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Utility

void clearConsole() { system("clear || cls"); }

vector<vector<char>> createMap() {
  vector<vector<char>> map = {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '},
  };

  return map;
}

// Map

unordered_map<string, vector<int>> createGridMap() {
  unordered_map<string, vector<int>> mapping;
  int counter = 1;
  int maxSize = 3;

  for (int i = 0; i < maxSize; i++) {
    for (int k = 0; k < maxSize; k++) {
      mapping[to_string(counter)] = {i, k};
      counter++;
    }
  }
  return mapping;
}

void displayMap(vector<vector<char>> grid) {
  for (int i = 0; i < grid.size(); i++) {
    for (int k = 0; k < grid[i].size(); k++) {
      if (k == grid[i].size() - 1) {
        cout << grid[i][k] << '\n';
      } else {
        cout << grid[i][k] << " | ";
      }
    }
    if (i < grid.size() - 1) {
      cout << "---------" << '\n';
    }
  }
}

// Player

bool validatePlayerSelection(string playerSelection) {
  int numberSelected;
  try {
    numberSelected = stoi(playerSelection);
  } catch (invalid_argument &err) {
    return true;
  }
  return numberSelected <= 0 || numberSelected > 9;
}

string getPlayerSelection() {
  string playerSelection;

  clearConsole();
  cout << "Please make a selection between 1 - 9:\n";
  cin >> playerSelection;

  while (validatePlayerSelection(playerSelection)) {
    clearConsole();
    cout << playerSelection
         << " is not a valid input!\nPlease make a selection between 1 - 9:\n";
    cin >> playerSelection;
  }

  return playerSelection;
}

int main() {
  vector<vector<char>> grid = createMap();
  unordered_map<string, vector<int>> mapping = createGridMap();
  string playerSelection = getPlayerSelection();

  cout << "selection: " << mapping[playerSelection][0] << ", "
       << mapping[playerSelection][1] << '\n';

  displayMap(grid);
  return 0;
}
