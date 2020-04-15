#include "Matrix4x4.h"
#include <cmath>

///////////////// METHODS ///////////////////////

void Mat4x4::Identity()
{
  m_Mat[0][0] = 1;
  m_Mat[1][1] = 1;
  m_Mat[2][2] = 1;
  m_Mat[3][3] = 1;

  m_Mat[0][1] = 0;
  m_Mat[0][2] = 0;
  m_Mat[3][3] = 0;

  m_Mat[1][0] = 0;
  m_Mat[1][2] = 0;
  m_Mat[3][3] = 0;

  m_Mat[2][0] = 0;
  m_Mat[2][1] = 0;
  m_Mat[3][3] = 0;
}
// Translate Methods
void Mat4x4::Translate(float x, float y, float z)
{
  m_Mat[0][3] += x;
  m_Mat[1][3] += y;
  m_Mat[2][3] += z;
}
void Mat4x4::Translate(const Vec3 &vec)
{
  m_Mat[0][3] += vec.m_X;
  m_Mat[1][3] += vec.m_Y;
  m_Mat[2][3] += vec.m_Z;
}

void Mat4x4::Rotate(float radians, int axis)
{
  switch(axis)
  {
    case XAXIS:
      m_Mat[1][1] = cos(radians);
      m_Mat[1][2] = -(sin(radians));
      m_Mat[2][1] = sin(radians);
      m_Mat[2][2] = cos(radians);
      break;

    case YAXIS:
      m_Mat[0][0] = cos(radians);
      m_Mat[2][0] = -(sin(radians));
      m_Mat[0][2] = sin(radians);
      m_Mat[2][2] = cos(radians);
      break;

    case ZAXIS:
      m_Mat[0][0] = cos(radians);
      m_Mat[0][1] = -(sin(radians));
      m_Mat[1][0] = sin(radians);
      m_Mat[1][1] = cos(radians);
      break;
  }

}
// Scale methods
void Mat4x4::Scale(float x, float y, float z)
{
  m_Mat[0][0] *= x;
  m_Mat[1][1] *= y;
  m_Mat[2][2] *= z;
}
void Mat4x4::Scale(const Vec3 &vec)
{
  m_Mat[0][0] *= vec.m_X;
  m_Mat[1][1] *= vec.m_Y;
  m_Mat[2][2] *= vec.m_Z;
}

/////////////////////////////////////////////////

