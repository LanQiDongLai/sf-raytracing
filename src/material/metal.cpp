#include "material/metal.h"

namespace sf{

Metal::Metal(const Color& albedo) : albedo(albedo) {}

bool Metal::scatter(const Ray& r_in, const HitRecord& rec,
  Color& attenuation, Ray& scattered) const {
  Vec3 reflected = r_in.direction().reflect_by(rec.normal);
  scattered = Ray(rec.p, reflected);
  attenuation = albedo;
  return (scattered.direction().dot(rec.normal) > 0);
}

}