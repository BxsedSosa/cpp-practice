#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<char>> createMap() {
  vector<vector<char>> map = {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '},
  };

  return map;
}

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

int main() {
  vector<vector<char>> grid = createMap();
  unordered_map<string, vector<int>> mapping = createGridMap();
  string playerSelection;

  cout << "Please make a selection:\n";
  cin >> playerSelection;

  cout << "selection: " << mapping[playerSelection][0] << ", "
       << mapping[playerSelection][1] << '\n';

  displayMap(grid);
  return 0;
}
