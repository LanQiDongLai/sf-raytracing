#pragma once
#include <cmath>

#include "object/hittable.h"
#include "point.h"
#include "ray.h"

namespace sf {
class Sphere : public Hittable {
 public:
  Sphere(Point center, double radius);
  bool hit(const Ray& r, float ray_tmin, float ray_tmax,
           HitRecord& rec) const override;

 private:
  Point center;
  double radius;
};
}  // namespace sf
