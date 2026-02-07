#include "../includes/Circle.h"
#include "../includes/Square.h"
#include <raylib.h>

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

int main() {
  Circle circle(100.0, 100.0, 30.0);
  Square floor(0, 500.0, 800.0, 100.0);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "idk");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    circle.drag();

    BeginDrawing();
    ClearBackground(WHITE);
    DrawRectangleV(floor.getPos(), floor.getSize(), RED);
    DrawCircleV(circle.getVec(), circle.getRadius(), BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
