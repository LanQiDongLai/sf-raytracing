#pragma once
#include "vec3.h"

namespace sf {
class Viewport {
 public:
  Viewport(int width, int height, int focal_length = 1.0);
  ~Viewport();
  Vec3 getPixelPos(double x, double y);
 private:
  int width;
  int height;
  int focal_length;
};
};  // namespace sf
