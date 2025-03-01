#pragma once
#include "object/hittable.h"
#include "viewport.h"
#include "surface.h"
#include "color.h"
#include "ray.h"

namespace sf {

class Camera {
 public:
  Camera();
  void render(const Hittable& world);

 private:
  Color Camera::ray_color(const Ray& r, const Hittable& world);

  Viewport viewport;
  Surface surface;
  static const int surface_width;
  static const int surface_height;
};

}