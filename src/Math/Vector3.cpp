#include "Vector3.h"

#include <cmath>


/////////////// CONSTRUCTORS ////////////////////
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

Vec3::Vec3(const Vec2 &vec, float z)
  : m_Z(z)
{
  m_X = vec.m_X;
  m_Y = vec.m_Y;
}
/////////////////////////////////////////////////

///////////////// METHODS ///////////////////////
float Vec3::Length() const
{
  return sqrtf((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z));
}
float Vec3::Dot(const Vec3 &vec)
{
  return (m_X * vec.m_X) + (m_Y * vec.m_Y) + (m_Z * vec.m_Z);
}
Vec3 Vec3::Cross(const Vec3 &vec)
{
  return Vec3(/*x*/((m_Y * vec.m_Z) - (m_Z * vec.m_Y)),/*y*/((m_Z * vec.m_X) - (m_X * vec.m_Z)),/*z*/((m_X * vec.m_Y) - (m_Y * vec.m_X)));
}
void Vec3::Normalize()
{
  float len = Length();
  m_X /= len;
  m_Y /= len;
  m_Z /= len;
}
/////////////////////////////////////////////////

//////////// OPERATOR OVERLOADING ///////////////

// vector / vector overloading
Vec3 Vec3::operator+ (const Vec3 &right)
{
  return Vec3(m_X + right.m_X, m_Y + right.m_Y, m_Z + right.m_Z);
}
Vec3 Vec3::operator- (const Vec3 &right)
{
  return Vec3(m_X - right.m_X, m_Y - right.m_Y, m_Z - right.m_Z);
}
Vec3& Vec3::operator+= (const Vec3 &right)
{
  m_X += right.m_X;
  m_Y += right.m_Y;
  m_Z += right.m_Z;
  return *this;
}
Vec3& Vec3::operator-= (const Vec3 &right)
{
  m_X -= right.m_X;
  m_Y -= right.m_Y;
  m_Z -= right.m_Z;
  return *this;
}


// this vector overloading
Vec3 Vec3::operator- ()
{
  return Vec3(-m_X, -m_Y, -m_Z);
}


// vector/scalar overloading
Vec3 Vec3::operator+ (float scale)
{
  return Vec3(m_X + scale, m_Y + scale, m_Z + scale);
}
Vec3 Vec3::operator- (float scale)
{
  return Vec3(m_X + scale, m_Y + scale, m_Z + scale);
}
Vec3 Vec3::operator* (float scale)
{
  return Vec3(m_X * scale, m_Y * scale, m_Z * scale);
}
Vec3 Vec3::operator/ (float scale)
{
  return Vec3(m_X / scale, m_Y / scale, m_Z / scale);
}
Vec3& Vec3::operator+= (float scale)
{
  m_X += scale;
  m_Y += scale;
  m_Z += scale;
  return *this;
}
Vec3& Vec3::operator-= (float scale)
{
  m_X -= scale;
  m_Y -= scale;
  m_Z -= scale;
  return *this;
}
Vec3& Vec3::operator*= (float scale)
{
  m_X *= scale;
  m_Y *= scale;
  m_Z *= scale;
  return *this;
}
Vec3& Vec3::operator/= (float scale)
{
  m_X /= scale;
  m_Y /= scale;
  m_Z /= scale;
  return *this;
}


// Bool overloading
bool Vec3::operator== (const Vec3 &vec) const
{
  return (m_X == vec.m_X && m_Y == vec.m_Y && m_Z == vec.m_Z);
}
bool Vec3::operator!= (const Vec3 &vec) const
{
  return !(m_X == vec.m_X && m_Y == vec.m_Y && m_Z == vec.m_Z);
}
bool Vec3::operator< (const Vec3 &vec) const
{
  return (Length() < vec.Length());
}
bool Vec3::operator> (const Vec3 &vec) const
{
  return (Length() > vec.Length());
}
bool Vec3::operator<= (const Vec3 &vec) const
{
  return (Length() <= vec.Length());
}
bool Vec3::operator>= (const Vec3 &vec) const
{
  return (Length() >= vec.Length());
}

// Cout overloading
/*std::ostream& Vec3::operator<<(std::ostream &flux)
{
  flux << m_X << " " << m_Y << " " << m_Z;
  return flux;
}*/
///////////////////////////////////////////////////
