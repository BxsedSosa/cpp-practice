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

// Validate

bool validatePlayerSelection(string playerSelection) {
  int numberSelected;
  try {
    numberSelected = stoi(playerSelection);
  } catch (invalid_argument &err) {
    return true;
  }
  return numberSelected <= 0 || numberSelected > 9;
}

bool checkUsedSelection(vector<vector<char>> map, vector<int> corrdinates) {
  int rowCorr = corrdinates[0];
  int colCorr = corrdinates[1];
  char locationsChar = map[rowCorr][colCorr];

  return locationsChar == 'x' || locationsChar == 'o';
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

void changeMap(vector<vector<char>> &map, vector<int> corrdinates,
               bool isPlayer) {
  int rowCorr = corrdinates[0];
  int colCorr = corrdinates[1];

  if (isPlayer) {
    map[rowCorr][colCorr] = 'x';
  } else {
    map[rowCorr][colCorr] = 'o';
  }
}

vector<int> getCorrdinates(string playerSelection) {
  unordered_map<string, vector<int>> selectionMap = createGridMap();

  return selectionMap[playerSelection];
}

// Player

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
  vector<vector<char>> gridMap = createMap();
  string playerSelection = getPlayerSelection();

  changeMap(gridMap, getCorrdinates(playerSelection), true);
  displayMap(gridMap);
  return 0;
}