//////////// OPERATOR OVERLOADING ///////////////
// Matrix / Matrix operators
Mat4x4 Mat4x4::operator+(const Mat4x4 &mat)
{
  Mat4x4 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0] + mat.m_Mat[0][0];
  rmat.m_Mat[0][1] = m_Mat[0][1] + mat.m_Mat[0][1];
  rmat.m_Mat[0][2] = m_Mat[0][2] + mat.m_Mat[0][2];
  rmat.m_Mat[0][3] = m_Mat[0][3] + mat.m_Mat[0][3];

  rmat.m_Mat[1][0] = m_Mat[1][0] + mat.m_Mat[1][0];
  rmat.m_Mat[1][1] = m_Mat[1][1] + mat.m_Mat[1][1];
  rmat.m_Mat[1][2] = m_Mat[1][2] + mat.m_Mat[1][2];
  rmat.m_Mat[1][3] = m_Mat[1][3] + mat.m_Mat[1][3];

  rmat.m_Mat[2][0] = m_Mat[2][0] + mat.m_Mat[2][0];
  rmat.m_Mat[2][1] = m_Mat[2][1] + mat.m_Mat[2][1];
  rmat.m_Mat[2][2] = m_Mat[2][2] + mat.m_Mat[2][2];
  rmat.m_Mat[2][3] = m_Mat[2][3] + mat.m_Mat[2][3];

  rmat.m_Mat[3][0] = m_Mat[3][0] + mat.m_Mat[3][0];
  rmat.m_Mat[3][1] = m_Mat[3][1] + mat.m_Mat[3][1];
  rmat.m_Mat[3][2] = m_Mat[3][2] + mat.m_Mat[3][2];
  rmat.m_Mat[3][3] = m_Mat[3][3] + mat.m_Mat[3][3];
  return rmat;
}
Mat4x4 Mat4x4::operator-(const Mat4x4 &mat)
{
  Mat4x4 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0] - mat.m_Mat[0][0];
  rmat.m_Mat[0][1] = m_Mat[0][1] - mat.m_Mat[0][1];
  rmat.m_Mat[0][2] = m_Mat[0][2] - mat.m_Mat[0][2];
  rmat.m_Mat[0][3] = m_Mat[0][3] - mat.m_Mat[0][3];

  rmat.m_Mat[1][0] = m_Mat[1][0] - mat.m_Mat[1][0];
  rmat.m_Mat[1][1] = m_Mat[1][1] - mat.m_Mat[1][1];
  rmat.m_Mat[1][2] = m_Mat[1][2] - mat.m_Mat[1][2];
  rmat.m_Mat[1][3] = m_Mat[1][3] - mat.m_Mat[1][3];

  rmat.m_Mat[2][0] = m_Mat[2][0] - mat.m_Mat[2][0];
  rmat.m_Mat[2][1] = m_Mat[2][1] - mat.m_Mat[2][1];
  rmat.m_Mat[2][2] = m_Mat[2][2] - mat.m_Mat[2][2];
  rmat.m_Mat[2][3] = m_Mat[2][3] - mat.m_Mat[2][3];

  rmat.m_Mat[3][0] = m_Mat[3][0] - mat.m_Mat[3][0];
  rmat.m_Mat[3][1] = m_Mat[3][1] - mat.m_Mat[3][1];
  rmat.m_Mat[3][2] = m_Mat[3][2] - mat.m_Mat[3][2];
  rmat.m_Mat[3][3] = m_Mat[3][3] - mat.m_Mat[3][3];
  return rmat;
}
Mat4x4 Mat4x4::operator*(const Mat4x4 &mat)
{
  Mat4x4 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0]*mat.m_Mat[0][0] + m_Mat[0][1]*mat.m_Mat[1][0] + m_Mat[0][2]*mat.m_Mat[2][0] + m_Mat[0][3]*mat.m_Mat[3][0];
  rmat.m_Mat[0][1] = m_Mat[0][0]*mat.m_Mat[0][1] + m_Mat[0][1]*mat.m_Mat[1][1] + m_Mat[0][2]*mat.m_Mat[2][1] + m_Mat[0][3]*mat.m_Mat[3][1];
  rmat.m_Mat[0][2] = m_Mat[0][0]*mat.m_Mat[0][2] + m_Mat[0][1]*mat.m_Mat[1][2] + m_Mat[0][2]*mat.m_Mat[2][2] + m_Mat[0][3]*mat.m_Mat[3][2];
  rmat.m_Mat[0][3] = m_Mat[0][0]*mat.m_Mat[0][3] + m_Mat[0][1]*mat.m_Mat[1][3] + m_Mat[0][2]*mat.m_Mat[2][3] + m_Mat[0][3]*mat.m_Mat[3][3];

  rmat.m_Mat[1][0] = m_Mat[1][0]*mat.m_Mat[0][0] + m_Mat[1][1]*mat.m_Mat[1][0] + m_Mat[1][2]*mat.m_Mat[2][0] + m_Mat[1][3]*mat.m_Mat[3][0];
  rmat.m_Mat[1][1] = m_Mat[1][0]*mat.m_Mat[0][1] + m_Mat[1][1]*mat.m_Mat[1][1] + m_Mat[1][2]*mat.m_Mat[2][1] + m_Mat[1][3]*mat.m_Mat[3][1];
  rmat.m_Mat[1][2] = m_Mat[1][0]*mat.m_Mat[0][2] + m_Mat[1][1]*mat.m_Mat[1][2] + m_Mat[1][2]*mat.m_Mat[2][2] + m_Mat[1][3]*mat.m_Mat[3][2];
  rmat.m_Mat[1][3] = m_Mat[1][0]*mat.m_Mat[0][3] + m_Mat[1][1]*mat.m_Mat[1][3] + m_Mat[1][2]*mat.m_Mat[2][3] + m_Mat[1][3]*mat.m_Mat[3][3];

  rmat.m_Mat[2][0] = m_Mat[2][0]*mat.m_Mat[0][0] + m_Mat[2][1]*mat.m_Mat[1][0] + m_Mat[2][2]*mat.m_Mat[2][0] + m_Mat[2][3]*mat.m_Mat[3][0];
  rmat.m_Mat[2][1] = m_Mat[2][0]*mat.m_Mat[0][1] + m_Mat[2][1]*mat.m_Mat[1][1] + m_Mat[2][2]*mat.m_Mat[2][1] + m_Mat[2][3]*mat.m_Mat[3][1];
  rmat.m_Mat[2][2] = m_Mat[2][0]*mat.m_Mat[0][2] + m_Mat[2][1]*mat.m_Mat[1][2] + m_Mat[2][2]*mat.m_Mat[2][2] + m_Mat[2][3]*mat.m_Mat[3][2];
  rmat.m_Mat[2][3] = m_Mat[2][0]*mat.m_Mat[0][3] + m_Mat[2][1]*mat.m_Mat[1][3] + m_Mat[2][2]*mat.m_Mat[2][3] + m_Mat[2][3]*mat.m_Mat[3][3];

  rmat.m_Mat[3][0] = m_Mat[3][0]*mat.m_Mat[0][0] + m_Mat[3][1]*mat.m_Mat[1][0] + m_Mat[3][2]*mat.m_Mat[2][0] + m_Mat[3][3]*mat.m_Mat[3][0];
  rmat.m_Mat[3][1] = m_Mat[3][0]*mat.m_Mat[0][1] + m_Mat[3][1]*mat.m_Mat[1][1] + m_Mat[3][2]*mat.m_Mat[2][1] + m_Mat[3][3]*mat.m_Mat[3][1];
  rmat.m_Mat[3][2] = m_Mat[3][0]*mat.m_Mat[0][2] + m_Mat[3][1]*mat.m_Mat[1][2] + m_Mat[3][2]*mat.m_Mat[2][2] + m_Mat[3][3]*mat.m_Mat[3][2];
  rmat.m_Mat[3][3] = m_Mat[3][0]*mat.m_Mat[0][3] + m_Mat[3][1]*mat.m_Mat[1][3] + m_Mat[3][2]*mat.m_Mat[2][3] + m_Mat[3][3]*mat.m_Mat[3][3];
  return rmat;
}

