#pragma once

#include "material/material.h"

namespace sf {

class Luminous : public Material {
 public:
  Luminous(const Color& albedo);

  virtual MaterialType scatter(const Ray& r_in, const HitRecord& rec,
                       Color& attenuation, Ray& scattered) const override;

 private:
  Color albedo;
};

}  // namespace sf