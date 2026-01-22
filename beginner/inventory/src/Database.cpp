#include "../includes/Database.h"
#include "../includes/Item.h"
#include <cstdlib>
#include <sqlite3.h>
#include <string>

std::string Database::retrieveTableName() {
  std::string tableName;
  system("cls || clear");
  std::cout << "Enter Table name: ";
  std::cin >> tableName;
  return tableName;
}

void Database::createNewTable() {
  char *messErr;
  std::string tableName = retrieveTableName();
  std::string sql = "CREATE TABLE " + tableName +
                    "("
                    "ID INT PRIMARY KEY,"
                    "NAME           TEXT,"
                    "QUANTITY INT,"
                    "PRICE REAL);";

  this->status = sqlite3_exec(db, sql.c_str(), NULL, 0, &messErr);
  if (this->status != SQLITE_OK) {
    std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
    sqlite3_free(messErr);
  } else
    std::cout << "Opened Database Successfully!" << std::endl;
}

void Database::insertNewData() {
  Item item;
  char *errMsg;
  std::string tableName = retrieveTableName();
  item.createItem();

  std::string sql("INSERT INTO " + tableName + " VALUES(" +
                  std::to_string(item.getId()) + ", '" + item.getName() +
                  "', '" + std::to_string(item.getQuantity()) + "', '" +
                  std::to_string(item.getPrice()) + "');");

  this->status = sqlite3_exec(this->db, sql.c_str(), NULL, 0, &errMsg);
  if (this->status != SQLITE_OK) {
    std::cerr << "Error Insert" << std::endl;
    sqlite3_free(errMsg);
  } else
    std::cout << "Records created Successfully!" << std::endl;
}
