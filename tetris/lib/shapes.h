#include <raylib.h>
#include <vector>

using namespace std;

class ShapeGrid {
public:
  vector<vector<int>> getGrid(void) { return sqaureMap; }

private:
  vector<vector<int>> sqaureMap = {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
  };
};
