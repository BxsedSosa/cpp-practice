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
