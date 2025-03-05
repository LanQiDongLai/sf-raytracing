#include "vec3.h"
#include "utils/math.h"

#include <cmath>
#include <numbers>

namespace sf {
Vec3::Vec3(double x, double y, double z) : data{x, y, z} {}

Vec3::Vec3() : data{0, 0, 0} {}

double Vec3::x() const { return data[0]; }
double Vec3::y() const { return data[1]; }
double Vec3::z() const { return data[2]; }

Vec3 Vec3::operator-() const { return Vec3(-data[0], -data[1], -data[2]); }

double Vec3::operator[](int i) const { return data[i]; }

double& Vec3::operator[](int i) { return data[i]; }

Vec3& Vec3::operator+=(const Vec3& v) {
  data[0] += v.data[0];
  data[1] += v.data[1];
  data[2] += v.data[2];
  return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) { return *this += -v; }

Vec3& Vec3::operator*=(double t) {
  data[0] *= t;
  data[1] *= t;
  data[2] *= t;
  return *this;
}

Vec3& Vec3::operator/=(double t) { return *this *= 1 / t; }

Vec3 Vec3::operator+(const Vec3& v) const {
  return Vec3(data[0] + v.data[0], data[1] + v.data[1], data[2] + v.data[2]);
}

Vec3 Vec3::operator-(const Vec3& v) const {
  return Vec3(data[0] - v.data[0], data[1] - v.data[1], data[2] - v.data[2]);
}

Vec3 Vec3::operator*(const Vec3& v) const {
  return Vec3(data[0] * v.data[0], data[1] * v.data[1], data[2] * v.data[2]);
}

Vec3 Vec3::operator/(const Vec3& v) const {
  return Vec3(data[0] / v.data[0], data[1] / v.data[1], data[2] / v.data[2]);
}

Vec3 Vec3::operator*(double t) const {
  return Vec3(t * data[0], t * data[1], t * data[2]);
}

Vec3 Vec3::operator/(double t) const {
  return Vec3(data[0] / t, data[1] / t, data[2] / t);
}

Vec3& Vec3::operator=(const Vec3& v) {
  data[0] = v.data[0];
  data[1] = v.data[1];
  data[2] = v.data[2];
  return *this;
}

Vec3 Vec3::cross(const Vec3& v) const {
  return Vec3(data[1] * v.data[2] - data[2] * v.data[1],
              data[2] * v.data[0] - data[0] * v.data[2],
              data[0] * v.data[1] - data[1] * v.data[0]);
}

double Vec3::dot(const Vec3& v) const {
  return data[0] * v.data[0] + data[1] * v.data[1] + data[2] * v.data[2];
}

Vec3 Vec3::normalize() const {
  return Vec3(data[0] / length(), data[1] / length(), data[2] / length());
}

Vec3 Vec3::random_in_unit_sphere() {
  double u = math::random_double(0., 1.);
  double v = math::random_double(0., 1.);
  double theta = std::acos(1 - 2 * u);
  double phi = 2 * std::numbers::pi * v;
  double x = std::sin(theta) * std::cos(phi);
  double y = std::sin(theta) * std::sin(phi);
  double z = std::cos(theta);
  return Vec3(x, y, z);
}

Vec3 Vec3::reflect_by(const Vec3& n) const {
  return *this - n * 2 * this->dot(n);
}

Vec3 Vec3::refract_by(const Vec3& n, double etai_over_etat) const {
  double cos_theta = -this->dot(n);
  Vec3 r_out_parallel = (*this + n * cos_theta) * etai_over_etat;
  Vec3 r_out_perp = -n * std::sqrt(1.0 - r_out_parallel.length_squared());
  return r_out_parallel + r_out_perp;
}

double Vec3::length() const {
  return sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]);
}

double Vec3::length_squared() const {
  return data[0] * data[0] + data[1] * data[1] + data[2] * data[2];
}
}  // namespace sf
