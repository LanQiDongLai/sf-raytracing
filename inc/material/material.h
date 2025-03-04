#pragma once

#include "ray.h"
#include "object/hit_record.h"
#include "color.h"

namespace sf {

class Material {
 public:
  virtual bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation,
                       Ray& scattered) const = 0;
};

}