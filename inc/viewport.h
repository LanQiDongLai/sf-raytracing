#pragma once
#include "vec3.h"

namespace sf {
class Viewport {
 public:
  Viewport();
  Viewport(double width, double height, double focal_length = 1.0);
  ~Viewport();
  Vec3 getPixelPos(double x, double y);
  void setWidth(double width);
  void setHeight(double height);
  void setFocalLength(double focal_length);
  double getWidth() const;
  double getHeight() const;
  double getFocalLength() const;
 private:
  double width;
  double height;
  double focal_length;
};
};  // namespace sf