Mat4x4& Mat4x4::operator+=(const Mat4x4 &mat)
{
  m_Mat[0][0] += mat.m_Mat[0][0];
  m_Mat[0][1] += mat.m_Mat[0][1];
  m_Mat[0][2] += mat.m_Mat[0][2];
  m_Mat[0][3] += mat.m_Mat[0][3];

  m_Mat[1][0] += mat.m_Mat[1][0];
  m_Mat[1][1] += mat.m_Mat[1][1];
  m_Mat[1][2] += mat.m_Mat[1][2];

  m_Mat[1][3] += mat.m_Mat[1][3];
  m_Mat[2][0] += mat.m_Mat[2][0];
  m_Mat[2][1] += mat.m_Mat[2][1];
  m_Mat[2][2] += mat.m_Mat[2][2];
  m_Mat[2][3] += mat.m_Mat[2][3];

  m_Mat[3][0] += mat.m_Mat[3][0];
  m_Mat[3][1] += mat.m_Mat[3][1];
  m_Mat[3][2] += mat.m_Mat[3][2];
  m_Mat[3][3] += mat.m_Mat[3][3];
  return *this;
}
Mat4x4& Mat4x4::operator-=(const Mat4x4 &mat)
{
  m_Mat[0][0] -= mat.m_Mat[0][0];
  m_Mat[0][1] -= mat.m_Mat[0][1];
  m_Mat[0][2] -= mat.m_Mat[0][2];
  m_Mat[0][3] -= mat.m_Mat[0][3];

  m_Mat[1][0] -= mat.m_Mat[1][0];
  m_Mat[1][1] -= mat.m_Mat[1][1];
  m_Mat[1][2] -= mat.m_Mat[1][2];
  m_Mat[1][3] -= mat.m_Mat[1][3];

  m_Mat[2][0] -= mat.m_Mat[2][0];
  m_Mat[2][1] -= mat.m_Mat[2][1];
  m_Mat[2][2] -= mat.m_Mat[2][2];
  m_Mat[2][3] -= mat.m_Mat[2][3];

  m_Mat[3][0] -= mat.m_Mat[3][0];
  m_Mat[3][1] -= mat.m_Mat[3][1];
  m_Mat[3][2] -= mat.m_Mat[3][2];
  m_Mat[3][3] -= mat.m_Mat[3][3];
}
Mat4x4& Mat4x4::operator*=(const Mat4x4 &mat)
{
  Mat4x4 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0]*mat.m_Mat[0][0] + m_Mat[0][1]*mat.m_Mat[1][0] + m_Mat[0][2]*mat.m_Mat[2][0] + m_Mat[0][3]*mat.m_Mat[3][0];
  rmat.m_Mat[0][1] = m_Mat[0][0]*mat.m_Mat[0][1] + m_Mat[0][1]*mat.m_Mat[1][1] + m_Mat[0][2]*mat.m_Mat[2][1] + m_Mat[0][3]*mat.m_Mat[3][1];
  rmat.m_Mat[0][2] = m_Mat[0][0]*mat.m_Mat[0][2] + m_Mat[0][1]*mat.m_Mat[1][2] + m_Mat[0][2]*mat.m_Mat[2][2] + m_Mat[0][3]*mat.m_Mat[3][2];
  rmat.m_Mat[0][3] = m_Mat[0][0]*mat.m_Mat[0][3] + m_Mat[0][1]*mat.m_Mat[1][3] + m_Mat[0][2]*mat.m_Mat[2][3] + m_Mat[0][3]*mat.m_Mat[3][3];

  rmat.m_Mat[1][0] = m_Mat[1][0]*mat.m_Mat[0][0] + m_Mat[1][1]*mat.m_Mat[1][0] + m_Mat[1][2]*mat.m_Mat[2][0] + m_Mat[1][3]*mat.m_Mat[3][0];
  rmat.m_Mat[1][1] = m_Mat[1][0]*mat.m_Mat[0][1] + m_Mat[1][1]*mat.m_Mat[1][1] + m_Mat[1][2]*mat.m_Mat[2][1] + m_Mat[1][3]*mat.m_Mat[3][1];
  rmat.m_Mat[1][2] = m_Mat[1][0]*mat.m_Mat[0][2] + m_Mat[1][1]*mat.m_Mat[1][2] + m_Mat[1][2]*mat.m_Mat[2][2] + m_Mat[1][3]*mat.m_Mat[3][2];
  rmat.m_Mat[1][3] = m_Mat[1][0]*mat.m_Mat[0][3] + m_Mat[1][1]*mat.m_Mat[1][3] + m_Mat[1][2]*mat.m_Mat[2][3] + m_Mat[1][3]*mat.m_Mat[3][3];

  rmat.m_Mat[2][0] = m_Mat[2][0]*mat.m_Mat[0][0] + m_Mat[2][1]*mat.m_Mat[1][0] + m_Mat[2][2]*mat.m_Mat[2][0] + m_Mat[2][3]*mat.m_Mat[3][0];
  rmat.m_Mat[2][1] = m_Mat[2][0]*mat.m_Mat[0][1] + m_Mat[2][1]*mat.m_Mat[1][1] + m_Mat[2][2]*mat.m_Mat[2][1] + m_Mat[2][3]*mat.m_Mat[3][1];
  rmat.m_Mat[2][2] = m_Mat[2][0]*mat.m_Mat[0][2] + m_Mat[2][1]*mat.m_Mat[1][2] + m_Mat[2][2]*mat.m_Mat[2][2] + m_Mat[2][3]*mat.m_Mat[3][2];
  rmat.m_Mat[2][3] = m_Mat[2][0]*mat.m_Mat[0][3] + m_Mat[2][1]*mat.m_Mat[1][3] + m_Mat[2][2]*mat.m_Mat[2][3] + m_Mat[2][3]*mat.m_Mat[3][3];

  rmat.m_Mat[3][0] = m_Mat[3][0]*mat.m_Mat[0][0] + m_Mat[3][1]*mat.m_Mat[1][0] + m_Mat[3][2]*mat.m_Mat[2][0] + m_Mat[3][3]*mat.m_Mat[3][0];
  rmat.m_Mat[3][1] = m_Mat[3][0]*mat.m_Mat[0][1] + m_Mat[3][1]*mat.m_Mat[1][1] + m_Mat[3][2]*mat.m_Mat[2][1] + m_Mat[3][3]*mat.m_Mat[3][1];
  rmat.m_Mat[3][2] = m_Mat[3][0]*mat.m_Mat[0][2] + m_Mat[3][1]*mat.m_Mat[1][2] + m_Mat[3][2]*mat.m_Mat[2][2] + m_Mat[3][3]*mat.m_Mat[3][2];
  rmat.m_Mat[3][3] = m_Mat[3][0]*mat.m_Mat[0][3] + m_Mat[3][1]*mat.m_Mat[1][3] + m_Mat[3][2]*mat.m_Mat[2][3] + m_Mat[3][3]*mat.m_Mat[3][3];
  *this = rmat;
  return *this;
}

