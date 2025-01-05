#include <raylib.h>
#include <vector>

using namespace std;

class Window {
public:
  void startWindow(void) {
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);
  }

  int getScreenWidth() { return screenWidth; }
  int getHalfScreenWidth() { return screenWidth / 2; }
  int getScreenHeight() { return screenHeight; }
  int getHalfScreenHeight() { return screenHeight / 2; }

private:
  const int screenHeight = 720;
  const int screenWidth = 1280;
};
