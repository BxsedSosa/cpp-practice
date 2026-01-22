#include "../includes/Item.h"
#include <cstdlib>
#include <iostream>
#include <sqlite3.h>
#include <string>

std::string retrieveTableName() {
  std::string tableName;
  std::cin >> tableName;

  return tableName;
}

void createNewTable(sqlite3 *db, int exit, std::string inv_name) {
  std::string sql = "CREATE TABLE " + inv_name +
                    "("
                    "ID INT PRIMARY KEY,"
                    "NAME           TEXT,"
                    "QUANTITY INT,"
                    "PRICE REAL);";
  char *messErr;
  exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messErr);

  if (exit != SQLITE_OK) {
    std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
    sqlite3_free(messErr);
  } else
    std::cout << "Opened Database Successfully!" << std::endl;
}

void insertNewInventory() {}

int main() {
  std::string user_input;
  sqlite3 *db;
  int exit = 0;

  exit = sqlite3_open("Inventory.db", &db);

  while (std::cin >> user_input) {
    if (user_input == "1") {
      createNewTable(db, exit, retrieveTableName());
    } else if (user_input == "0") {
      break;
    } else {
      std::cout << "Please input a valid option!\n";
    }
  }

  sqlite3_close(db);
  return 0;
}
