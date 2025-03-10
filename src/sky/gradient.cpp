#include "sky/gradient.h"

namespace sf {

Gradient::Gradient(const Color& up,const Color& down) : up_color(up), down_color(down) {}

Color Gradient::get_color(const Ray& r) const {
  Vec3 unit_direction = r.direction().normalize();
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return down_color * (1.0 - t) + up_color * t;
}

}  // namespace sf