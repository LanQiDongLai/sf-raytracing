#pragma once

#include "sky/sky.h"

namespace sf {

class Monochrome : public Sky {
 public:
  Monochrome(const Color& color);
  Color get_color(const Ray& r) const override;

 private:
  Color color;
};

}  // namespace sf
