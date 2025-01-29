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

bool validateUserInput(string userSelection) {
  int numberSelected;
  try {
    numberSelected = stoi(userSelection);
  } catch (invalid_argument &err) {
    return true;
  }
  return numberSelected <= 0 || numberSelected > 9;
}

bool validateUsedSelection(vector<vector<char>> map, vector<int> corrdinates) {
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

vector<string> getHashKeys() {
  vector<string> keys;
  unordered_map<string, vector<int>> gridMap = createGridMap();

  for (auto pair : gridMap) {
    keys.push_back(pair.first);
  }

  return keys;
}

void displayMap(vector<vector<char>> &grid) {
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

bool checkThreeInRow(vector<vector<char>> gridMap) {
  char firstMoveInRow;

  for (int row = 0; row < gridMap.size(); row++) {
    firstMoveInRow = gridMap[row][0];
    for (int column = 1; column < gridMap.size(); column++) {
      if (firstMoveInRow != gridMap[row][column]) {
        break;
      }

      if (firstMoveInRow == gridMap[row][column] &&
          column == gridMap[row].size()) {
        return true;
      }
    }
  }

  return false;
}

// Player

string getPlayerSelection(vector<vector<char>> &gridMap) {
  string playerSelection;

  displayMap(gridMap);
  cout << "Please make a selection between 1 - 9:\n";
  cin >> playerSelection;

  while (validateUserInput(playerSelection) ||
         validateUsedSelection(gridMap, getCorrdinates(playerSelection))) {

    if (validateUserInput(playerSelection)) {
      displayMap(gridMap);
      cout
          << playerSelection
          << " is not a valid input!\nPlease make a selection between 1 - 9:\n";
      cin >> playerSelection;
    } else {
      displayMap(gridMap);
      cout << playerSelection
           << " is already used input!\nPlease make a seleection between 1 - "
              "9:\n";
      cin >> playerSelection;
    }
  }

  return playerSelection;
}

// CPU

int getRandomNumber() { return rand() % 8; }

vector<int> getCpuSelection(vector<vector<char>> &gridMap) {
  vector<string> gridKeys = getHashKeys();
  vector<int> cpuSelection = getCorrdinates(gridKeys[getRandomNumber()]);

  while (validateUsedSelection(gridMap, cpuSelection)) {
    cpuSelection = getCorrdinates(gridKeys[getRandomNumber()]);
  }

  return cpuSelection;
}

// Main

int main() {
  bool running = true;
  vector<vector<char>> gridMap = createMap();
  string playerSelection;
  vector<int> cpuSelection;

  while (running) {
    playerSelection = getPlayerSelection(gridMap);
    changeMap(gridMap, getCorrdinates(playerSelection), true);
    cpuSelection = getCpuSelection(gridMap);
    changeMap(gridMap, cpuSelection, false);
  }
  return 0;
}
