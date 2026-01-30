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

std::vector<std::string> Organizer::getFileNames() {
  std::vector<std::string> fileNames;
  for (auto dirEntry :
       std::filesystem::directory_iterator(this->downloadPath)) {
    std::string fileName = dirEntry.path().filename();
    fileNames.push_back(fileName);
  }

  return fileNames;
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

  return dirExts;
}
