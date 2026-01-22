#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string>

class Database {
private:
  sqlite3 *db;
  int exit;

public:
  std::string retrieveTableName();
  void createNewTable(std::string);
};
