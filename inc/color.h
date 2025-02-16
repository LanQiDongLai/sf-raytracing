#include "vec3.h"

#include <iostream>

namespace sf {
using Color = Vec3;

std::ostream& operator<<(std::ostream& out, const Color& c) {
  return out << 255 * c.x() << ' ' << 255 * c.y() << ' ' << 255 * c.z();
}

}  // namespace sf
