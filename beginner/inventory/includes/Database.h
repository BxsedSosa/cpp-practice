#pragma once

#include <iostream>
#include <sqlite3.h>
#include <string>

class Database {
private:
public:
  int status = 0;
  sqlite3 *db;
  void createNewTable();
  void insertNewData();
  void displayTable();
  void deleteRow();
};
