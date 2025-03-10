#include "sky/monochrome.h"

namespace sf {

Monochrome::Monochrome(const Color& color) : color(color) {}

Color Monochrome::get_color(const Ray& r) const {
  return color;
}

}  // namespace sf