#pragma once

#include <random>

namespace sf {
namespace math {

double clamp(double x, double t_min, double t_max);

bool in_range(double x, double t_min, double t_max);

double random_double(double t_min, double t_max);

double radians_to_degrees(double radians);

double degrees_to_radians(double degrees);

}  // namespace math

}  // namespace sf