#pragma once

#include <filesystem>
#include <vector>

class Creator {
private:
  std::vector<std::string> extensions;

public:
  void setExtensions(std::filesystem::path);
  std::vector<std::string> getExtensions();
  void showExtensions();
};
