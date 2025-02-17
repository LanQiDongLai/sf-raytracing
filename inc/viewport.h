#pragma once
#include "vec3.h"

namespace sf {
class Viewport {
 public:
  Viewport(int width, int height, int focal_length = 1.0);
  ~Viewport();
  Vec3 getPixelPos(int x, int y);
 private:
  int width;
  int height;
  int focal_length;
};
};  // namespace sf
