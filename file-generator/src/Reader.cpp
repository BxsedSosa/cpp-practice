#include "../includes/Reader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Reader::getExtensions() {
  std::ifstream f("file-extensions.txt");

  if (!f.is_open()) {
    std::cerr << "Error opening the file!";
  }
  std::string line;

  while (std::getline(f, line)) {
    this->extensions.push_back(line);
  }

  f.close();
}

void Reader::showExtensions() {
  for (int i = 0; i < this->extensions.size(); i++) {
    std::cout << extensions[i] << '\n';
  }
}

std::vector<std::string> Reader::retrieveExtensions() {
  return this->extensions;
}
