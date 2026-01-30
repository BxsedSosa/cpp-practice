#include "../includes/Creator.h"
#include "../includes/Organizer.h"

int main() {
  Organizer organizer;
  Creator creator;

  organizer.setDownloadPath(creator.getDownloadPath());
  creator.setDirExts(organizer.getExtsInDir());
  creator.writeSavedExts();
  creator.createExtFolder();

  return 0;
}
