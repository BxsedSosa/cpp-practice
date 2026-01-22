#include "../includes/Item.h"
#include <cstdlib>
#include <iostream>
#include <string>

void Item::createItem() {
  std::cout << "Enter a item ID: ";
  std::cin >> this->id;
  std::cout << "Enter a item name: ";
  std::cin >> this->name;
  std::cout << "Enter a item quantity: ";
  std::cin >> this->quantity;
  std::cout << "Enter a item price: ";
  std::cin >> this->price;
};

int Item::getId() { return this->id; }
int Item::getQuantity() { return this->quantity; }
int Item::getPrice() { return this->price; }
std::string Item::getName() { return this->name; }
