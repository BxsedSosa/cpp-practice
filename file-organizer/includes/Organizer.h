#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class Organizer {
private:
  fs::path path;

public:
  fs::path getPath();
  void setPath(fs::path);
  void showPath();
};
