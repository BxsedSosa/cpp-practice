#include "../includes/Organizer.h"
#include <filesystem>

int main() {
  Organizer organizer;
  std::filesystem::path currPath = std::filesystem::current_path();

  organizer.setPath(currPath);
  organizer.showPath();

  return 0;
}
