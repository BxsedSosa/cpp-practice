#include "../includes/Database.h"
#include <iostream>
#include <sqlite3.h>
#include <string>

int main() {
  Database inventory;
  std::string user_input;

  int exit = 0;

  exit = sqlite3_open("Inventory.db", &inventory.db);

  while (std::cin >> user_input) {
    if (user_input == "1") {
      inventory.createNewTable(inventory.retrieveTableName());
    } else if (user_input == "0") {
      break;
    } else {
      std::cout << "Please input a valid option!\n";
    }
  }

  sqlite3_close(inventory.db);
  return 0;
}
