#include "../includes/Filer.h"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <vector>

void printFilePath(std::filesystem::path filePath) {
  std::cout << "NEW FILE PATH: " << filePath << '\n';
}

void Filer::startFiling() {
  this->organizer.setDownloadPath(this->creator.getDownloadPath());
  this->creator.setDirExts(this->organizer.getExtsInDir());
  this->creator.writeSavedExts();
  this->creator.createExtFolder();
  this->downloadPath = this->creator.getDownloadPath();
  moveFiles(this->organizer.getFileNames());
}

void Filer::moveFiles(std::vector<std::string> fileNames) {
  std::vector<std::string> savedExts = this->creator.getSavedExts();
  for (std::string fileName : fileNames) {
    std::filesystem::path filePath = this->downloadPath.string() + fileName;
    std::string extDirName = filePath.extension();
    extDirName.erase(0, 1);

    auto doesExists = std::find(savedExts.begin(), savedExts.end(), extDirName);
    if (doesExists != savedExts.end()) {
      continue;
    }

    if (extDirName == "") {
      std::filesystem::path newFilePath =
          this->downloadPath.string() + "Folders/" + fileName;
      std::filesystem::rename(filePath, newFilePath);
    } else {
      std::filesystem::path newFilePath =
          this->downloadPath.string() + extDirName + "/" + fileName;
      std::filesystem::rename(filePath, newFilePath);
    }
  }
}
