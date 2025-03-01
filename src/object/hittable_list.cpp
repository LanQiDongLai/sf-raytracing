#include "object/hittable_list.h"

namespace sf {

HittableList::HittableList() {
}

void HittableList::add(std::shared_ptr<Hittable> object) {
  this->objects.push_back(object);
}

bool HittableList::hit(const Ray& r, float ray_tmin, float ray_tmax,
                       HitRecord& rec) const {
  HitRecord temp_rec;
  bool hit_anything = false;
  auto closest_so_far = ray_tmax;

  for (const auto& object : objects) {
    if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }

  return hit_anything;
}
}  // namespace sf