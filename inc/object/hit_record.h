#pragma once
#include "point.h"
#include "ray.h"

namespace sf {
struct HitRecord {
  float t;
  Point p;
  Vec3 normal;
  bool front_face;
  void set_face_normal(const Ray& r, const Vec3& outward_normal);
};
}  // namespace sf