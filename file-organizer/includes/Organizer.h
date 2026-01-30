#pragma once

#include <filesystem>

class Organizer {
private:
  std::filesystem::path path;
  std::filesystem::path downloadPath;

public:
  Organizer();
  std::filesystem::path getPath();
  void setDownloadPath(std::filesystem::path);
  void setPath(std::filesystem::path);
  void showPath();
  std::vector<std::string> getFileNames();
  std::vector<std::string> getExtsInDir();
};
