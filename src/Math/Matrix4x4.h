#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

enum {
  XAXIS = 1,
  YAXIS,
  ZAXIS
};



class Mat4x4
{
public:
  float m_Mat[4][4] = {0};
  Mat4x4() {}

  // Matrix methods
  void Identity();
  void Translate(float x, float y, float z);
  void Translate(const Vec3 &vec);
  void Rotate(float radians, int axis);
  void Scale(float x, float y, float z);
  void Scale(const Vec3 &vec);
  void Print();
  void Ortho(float left, float right, float bottom, float top, float near, float far);
  //void Perspective(float fov, float);

  // Matrix 2D methods !
  void Translate2D(float x, float y);
  void Translate2D(const Vec2 &vec);
  void Rotate2D(float radians);
  void Scale2D(float x, float y);
  void Scale2D(const Vec2 &vec);


  // Matrix / Matrix overloading
  Mat4x4 operator+(const Mat4x4 &mat);
  Mat4x4 operator-(const Mat4x4 &mat);
  Mat4x4 operator*(const Mat4x4 &mat);
  Mat4x4& operator+=(const Mat4x4 &mat);
  Mat4x4& operator-=(const Mat4x4 &mat);
  Mat4x4& operator*=(const Mat4x4 &mat);

  // Matrix / Scalar overloading
  Mat4x4 operator*(float scale);
  Mat4x4& operator*=(float scale);

  // Matrix / Vector overloading
  Vec4 operator*(const Vec4 &vec);

  // Bool overloading
  bool operator==(const Mat4x4 &mat);
  bool operator!=(const Mat4x4 &mat);

};

#endif
