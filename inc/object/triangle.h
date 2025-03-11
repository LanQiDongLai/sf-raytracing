#pragma once

#include "object/hittable.h"
#include "material/material.h"
#include "point.h"

namespace sf {

class Triangle : public Hittable {
 public:
  Triangle(Point v0, Point v1, Point v2, std::shared_ptr<Material> material);
  virtual bool hit(const Ray& r, float ray_tmin, float ray_tmax,
                   HitRecord& rec) const override;
  Point v0, v1, v2;
  std::shared_ptr<Material> material;
};

}  // namespace sf