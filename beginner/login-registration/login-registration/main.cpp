#include <iostream>

#include "../mongo-cred.cpp"

int main() {
  extern credentials;

  std::cout << credentials.name << '\n';
  std::cout << "hello world'\n";

  return 0;
}
