#include <mysql_connection.h>
#include <mysql_driver.h>

int main() {
  sql::mysql::MySQL_Driver *driver;
  sql::Connection *con;

  // Initialize MySQL driver instance
  driver = sql::mysql::get_mysql_driver_instance();
  // Connect to the database
  con = driver->connect("tcp://127.0.0.1:3306", "user", "password");

  // Clean-up
  delete con;
  return 0;
}
