#pragma once
#include "color.h"
#include "object/hittable.h"
#include "ray.h"
#include "surface.h"
#include "viewport.h"
#include "sky/sky.h"

namespace sf {

class Camera {
 public:
  Camera();
  void render(const Hittable& world);

  void setPosition(const Point& pos);
  void setLookat(const Point& lookat);
  void setUp(const Vec3& up);

  void setMaxDepth(int max_depth);
  void setSurfaceHeight(int height);
  void setAspectRadio(double aspect_radio);
  void setFov(double fov);
  void setMultiSample(int samples_per_pixel);
  void setDefocusAngle(double defocus_angle);
  void setFocusDist(double focus_dist);
  void setSky(std::shared_ptr<Sky> sky);

 private:
  void init();

  Color ray_color(const Ray& r, int depth, const Hittable& world);

  Ray get_ray(double j, double i);

  Color sample_on_pixel(double j, double i, const Hittable& world);

  Color gamma_correction(const Color& color);

  int surface_height;
  double aspect_ratio;
  int surface_width;
  
  int samples_per_pixel;
  int max_depth;
  double fov;
  double focus_dist;
  double defocus_angle;
  
  Point position;
  Point lookat;
  Vec3 up;
  Vec3 right;
  Vec3 front;

  Viewport viewport;

  std::shared_ptr<Sky> sky;
};

}  // namespace sf