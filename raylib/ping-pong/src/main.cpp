#include <raylib.h>

#include "../includes/Ball.h"

#define SCRN_HEIGHT 600
#define SCRN_WIDTH 900

int main() {
  Ball ball({float(SCRN_WIDTH / 2), float(SCRN_HEIGHT / 2)}, 10, WHITE);
  InitWindow(SCRN_WIDTH, SCRN_HEIGHT, "Ping Pong");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    ball.movement();

    BeginDrawing();
    ClearBackground(BLACK);
    ball.draw();

    EndDrawing();
  }
  return 0;
}
