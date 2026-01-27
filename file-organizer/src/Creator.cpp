#include "../includes/Creator.h"
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

void Creator::setExtensions(std::filesystem::path path) {
  for (auto dir_entry : std::filesystem::directory_iterator(path)) {
    std::string ext = dir_entry.path().filename().extension();
    this->extensions.push_back(ext);
  }
}

std::vector<std::string> Creator::getExtensions() { return this->extensions; }

void Creator::showExtensions() {
  for (auto ext : this->extensions) {
    std::cout << "Extension: " << ext << '\n';
  }
}
