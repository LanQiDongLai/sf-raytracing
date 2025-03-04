#pragma once

#include "color.h"
#include "object/hit_record.h"
#include "ray.h"
#include "material/material.h"

namespace sf {

class Lambertian : public Material {
 public:
  Lambertian(const Color& albedo);

  virtual bool scatter(const Ray& r_in, const HitRecord& rec,
                       Color& attenuation, Ray& scattered) const override;

 private:
  Color albedo;
};

}  // namespace sf