#include "../includes/Creator.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::filesystem::path getDocPath() {
  int count = 0;
  std::string currPath = std::filesystem::current_path();

  for (int i = 0; i < currPath.size(); i++) {
    if (currPath[i] == '/') {
      count++;
    }
    if (count == 3) {
      currPath.erase(i + 1, currPath.size());
    }
  }

  return currPath;
}

Creator::Creator() { this->docPath = getDocPath().string() + "Documents/"; }

void Creator::setExts(std::filesystem::path path) {
  for (auto dir_entry : std::filesystem::directory_iterator(path)) {
    std::string ext = dir_entry.path().filename().extension();
    this->dirExts.push_back(ext);
  }
}

std::vector<std::string> Creator::getExts() { return this->dirExts; }

void Creator::showExts() {
  for (auto ext : this->dirExts) {
    std::cout << "Extension: " << ext << '\n';
  }
}

std::vector<std::string> Creator::getSavedExts() {
  std::vector<std::string> savedExts;

  return savedExts;
}

void Creator::setSavedExt() {}

void Creator::createSavedExtsFile() {
  std::ofstream file;
  file.open(this->fileName);

  if (!file.is_open()) {
    std::cout << "Error creating " << this->fileName << '\n';
    return;
  }

  std::cout << "Created " << this->fileName << " Successfully\n";
  file.close();

  try {
    std::filesystem::rename(this->fileName,
                            this->docPath.string() + this->fileName);
  } catch (std::filesystem::filesystem_error &e) {
    std::cout << e.what() << '\n';
  }
}

// bool Creator::isSavedExtFileCreated() {}
