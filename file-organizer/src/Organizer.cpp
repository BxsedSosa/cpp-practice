#include "../includes/Organizer.h"
#include <algorithm>
#include <filesystem>
#include <iostream>

Organizer::Organizer() {}

std::filesystem::path Organizer::getPath() { return this->path; }
void Organizer::setDownloadPath(std::filesystem::path path) {
  this->downloadPath = path;
}
void Organizer::setPath(std::filesystem::path path) { this->path = path; }

void Organizer::showPath() {
  std::cout << "Current Path: " << this->path << '\n';
}

void Organizer::showFilesInDir() {
  for (auto dirEntry :
       std::filesystem::directory_iterator(this->downloadPath)) {
    std::string ext = dirEntry.path().filename().extension();
    std::string fileName = dirEntry.path().filename();

    std::cout << "File: " << fileName << "\nExtension: " << ext << '\n';
  }
}

std::vector<std::string> Organizer::getExtsInDir() {
  std::vector<std::string> dirExts;
  for (auto dirEntry :
       std::filesystem::directory_iterator(this->downloadPath)) {
    std::string ext = dirEntry.path().filename().extension();
    auto doesExists = std::find(dirExts.begin(), dirExts.end(), ext);
    if (doesExists != dirExts.end()) {
      continue;
    } else {
      dirExts.push_back(ext);
    }
  }

  for (auto ext : dirExts) {
    std::cout << "DOWN EXT: " << ext << '\n';
  }
  return dirExts;
}
