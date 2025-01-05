#include <raylib.h>

void playerMovement(int &xCorr, int &yCorr) {
  if (IsKeyDown(KEY_RIGHT))
    xCorr += 1;
  if (IsKeyDown(KEY_LEFT))
    xCorr -= 1;
  if (IsKeyDown(KEY_UP))
    yCorr -= 1;
  if (IsKeyDown(KEY_DOWN))
    yCorr += 1;
}

int main() {
  const int screenHeight = 720;
  const int screenWidth = 1280;
  int rectX = screenWidth / 4 * 2 - 60;
  int rectY = 100;

  InitWindow(screenWidth, screenHeight, "Tetris");

  SetTargetFPS(60);

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
