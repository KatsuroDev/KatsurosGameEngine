#include "Vector2.h"

#include <cmath>

/////////////// CONSTRUCTORS ////////////////////
Vec2::Vec2(const Vec2& vec)
{
  m_X = vec.m_X;
  m_Y = vec.m_Y;
}

Vec2::Vec2(float x, float y)
  : m_X(x), m_Y(y)
{
}
/////////////////////////////////////////////////

///////////////// METHODS ///////////////////////
float Vec2::Length() const
{
  return sqrtf((m_X * m_X) + (m_Y * m_Y));
}

float Vec2::Dot(const Vec2 &vec)
{
  return (m_X * m_X) + (vec.m_Y * vec.m_Y);
}

void Vec2::Normalize()
{
  float len = Length();
  m_X /= len;
  m_Y /= len;
}
/////////////////////////////////////////////////

//////////// OPERATOR OVERLOADING ///////////////

// vector/vector overloading
Vec2 Vec2::operator+ (const Vec2 &right)
{
  return Vec2(m_X + right.m_X, m_Y + right.m_Y);
}
Vec2 Vec2::operator- (const Vec2 &right)
{
  return Vec2(m_X - right.m_X, m_Y - right.m_Y);
}
Vec2& Vec2::operator+= (const Vec2 &right)
{
  m_X += right.m_X;
  m_Y += right.m_Y;
  return *this;
}
Vec2& Vec2::operator-= (const Vec2 &right)
{
  m_X -= right.m_X;
  m_Y -= right.m_Y;
  return *this;
}

// this vector overloading
Vec2 Vec2::operator- ()
{
  return Vec2(-m_X, -m_Y);
}

// vector/scalar overloading
Vec2 Vec2::operator+ (float scale)
{
  return Vec2(m_X + scale, m_Y + scale);
}
Vec2 Vec2::operator- (float scale)
{
  return Vec2(m_X - scale, m_Y - scale);
}
Vec2 Vec2::operator* (float scale)
{
  return Vec2(m_X * scale, m_Y * scale);
}
Vec2 Vec2::operator/ (float scale)
{
  return Vec2(m_X / scale, m_Y / scale);
}
Vec2& Vec2::operator+= (float scale)
{
  m_X += scale;
  m_Y += scale;
  return *this;
}
Vec2& Vec2::operator-= (float scale)
{
  m_X -= scale;
  m_Y -= scale;
  return *this;
}
Vec2& Vec2::operator*= (float scale)
{
  m_X *= scale;
  m_Y *= scale;
  return *this;
}
Vec2& Vec2::operator/= (float scale)
{
  m_X /= scale;
  m_Y /= scale;
  return *this;
}

// Bool overloading
bool Vec2::operator== (const Vec2 &vec) const
{
  return (m_X == vec.m_X && m_Y == vec.m_Y);
}
bool Vec2::operator!= (const Vec2 &vec) const
{
  return !(m_X == vec.m_X && m_Y == vec.m_Y);
}
bool Vec2::operator< (const Vec2 &vec) const
{
  return (Length() < vec.Length());
}
bool Vec2::operator> (const Vec2 &vec) const
{
  return (Length() > vec.Length());
}
bool Vec2::operator<= (const Vec2 &vec) const
{
  return (Length() <= vec.Length());
}
bool Vec2::operator>= (const Vec2 &vec) const
{
  return (Length() >= vec.Length());
}

// Cout overloading
/*std::ostream &Vec3::operator<<(std::ostream &flux, Vec2 const &vec)
{
  flux << vec.m_X << " " << vec.m_Y;
  return flux;
}*/
///////////////////////////////////////////////////
