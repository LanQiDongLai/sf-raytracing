#pragma once

#include "object/hittable.h"
#include "material/material.h"

namespace sf {

class InfiniteChess : public Hittable {
 public:
  InfiniteChess(float height, float cell_size, std::shared_ptr<Material> material1, std::shared_ptr<Material> material2);
  virtual bool hit(const Ray& r, float ray_tmin, float ray_tmax,
                   HitRecord& rec) const override;
  float height;
  float cell_size;
  std::shared_ptr<Material> material1;
  std::shared_ptr<Material> material2;
};

}  // namespace sf