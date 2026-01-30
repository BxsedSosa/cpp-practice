#include "../includes/Creator.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::filesystem::path getRootPath() {
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

Creator::Creator() {
  this->startingPath = getRootPath();
  this->docPath = this->startingPath.string() + "Documents/";
  this->downloadPath = this->startingPath.string() + "Downloads/";
  createSavedExtsFile();
  setSavedExts();
}

std::vector<std::string> Creator::getExts() { return this->dirExts; }
std::vector<std::string> Creator::getSavedExts() { return this->savedExts; }
std::filesystem::path Creator::getDownloadPath() { return this->downloadPath; }

void Creator::setDirExts(std::vector<std::string> dirExts) {
  this->dirExts = dirExts;
}

void Creator::setExts(std::filesystem::path path) {
  for (auto dir_entry : std::filesystem::directory_iterator(path)) {
    std::string ext = dir_entry.path().filename().extension();
    this->dirExts.push_back(ext);
  }
}

void Creator::showExts() {
  for (auto ext : this->dirExts) {
    std::cout << "Extension: " << ext << '\n';
  }
}

void Creator::writeSavedExts() {
  std::filesystem::path docFile = this->docPath.string() + this->fileName;
  std::ofstream outputfile(docFile, std::ios::app);

  if (!outputfile) {
    std::cerr << "Failed to open text file!\n";
    return;
  }

  for (std::string ext : this->dirExts) {
    auto doesExists =
        std::find(this->savedExts.begin(), this->savedExts.end(), ext);
    if (doesExists != this->savedExts.end()) {
      continue;
    }
    outputfile << ext << '\n';
  }

  outputfile.close();
}

void Creator::setSavedExts() {
  std::filesystem::path docFile = this->docPath.string() + this->fileName;
  std::string ext;

  if (std::filesystem::exists(docFile)) {
    std::ifstream file(docFile);

    if (!file.is_open()) {
      std::cerr << "Error opening the file!";
      return;
    }

    while (std::getline(file, ext)) {
      this->savedExts.push_back(ext);
    }

    file.close();
  }
}

void Creator::createSavedExtsFile() {
  std::filesystem::path docFile = this->docPath.string() + this->fileName;
  std::ofstream file;
  if (!std::filesystem::exists(docFile)) {
    file.open(this->fileName);

    if (!file.is_open()) {
      std::cout << "Error creating " << this->fileName << '\n';
      return;
    }

    std::cout << "Successfully created txt file!\n";
    file.close();

    try {
      std::filesystem::rename(this->fileName, docFile);
    } catch (std::filesystem::filesystem_error &e) {
      std::cout << e.what() << '\n';
    }
  }
}

void Creator::createExtFolder() {
  for (auto ext : this->dirExts) {
    std::string dirName = ext;
    dirName.erase(0, 1);
    if (!std::filesystem::exists(dirName)) {
      if (dirName != " ") {
        std::filesystem::create_directories(this->downloadPath.string() +
                                            dirName);
      } else {
        std::filesystem::create_directories(this->downloadPath.string() +
                                            "Folder");
      }
    }
  }
}
