#pragma once
#include <memory>
#include <vector>

#include "object/hittable.h"

namespace sf {

class HittableList : public Hittable {
 public:
  HittableList();
  void add(std::shared_ptr<Hittable> object);
  bool hit(const Ray& r, float t_min, float t_max,
           HitRecord& rec) const override;

 private:
  std::vector<std::shared_ptr<Hittable>> objects;
};

}  // namespace sf
