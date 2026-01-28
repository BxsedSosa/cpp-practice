#include "../includes/Creator.h"
#include "../includes/Organizer.h"
#include <iostream>

int main() {
  Organizer organizer;
  Creator creator;

  for (auto ext : creator.getSavedExts()) {
    std::cout << "EXT: " << ext << '\n';
  }

  return 0;
}
