#include "Vector3.h"

#include <cmath>

Vec3::Vec3(const Vec3 &vec)
{
  m_X = vec.m_X;
  m_Y = vec.m_Y;
  m_Z = vec.m_Z;
}

Vec3::Vec3(float x, float y, float z)
  : m_X(x), m_Y(y), m_Z(z)
{
}

/* SPOILER VERY RACIST JOKE AT LINE 18 */
// Japonais a nager quand je me chinoyé

float Vec3::Length()
{
  return sqrtf((m_X*m_X) + (m_Y*m_Y) + (m_Z*m_Z));
}
float Vec3::Dot(const Vec3 &vec)
{
  return (m_X*vec.m_X) + (m_Y*vec.m_Y) + (m_Z*vec.m_Z);
}
Vec3 Vec3::Cross(const Vec3 &vec)
{
  return Vec3(/*x*/(m_Y*vec.m_Z - m_Z*vec.m_Y),/*y*/(m_Z*vec.m_X - m_X*vec.m_Z),/*z*/(m_X*vec.m_Y - m_Y*vec.m_X));
}
void Vec3::Normalize()
{
  float len = Length();
  m_X /= len;
  m_Y /= len;
  m_Z /= len;
}

//////////// OPERATOR OVERLOADING ///////////////

// vector / vector overloading
Vec3 Vec3::operator+ (const Vec3 &right)
{
  return Vec3(m_X+right.m_X, m_Y+right.m_Y, m_Z+right.m_Z);
}
Vec3 Vec3::operator- (const Vec3 &right)
{
  return Vec3(m_X-right.m_X, m_Y-right.m_Y, m_Z-right.m_Z);
}
/*Vec3 operator* (Vec3& right)
{
}
Vec3 operator/ (Vec3& right)
{
}*/

// this vector overloading
Vec3 Vec3::operator- ()
{
  return Vec3(-m_X, -m_Y, -m_Z);
}

// vector/scalar overloading
Vec3 Vec3::operator* (float scale)
{
  return Vec3(m_X*scale, m_Y*scale, m_Z*scale);
}
Vec3 Vec3::operator/ (float scale)
{
  return Vec3(m_X/scale, m_Y/scale, m_Z/scale);
}
