#pragma once

#include <filesystem>
#include <vector>

class Creator {
private:
  std::string fileName = "saved_extension.txt";
  std::filesystem::path startingPath;
  std::filesystem::path downloadPath;
  std::filesystem::path docPath;
  std::vector<std::string> savedExts;
  std::vector<std::string> dirExts;

public:
  Creator();
  void setExts(std::filesystem::path);
  void setSavedExts();
  void setDirExts(std::vector<std::string>);
  std::filesystem::path getDownloadPath();
  std::vector<std::string> getSavedExts();
  std::vector<std::string> getExts();
  void writeSavedExts();
  void showExts();
  void createSavedExtsFile();
  void createExtFolder();
};
