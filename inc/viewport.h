#pragma once
#include "vec3.h"

namespace sf {
class Viewport {
 public:
  Viewport(int width, int height);
  ~Viewport();
  void setFocalLength(double focal_length);
  Vec3 getPixelPos(int x, int y);
 private:
  int width;
  int height;
};
};  // namespace sf
