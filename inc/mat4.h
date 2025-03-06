#pragma once
#include "vec3.h"

namespace sf {
class Mat4 {
 public:
  Mat4();
  Mat4(double m00, double m01, double m02, double m03, double m10, double m11,
       double m12, double m13, double m20, double m21, double m22, double m23,
       double m30, double m31, double m32, double m33);
  Vec3 operator*(const Vec3& v) const;
  Mat4 operator*(const Mat4& m) const;

  double *operator[](int i);
  const double *operator[](int i) const;

  double get(int i, int j) const;
  void set(int i, int j, double val);
  Mat4 transpose() const;  

 private:
  double data[4][4];
};
}  // namespace sf