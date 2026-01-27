#pragma once

#include <string>
#include <vector>

class Reader {
private:
  std::vector<std::string> extensions;

public:
  void getExtensions();
  void showExtensions();
};
