#pragma once

#include "color.h"
#include "ray.h"

namespace sf {

class Sky {
 public:
  virtual Color get_color(const Ray& r) const = 0;
};

}  // namespace sf