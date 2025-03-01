#include "object/hit_record.h"

namespace sf {
void HitRecord::set_face_normal(const Ray& r, const Vec3& outward_normal) {
  front_face = r.direction().dot(outward_normal) < 0;
  normal = front_face ? outward_normal : -outward_normal;
}
}  // namespace sf