#pragma once

#include <string>

class Item {
private:
  int id;
  std::string name;
  int quantity;
  double price;

public:
  Item(int, std::string, int, double);
  std::string get_name(int);
  int get_quantity(int);
  int get_price(int);
};
