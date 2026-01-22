#pragma once

#include <string>

class Item {
private:
  int id;
  std::string name;
  int quantity;
  double price;

public:
  void createItem();
  int getId();
  std::string getName();
  int getQuantity();
  int getPrice();
};
