#pragma once

#include "vec3.h"
#include "point.h"

namespace sf {
class Ray {
 public:
  Ray();

  Ray(const Vec3& origin, const Vec3& direction);

  Point point() const;

  Vec3 direction() const;

  Point at(double t) const;

 private:
  Vec3 origin;
  Vec3 dir;
};
}  // namespace sf