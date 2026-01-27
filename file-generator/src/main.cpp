#include "../includes/Maker.h"
#include "../includes/Reader.h"

int main() {
  Reader reader;
  Maker maker;
  reader.getExtensions();
  maker.createDirectory();
  maker.createFiles(reader.retrieveExtensions(), 5);
  return 0;
}
