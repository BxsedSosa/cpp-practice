#include "../includes/Creator.h"
#include "../includes/Organizer.h"
#include <filesystem>

int main() {
  Organizer organizer;
  Creator creator;
  std::filesystem::path currPath = std::filesystem::current_path();

  organizer.setPath(currPath);
  creator.setExtensions(organizer.getPath());
  creator.showExtensions();

  return 0;
}
