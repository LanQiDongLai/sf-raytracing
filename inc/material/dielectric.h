#pragma once

#include "material/material.h"

namespace sf {

class Dielectric : public Material {
 public:
  Dielectric(double index_of_refraction);
  virtual bool scatter(const Ray& r_in, const HitRecord& rec,
                       Color& attenuation, Ray& scattered) const override;

 private:
  double reflectance(double cosine, double refraction_index) const;
  double index_of_refraction;
};

}  // namespace sf