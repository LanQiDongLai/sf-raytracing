#include "mat4.h"

namespace sf {

Mat4::Mat4() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        data[i][j] = 1;
      } else {
        data[i][j] = 0;
      }
    }
  }
}

Mat4::Mat4(double m00, double m01, double m02, double m03, double m10,
           double m11, double m12, double m13, double m20, double m21,
           double m22, double m23, double m30, double m31, double m32,
           double m33) {
  data[0][0] = m00;
  data[0][1] = m01;
  data[0][2] = m02;
  data[0][3] = m03;
  data[1][0] = m10;
  data[1][1] = m11;
  data[1][2] = m12;
  data[1][3] = m13;
  data[2][0] = m20;
  data[2][1] = m21;
  data[2][2] = m22;
  data[2][3] = m23;
  data[3][0] = m30;
  data[3][1] = m31;
  data[3][2] = m32;
  data[3][3] = m33;
}

Vec3 Mat4::operator*(const Vec3& v) const {
  Vec3 result;
  for (int i = 0; i < 3; i++) {
    result[i] = data[i][0] * v[0] + data[i][1] * v[1] + data[i][2] * v[2] +
                data[i][3] * 1;
  }
  double w = data[3][0] * v[0] + data[3][1] * v[1] + data[3][2] * v[2] +
              data[3][3] * 1;
  result /= w;
  return result;
}

Mat4 Mat4::operator*(const Mat4& m) const {
  Mat4 result;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      result.data[i][j] = 0;
      for (int k = 0; k < 4; k++) {
        result.data[i][j] += data[i][k] * m.data[k][j];
      }
    }
  }
  return result;
}

double* Mat4::operator[](int i) {
  return data[i];
}

const double* Mat4::operator[](int i) const {
  return data[i];
}

double Mat4::get(int i, int j) const {
  return data[i][j];
}

void Mat4::set(int i, int j, double val) {
  data[i][j] = val;
}

Mat4 Mat4::transpose() const {
  Mat4 result;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      result.data[i][j] = data[j][i];
    }
  }
  return result;
}


}  // namespace sf