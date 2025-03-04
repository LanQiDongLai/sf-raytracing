#pragma once
#include "point.h"
#include "ray.h"
#include <memory>

namespace sf {

class Material;

struct HitRecord {
  float t;
  Point p;
  Vec3 normal;
  std::shared_ptr<Material> material;
  bool front_face;
  void set_face_normal(const Ray& r, const Vec3& outward_normal);
};
}  // namespace sf