#include "vec3.h"

#include <cmath>

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

double Vec3::length() const {
  return sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]);
}

double Vec3::length_squared() const {
  return data[0] * data[0] + data[1] * data[1] + data[2] * data[2];
}
}  // namespace sf