// Matrix / Scalar operators
Mat4x4 Mat4x4::operator*(float scale)
{
  Mat4x4 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0] * scale;
  rmat.m_Mat[0][1] = m_Mat[0][1] * scale;
  rmat.m_Mat[0][2] = m_Mat[0][2] * scale;
  rmat.m_Mat[0][3] = m_Mat[0][3] * scale;

  rmat.m_Mat[1][0] = m_Mat[1][0] * scale;
  rmat.m_Mat[1][1] = m_Mat[1][1] * scale;
  rmat.m_Mat[1][2] = m_Mat[1][2] * scale;
  rmat.m_Mat[1][3] = m_Mat[1][3] * scale;

  rmat.m_Mat[2][0] = m_Mat[2][0] * scale;
  rmat.m_Mat[2][1] = m_Mat[2][1] * scale;
  rmat.m_Mat[2][2] = m_Mat[2][2] * scale;
  rmat.m_Mat[2][3] = m_Mat[2][3] * scale;

  rmat.m_Mat[3][0] = m_Mat[3][0] * scale;
  rmat.m_Mat[3][1] = m_Mat[3][1] * scale;
  rmat.m_Mat[3][2] = m_Mat[3][2] * scale;
  rmat.m_Mat[3][3] = m_Mat[3][3] * scale;
  return rmat;
}
Mat4x4& Mat4x4::operator*=(float scale)
{
  m_Mat[0][0] *= scale;
  m_Mat[0][1] *= scale;
  m_Mat[0][2] *= scale;
  m_Mat[0][3] *= scale;

  m_Mat[1][0] *= scale;
  m_Mat[1][1] *= scale;
  m_Mat[1][2] *= scale;
  m_Mat[1][3] *= scale;

  m_Mat[2][0] *= scale;
  m_Mat[2][1] *= scale;
  m_Mat[2][2] *= scale;
  m_Mat[2][3] *= scale;

  m_Mat[3][0] *= scale;
  m_Mat[3][1] *= scale;
  m_Mat[3][2] *= scale;
  m_Mat[3][3] *= scale;
  return *this;
}


