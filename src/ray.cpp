#include "ray.h"

namespace sf {
Ray::Ray() : origin{0, 0, 0}, dir{0, 0, 0} {}
Ray::Ray(const Vec3& origin, const Vec3& direction) : origin{origin}, dir{direction} {}

Point Ray::point() const { return origin; }

Vec3 Ray::direction() const { return dir; }

Point Ray::at(double t) const { return origin + dir * t; }

}  // namespace sf