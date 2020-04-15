#include "Vector4.h"

#include <cmath>

/////////////// CONSTRUCTORS ////////////////////
Vec4::Vec4(const Vec4 &vec)
{
  m_X = vec.m_X;
  m_Y = vec.m_Y;
  m_Z = vec.m_Z;
  m_W = vec.m_W;
}

Vec4::Vec4(float x, float y, float z, float w)
  : m_X(x), m_Y(y), m_Z(z), m_W(w)
{

}

Vec4::Vec4(const Vec2 &vec, float z, float w)
  : m_Z(z), m_W(w)
{
  m_X = vec.m_X;
  m_Y = vec.m_Y;
}

Vec4::Vec4(const Vec3 &vec, float w)
  : m_W(w)
{
  m_X = vec.m_X;
  m_Y = vec.m_Y;
  m_Z = vec.m_Z;
}

/////////////////////////////////////////////////

///////////////// METHODS ///////////////////////
float Vec4::Length() const
{
  return sqrtf((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z) + (m_W * m_W));
}

float Vec4::Dot(const Vec4 &vec)
{
  return (m_X * vec.m_X) + (m_Y * vec.m_Y) + (m_Z * vec.m_Z) + (m_W * vec.m_W);
}


void Vec4::Normalize()
{
  float len = Length();
  m_X /= len;
  m_Y /= len;
  m_Z /= len;
  m_W /= len;
}
/////////////////////////////////////////////////

//////////// OPERATOR OVERLOADING ///////////////

// vector / vector overloading
Vec4 Vec4::operator+ (const Vec4 &right)
{
  return Vec4(m_X + right.m_X, m_Y + right.m_Y, m_Z + right.m_Z, m_W + right.m_W);
}

Vec4 Vec4::operator- (const Vec4 &right)
{
  return Vec4(m_X - right.m_X, m_Y - right.m_Y, m_Z - right.m_Z, m_W - right.m_W);
}
Vec4& Vec4::operator+= (const Vec4 &right)
{
  m_X += right.m_X;
  m_Y += right.m_Y;
  m_Z += right.m_Z;
  m_W += right.m_W;
  return *this;
}
Vec4& Vec4::operator-= (const Vec4 &right)
{
  m_X -= right.m_X;
  m_Y -= right.m_Y;
  m_Z -= right.m_Z;
  m_W -= right.m_W;
  return *this;
}

// this vector overloading
Vec4 Vec4::operator- ()
{
  return Vec4(-m_X, -m_Y, -m_Z, -m_W);
}

// vector/scalar overloading
Vec4 Vec4::operator+ (float scale)
{
  return Vec4(m_X + scale, m_Y + scale, m_Z + scale, m_W + scale);
}

Vec4 Vec4::operator- (float scale)
{
  return Vec4(m_X - scale, m_Y - scale, m_Z - scale, m_W - scale);
}

Vec4 Vec4::operator* (float scale)
{
  return Vec4(m_X * scale, m_Y * scale, m_Z * scale, m_W * scale);
}

Vec4 Vec4::operator/ (float scale)
{
  return Vec4(m_X / scale, m_Y / scale, m_Z / scale, m_W / scale);
}

Vec4& Vec4::operator+= (float scale)
{
  m_X += scale;
  m_Y += scale;
  m_Z += scale;
  m_W += scale;
  return *this;
}

Vec4& Vec4::operator-= (float scale)
{
  m_X -= scale;
  m_Y -= scale;
  m_Z -= scale;
  m_W -= scale;
  return *this;
}

Vec4& Vec4::operator*= (float scale)
{
  m_X *= scale;
  m_Y *= scale;
  m_Z *= scale;
  m_W *= scale;
  return *this;
}

Vec4& Vec4::operator/= (float scale)
{
  m_X /= scale;
  m_Y /= scale;
  m_Z /= scale;
  m_W /= scale;
  return *this;
}


// Bool overloading
bool Vec4::operator== (const Vec4 &vec) const
{
  return (m_X == vec.m_X && m_Y == vec.m_Y && m_Z == vec.m_Z && m_W == vec.m_W);
}

bool Vec4::operator!= (const Vec4 &vec) const
{
  return !(m_X == vec.m_X && m_Y == vec.m_Y && m_Z == vec.m_Z && m_W == vec.m_W);
}

bool Vec4::operator< (const Vec4 &vec) const
{
  return (Length() < vec.Length());
}

bool Vec4::operator> (const Vec4 &vec) const
{
  return (Length() > vec.Length());
}

bool Vec4::operator<= (const Vec4 &vec) const
{
    return (Length() <= vec.Length());
}

bool Vec4::operator>= (const Vec4 &vec) const
{
  return (Length() >= vec.Length());
}

// Cout overloading
/*std::ostream& Vec4::operator<<(std::ostream &flux)
{
  flux << m_X << " " << m_Y << " " << m_Z << " " << m_W;
  return flux;
}*/
///////////////////////////////////////////////////
