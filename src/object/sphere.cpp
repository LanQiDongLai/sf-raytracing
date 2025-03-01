#include "object/sphere.h"

namespace sf {
Sphere::Sphere(Point center, double radius) : center(center), radius(radius) {}
bool Sphere::hit(const Ray& r, float ray_tmin, float ray_tmax,
                 HitRecord& rec) const {
  Vec3 oc = r.point() - center;
  auto a = r.direction().length_squared();
  auto half_b = oc.dot(r.direction());
  auto c = oc.length_squared() - radius * radius;

  auto discrimiant = half_b * half_b - a * c;
  if (discrimiant < 0) {
    return false;
  }
  auto sqrtd = std::sqrt(discrimiant);

  auto root = (-half_b - sqrtd) / a;
  if (root <= ray_tmin || root >= ray_tmax) {
    root = (-half_b + sqrtd) / a;
    if (root <= ray_tmin || root >= ray_tmax) {
      return false;
    }
  }

  rec.t = root;
  rec.p = r.at(rec.t);
  rec.normal = (rec.p - center) / radius;

  rec.set_face_normal(r, rec.normal);
  return true;
}
}  // namespace sf