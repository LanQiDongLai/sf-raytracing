#include "material/dielectric.h"

#include "utils/math.h"

namespace sf {

Dielectric::Dielectric(double index_of_refraction)
    : index_of_refraction{index_of_refraction} {}

bool Dielectric::scatter(const Ray& r_in, const HitRecord& rec,
                         Color& attenuation, Ray& scattered) const {
  attenuation = Color(1.0, 1.0, 1.0);

  double ri = rec.front_face ? (1 / index_of_refraction) : index_of_refraction;
  Vec3 unit_direction = r_in.direction().normalize();

  double cos_theta = std::fmin(-unit_direction.dot(rec.normal), 1.0);
  double sin_theta = std::sqrt(1 - cos_theta * cos_theta);
  bool cannot_refract = ri * sin_theta > 1.0;
  Vec3 direction;

  if (cannot_refract || reflectance(cos_theta, ri) > math::random_double(0., 1.)) {
    direction = unit_direction.reflect_by(rec.normal);
  } else {
    direction = unit_direction.refract_by(rec.normal, ri);
  }

  scattered = Ray(rec.p, direction);
  return true;
}

double Dielectric::reflectance(double cosine, double refraction_index) const {
  // Use Schlick's approximation for reflectance.
  auto r0 = (1 - refraction_index) / (1 + refraction_index);
  r0 = r0 * r0;
  return r0 + (1 - r0) * pow((1 - cosine), 5);
}
}  // namespace sf
