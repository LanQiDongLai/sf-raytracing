#pragma once

#include "material/material.h"

namespace sf {

class Metal : public Material {
 public:
  Metal(const Color& albedo, double fuzz = 0.0);

  virtual bool scatter(const Ray& r_in, const HitRecord& rec,
                       Color& attenuation, Ray& scattered) const override;

 private:
  Color albedo;
  double fuzz;
};

}  // namespace sf