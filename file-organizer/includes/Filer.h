#pragma once

#include "./Creator.h"
#include "./Organizer.h"
#include <vector>

class Filer {
private:
  Creator creator;
  Organizer organizer;
  std::filesystem::path downloadPath;

public:
  void startFiling();
  void moveFiles(std::vector<std::string>);
};
