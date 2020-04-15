#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "Vector2.h"
#include "Vector3.h"

class Mat3x3
{
public:
  float m_Mat[3][3] = {0};
  Mat3x3() {}

  // Matrix methods
  void Identity();
  void Translate(float x, float y);
  void Translate(const Vec2 &vec);
  void Rotate(float radians);
  void Scale(float x, float y);
  void Scale(const Vec2 &vec);

  // Matrix / Matrix overloading
  Mat3x3 operator+(const Mat3x3 &mat);
  Mat3x3 operator-(const Mat3x3 &mat);
  Mat3x3 operator*(const Mat3x3 &mat);
  Mat3x3& operator+=(const Mat3x3 &mat);
  Mat3x3& operator-=(const Mat3x3 &mat);
  Mat3x3& operator*=(const Mat3x3 &mat);

  // Matrix / Scalar overloading
  Mat3x3 operator*(float scale);
  Mat3x3& operator*=(float scale);

  // Matrix / Vector overloading
  Vec3 operator*(const Vec3 &vec);

  // Bool overloading
  bool Mat3x3::operator==(const Mat3x3 &mat);
  bool Mat3x3::operator!=(const Mat3x3 &mat);

};

#endif
