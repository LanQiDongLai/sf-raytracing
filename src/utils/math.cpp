#include "utils/math.h"
#include <numbers>
#include "math.h"

namespace sf {
namespace math {

double clamp(double x, double t_min, double t_max) {
  if (x < t_min) {
    return t_min;
  }
  if (x > t_max) {
    return t_max;
  }
  return x;
}

bool in_range(double x, double t_min, double t_max) {
  if (x >= t_min && x <= t_max) {
    return true;
  }
  return false;
}

double random_double(double t_min, double t_max) {
  std::random_device device;
  std::default_random_engine engine(device());
  std::uniform_real_distribution<double> uniform_dist(t_min, t_max);
  return uniform_dist(engine);
}

double radians_to_degrees(double radians) {
  return radians * 180 / std::numbers::pi;
}

double degrees_to_radians(double degrees) {
  return degrees * std::numbers::pi / 180;
}

}  // namespace math
}  // namespace sf