#include "material/luminous.h"

namespace sf {


Luminous::Luminous(const Color& albedo) : albedo(albedo) {}

MaterialType Luminous::scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation,
                       Ray& scattered) const {
  attenuation = albedo;
  return MaterialType::Luminous;
}

}