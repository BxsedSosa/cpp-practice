#include "../lib/movement.cpp"
#include "../lib/shapes.h"
#include "../lib/window.h"
#include <raylib.h>
void createPlayArea(int screenWidth, int screenHeight) {
  int squareSize = 40;
  int playAreaWidth = 10;
  int playAreaHeight = 20;

  Vector2 offset;
  offset.x = screenWidth / 2 - (playAreaWidth * squareSize / 2) - 50;
  offset.y = screenHeight / 2 - ((playAreaHeight - 1) * squareSize / 2) +
             squareSize * 2;

  offset.y -= 50; // NOTE: Harcoded position!
  int controller = offset.x;

  for (int y = 0; y < playAreaHeight; y++) {
    for (int x = 0; x < playAreaWidth; x++) {
      DrawLine(offset.x, offset.y, offset.x + squareSize, offset.y, LIGHTGRAY);
      DrawLine(offset.x, offset.y, offset.x, offset.y + squareSize, LIGHTGRAY);
      DrawLine(offset.x + squareSize, offset.y, offset.x + squareSize,
               offset.y + squareSize, LIGHTGRAY);
      DrawLine(offset.x, offset.y + squareSize, offset.x + squareSize,
               offset.y + squareSize, LIGHTGRAY);
      offset.x += squareSize;
    }
  }
}

int main() {
  Window window;
  ShapeGrid gridmap;

  window.startWindow();
  int screenWidth = window.getScreenWidth();
  int screenHeight = window.getScreenHeight();

  int rectX = screenWidth / 4 * 2 - 60;
  int rectY = 100;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    createPlayArea(screenWidth, screenHeight);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
