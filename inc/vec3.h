#pragma once

namespace sf {
class Vec3 {
 public:
  Vec3();
  Vec3(double x, double y, double z);

  double x() const;
  double y() const;
  double z() const;

  Vec3 operator-() const;

  double operator[](int i) const;
  double& operator[](int i);

  Vec3& operator+=(const Vec3& v);

  Vec3& operator-=(const Vec3& v);

  Vec3& operator*=(double t);

  Vec3& operator/=(double t);

  Vec3 operator+(const Vec3& v) const;

  Vec3 operator-(const Vec3& v) const;

  Vec3 operator*(const Vec3& v) const;

  Vec3 operator/(const Vec3& v) const;

  Vec3 operator*(double t) const;

  Vec3 operator/(double t) const;

  double length() const;

  double length_squared() const;

  Vec3& operator=(const Vec3& v);

  Vec3 cross(const Vec3& v) const;

  double dot(const Vec3& v) const;

  Vec3 normalize() const;

  static Vec3 random_in_unit_sphere();

  Vec3 reflect_by(const Vec3& n) const;
 private:
  double data[3];
};
}  // namespace sf