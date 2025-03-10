#include "material/metal.h"

namespace sf{

Metal::Metal(const Color& albedo, double fuzz) : albedo(albedo), fuzz(fuzz) {}

MaterialType Metal::scatter(const Ray& r_in, const HitRecord& rec,
  Color& attenuation, Ray& scattered) const {
  Vec3 reflected = r_in.direction().reflect_by(rec.normal).normalize() + Vec3::random_in_unit_sphere() * fuzz;
  scattered = Ray(rec.p, reflected);
  attenuation = albedo;
  return (scattered.direction().dot(rec.normal) > 0 ? MaterialType::NonLuminous : MaterialType::BlackHole);
}

}