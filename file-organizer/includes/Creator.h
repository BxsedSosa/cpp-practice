#pragma once

#include <filesystem>
#include <vector>

class Creator {
private:
  std::string fileName = "saved_extension.txt";
  std::filesystem::path docPath;
  std::vector<std::string> savedExts;
  std::vector<std::string> dirExts;

public:
  Creator();
  void setExts(std::filesystem::path);
  void setSavedExt();
  std::vector<std::string> getSavedExts();
  std::vector<std::string> getExts();
  void showExts();
  void createSavedExtsFile();
  bool isSavedExtFileCreated();
};
