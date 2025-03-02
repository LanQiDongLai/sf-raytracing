#include "viewport.h"

namespace sf {
Viewport::Viewport(int width, int height, int focal_length)
    : width(width), height(height), focal_length(focal_length) {}

Viewport::~Viewport() {}

Vec3 Viewport::getPixelPos(double x, double y) {
  return Vec3((x / width * 2 - 1) * width / height, -y / height * 2 + 1, -focal_length);
}

}  // namespace sf