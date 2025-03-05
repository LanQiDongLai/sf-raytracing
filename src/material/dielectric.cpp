#include "material/dielectric.h"

namespace sf {

Dielectric::Dielectric(double index_of_refraction)
    : index_of_refraction{index_of_refraction} {}

bool Dielectric::scatter(const Ray& r_in, const HitRecord& rec,
                         Color& attenuation, Ray& scattered) const {
  attenuation = Color(1.0, 1.0, 1.0);
  double etai_over_etat =
      rec.front_face ? (1.0 / index_of_refraction) : index_of_refraction;

  Vec3 unit_direction = r_in.direction().normalize();
  scattered = Ray(rec.p, unit_direction.refract_by(rec.normal, etai_over_etat));
  return true;
}
}  // namespace sf
