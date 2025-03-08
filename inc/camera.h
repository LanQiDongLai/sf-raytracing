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

  void setMaxDepth(int max_depth);
  void setAspectRadio(double aspect_radio);
  void setFov(double fov);
  void setMultiSample(int samples_per_pixel);

 private:
  void init();

  Color ray_color(const Ray& r, int depth, const Hittable& world);

  Ray get_ray(double j, double i);

  Color sample_on_pixel(double j, double i, const Hittable& world);

  Color gamma_correction(const Color& color);
  // 考虑从外部传入，并修改 Surface 的构造函数
  int surface_height;
  double aspect_ratio;
  int surface_width;
  
  int samples_per_pixel;
  int max_depth;
  double fov;
  double focal_length;
  
  Point position;
  Point lookat;
  Vec3 up;

  Surface surface;

  Viewport viewport;
};

}  // namespace sf