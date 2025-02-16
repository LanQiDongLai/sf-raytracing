#pragma once

namespace sf {
class Vec3 {
 public:
  Vec3(double x, double y, double z);

  double x() const;
  double y() const;
  double z() const;

  Vec3 operator-() const;

  double operator[](int i) const;
  double& operator[](int i);

  Vec3& operator+=(const Vec3& v);

  Vec3& operator*=(double t);

  Vec3& operator/=(double t);

  double length() const;

  double length_squared() const;

 private:
  double data[3];
};
}  // namespace sf