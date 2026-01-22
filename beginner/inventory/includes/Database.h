#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string>

class Database {
private:
  int exit;

public:
  sqlite3 *db;
  std::string retrieveTableName();
  void createNewTable(std::string);
};
