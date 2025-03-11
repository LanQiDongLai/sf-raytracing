#include "object/triangle.h"

namespace sf {

Triangle::Triangle(Point v0, Point v1, Point v2,
                   std::shared_ptr<Material> material)
    : v0(v0), v1(v1), v2(v2), material(material) {}

bool Triangle::hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const {
  Vec3 e1 = v1 - v0;
  Vec3 e2 = v2 - v0;
  Vec3 h = r.direction().cross(e2);
  auto a = e1.dot(h);
  if (a > -1e-6 && a < 1e-6) return false;
  auto f = 1.0 / a;
  Vec3 s = r.point() - v0;
  auto u = f * s.dot(h);
  if (u < 0.0 || u > 1.0) return false;
  Vec3 q = s.cross(e1);
  auto v = f * r.direction().dot(q);
  if (v < 0.0 || u + v > 1.0) return false;
  auto t = f * e2.dot(q);
  if (t > t_min && t < t_max) {
    rec.t = t;
    rec.p = r.at(t);
    rec.normal = e1.cross(e2).normalize();
    rec.material = material;
    return true;
  }
  return false;
}

}  // namespace sf