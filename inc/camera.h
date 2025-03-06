#pragma once
#include "color.h"
#include "object/hittable.h"
#include "ray.h"
#include "surface.h"
#include "viewport.h"

namespace sf {

class Camera {
 public:
  Camera();
  void render(const Hittable& world);

  void setPosition(const Point& pos);
  void setLookat(const Point& lookat);
  void setUp(const Vec3& up);

 private:
  Color ray_color(const Ray& r, int depth, const Hittable& world);

  Ray get_ray(int j, int i);

  Color sample_on_pixel(int j, int i, const Hittable& world);

  Color gamma_correction(const Color& color);
  Viewport viewport;
  Surface surface;
  static const int surface_width;
  static const int surface_height;
  static const int samples_per_pixel;
  static const int max_depth;
  Point position;
  Point lookat;
  Vec3 up;
};

}  // namespace sf