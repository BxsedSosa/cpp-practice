#include "../includes/Database.h"
#include <sqlite3.h>

std::string Database::retrieveTableName() {
  std::string tableName;
  std::cin >> tableName;
  return tableName;
}

void Database::createNewTable(std::string tableName) {
  std::string sql = "CREATE TABLE " + tableName +
                    "("
                    "ID INT PRIMARY KEY,"
                    "NAME           TEXT,"
                    "QUANTITY INT,"
                    "PRICE REAL);";
  char *messErr;
  exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messErr);

  if (this->exit != SQLITE_OK) {
    std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
    sqlite3_free(messErr);
  } else
    std::cout << "Opened Database Successfully!" << std::endl;
}
