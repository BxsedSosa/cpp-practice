#include "../includes/Maker.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Maker::createFiles(std::vector<std::string> fileExts, int times) {
  for (int k = 0; k < times; k++) {
    for (int i = 0; i < fileExts.size(); i++) {
      std::ofstream file;
      std::string fileName = "testing/test" + std::to_string(k) + fileExts[i];
      file.open(fileName);

      if (!file.is_open()) {
        std::cout << "Error creating " << fileName << '\n';
        break;
      }

      std::cout << "Created " << fileName << "Successfully\n";
      file.close();
    }
  }
}

void Maker::createDirectory() {
  std::filesystem::path currPath = std::filesystem::current_path();
  std::filesystem::path newPath = currPath / "testing";

  bool is_dir = std::filesystem::is_directory(newPath);

  if (is_dir) {
    std::cout << "This directory already exisit!\n";
  } else {
    std::cout << "Creating new directory\n";
    std::filesystem::create_directory(newPath);
  }
}
