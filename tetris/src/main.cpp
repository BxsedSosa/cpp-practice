#include "../lib/movement.cpp"
#include "../lib/shapes.h"
#include "../lib/window.h"
#include <iostream>
#include <raylib.h>

int main() {
  Window window;
  ShapeGrid gridmap;

  window.startWindow();
  int screenWidth = window.getScreenWidth();

  int rectX = screenWidth / 4 * 2 - 60;
  int rectY = 100;

  while (!WindowShouldClose()) {
    playerMovement(rectX, rectY);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(rectX, rectY, 120, 60, RED);
    playerMovement(rectX, rectY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
