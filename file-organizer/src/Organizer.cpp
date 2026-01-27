#include "../includes/Organizer.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

fs::path Organizer::getPath() { return this->path; }

void Organizer::setPath(fs::path path) { this->path = path; }

void Organizer::showPath() {
  std::cout << "Current Path: " << this->path << '\n';
}

void Organizer::showFilesInDir() {
  for (auto dir_entry : fs::directory_iterator(this->path)) {
    std::string ext = dir_entry.path().filename().extension();
    std::string fileName = dir_entry.path().filename();

    std::cout << "File: " << fileName << "\nExtension: " << ext << '\n';
  }
}
