#ifndef VECTOR4_H
#define VECTOR4_H

#include "Vector2.h"
#include "Vector3.h"
#include <ostream>

class Vec4
{
  float m_X, m_Y, m_Z, m_W;
  Vec4() {}
  Vec4(const Vec4 &vec);
  Vec4(float x, float y, float z, float w);
  Vec4(const Vec3 &vec, float w);
  Vec4(const Vec2 &vec, float z, float w);


  float Length() const;
  float Dot(const Vec4 &vec);
  void Normalize();

  //////////// OPERATOR OVERLOADING ///////////////

  // vector / vector overloading
  Vec4 operator+ (const Vec4 &right);
  Vec4 operator- (const Vec4 &right);
  Vec4& operator+= (const Vec4 &right);
  Vec4& operator-= (const Vec4 &right);

  // this vector overloading
  Vec4 operator- ();

  // vector/scalar overloading
  Vec4 operator+ (float scale);
  Vec4 operator- (float scale);
  Vec4 operator* (float scale);
  Vec4 operator/ (float scale);
  Vec4& operator+= (float scale);
  Vec4& operator-= (float scale);
  Vec4& operator*= (float scale);
  Vec4& operator/= (float scale);

  // Bool overloading
  bool operator== (const Vec4 &vec) const;
  bool operator!= (const Vec4 &vec) const;
  bool operator< (const Vec4 &vec) const;
  bool operator> (const Vec4 &vec) const;
  bool operator<= (const Vec4 &vec) const;
  bool operator>= (const Vec4 &vec) const;

  // Cout overloading
  //std::ostream& operator<<(std::ostream &flux);
};

#endif
