#include "../includes/Organizer.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

fs::path Organizer::getPath() { return this->path; }

void Organizer::setPath(fs::path path) { this->path = path; }

void Organizer::showPath() {
  std::cout << "Current Path: " << this->path << '\n';
}
