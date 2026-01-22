#include "../includes/Item.h"
#include <string>

Item::Item(int id, std::string name, int quantity, double price) {
  this->id = id;
  this->name = name;
  this->quantity = quantity;
  this->price = price;
};

std::string Item::get_name(int id) { return this->name; }
int Item::get_quantity(int id) { return this->quantity; }
int Item::get_price(int id) { return this->price; }