// Matrix / Vector operators
Vec4 Mat4x4::operator*(const Vec4 &vec)
{
  Vec4 rvec;
  rvec.m_X = m_Mat[0][0] * vec.m_X + m_Mat[0][1] * vec.m_Y + m_Mat[0][2] * vec.m_Z + m_Mat[0][3] * vec.m_W;
  rvec.m_Y = m_Mat[1][0] * vec.m_X + m_Mat[1][1] * vec.m_Y + m_Mat[1][2] * vec.m_Z + m_Mat[1][3] * vec.m_W;
  rvec.m_Z = m_Mat[2][0] * vec.m_X + m_Mat[2][1] * vec.m_Y + m_Mat[2][2] * vec.m_Z + m_Mat[2][3] * vec.m_W;
  rvec.m_W = m_Mat[3][0] * vec.m_X + m_Mat[3][1] * vec.m_Y + m_Mat[3][2] * vec.m_Z + m_Mat[3][3] * vec.m_W;
  return rvec;
}

// Bool overloading
bool Mat4x4::operator==(const Mat4x4 &mat)
{
  bool isEqual = true;
  for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
    if(m_Mat[i][j] != mat.m_Mat[i][j])
    {
      isEqual = false;
      break;
    }
  return isEqual;
}

bool Mat4x4::operator!=(const Mat4x4 &mat)
{
  bool isNotEqual = false;
  for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
    if(m_Mat[i][j] != mat.m_Mat[i][j])
    {
      isNotEqual = true;
      break;
    }
  return isNotEqual;
}

///////////////////////////////////////////////////
