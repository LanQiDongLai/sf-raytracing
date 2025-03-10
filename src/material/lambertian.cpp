#include "material/lambertian.h"

namespace sf {

Lambertian::Lambertian(const Color& albedo) : albedo(albedo) {}

MaterialType Lambertian::scatter(const Ray& r_in, const HitRecord& rec,
                         Color& attenuation, Ray& scattered) const {
  Vec3 scatter_direction = rec.normal + Vec3::random_in_unit_sphere();
  if(scatter_direction.length() < 0.001) {
    scatter_direction = rec.normal;
  }
  scattered = Ray(rec.p, scatter_direction);
  attenuation = albedo;
  return MaterialType::NonLuminous;
}

}  // namespace sf