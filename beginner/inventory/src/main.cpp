#include "../includes/Database.h"
#include <cstdlib>
#include <iostream>
#include <sqlite3.h>
#include <string>

int main() {
  Database inventory;
  std::string user_input;

  inventory.status = sqlite3_open("Inventory.db", &inventory.db);

  if (inventory.status) {
    std::cerr << "Error open DB " << sqlite3_errmsg(inventory.db) << std::endl;
    return (-1);
  }

  system("cls || clear");
  while (std::cin >> user_input) {
    system("cls || clear");
    if (user_input == "1") {
      inventory.createNewTable();
    } else if (user_input == "2") {
      inventory.insertNewData();
    } else if (user_input == "3") {
      inventory.displayTable();
    } else if (user_input == "4") {
      inventory.deleteRow();
    } else if (user_input == "0") {
      break;
    } else {
      std::cout << "Please input a valid option!\n";
    }
  }

  sqlite3_close(inventory.db);
  return 0;
}
