#pragma once

#include "ray.h"
#include "object/hit_record.h"
#include "color.h"

namespace sf {

enum class MaterialType {
  Luminous,
  NonLuminous,
  BlackHole,
};

class Material {
 public:
  virtual MaterialType scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation,
                       Ray& scattered) const = 0;
};

}