#ifndef VECTOR2_H
#define VECTOR2_H

#include <ostream>

class Vec2
{
public:
  float m_X, m_Y;

  Vec2() {}
  Vec2(const Vec2& vec);
  Vec2(float x, float y);

  float Length() const;
  float Dot(const Vec2& vec);
  void Normalize();

  //////////// OPERATOR OVERLOADING ///////////////

  // vector/vector overloading
  Vec2 operator+ (const Vec2 &right);
  Vec2 operator- (const Vec2 &right);
  Vec2& operator+= (const Vec2 &right);
  Vec2& operator-= (const Vec2 &right);

  // this vector overloading
  Vec2 operator- ();

  // vector/scalar overloading
  Vec2 operator+ (float scale);
  Vec2 operator- (float scale);
  Vec2 operator* (float scale);
  Vec2 operator/ (float scale);
  Vec2& operator+= (float scale);
  Vec2& operator-= (float scale);
  Vec2& operator*= (float scale);
  Vec2& operator/= (float scale);

  // Bool overloading
  bool operator== (const Vec2 &vec) const;
  bool operator!= (const Vec2 &vec) const;
  bool operator< (const Vec2 &vec) const;
  bool operator> (const Vec2 &vec) const;
  bool operator<= (const Vec2 &vec) const;
  bool operator>= (const Vec2 &vec) const;

  // Cout overloading
  //std::ostream &operator<<(std::ostream &flux, Vec2 const &vec);
};

#endif
