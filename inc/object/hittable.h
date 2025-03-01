#pragma once
#include "object/hit_record.h"
#include "ray.h"

namespace sf {

class Hittable {
 public:
  virtual bool hit(const Ray& r, float t_min, float t_max,
                   HitRecord& rec) const = 0;
};

}  // namespace sf
