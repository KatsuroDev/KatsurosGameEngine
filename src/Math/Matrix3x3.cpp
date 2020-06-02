#include "Matrix3x3.h"
#include <cmath>
#include <iostream>

///////////////// METHODS ///////////////////////
void Mat3x3::Identity()
{
  m_Mat[0][0] = 1;
  m_Mat[1][1] = 1;
  m_Mat[2][2] = 1;

  m_Mat[0][1] = 0;
  m_Mat[0][2] = 0;

  m_Mat[1][0] = 0;
  m_Mat[1][2] = 0;

  m_Mat[2][0] = 0;
  m_Mat[2][1] = 0;
}

// Translate methods
void Mat3x3::Translate(float x, float y)
{
  m_Mat[2][0] += x;
  m_Mat[2][1] += y;
}
void Mat3x3::Translate(const Vec2 &vec)
{
  m_Mat[2][0] += vec.m_X;
  m_Mat[2][1] += vec.m_Y;
}

void Mat3x3::Rotate(float radians)
{
  //radians
  m_Mat[0][0] = cos(radians);
  m_Mat[0][1] = -(sin(radians));
  m_Mat[1][0] = sin(radians);
  m_Mat[1][1] = cos(radians);
}

//Scale methods
void Mat3x3::Scale(float x, float y)
{
  Mat3x3 scaleMatrix;
  scaleMatrix.Identity();
  scaleMatrix.m_Mat[0][0] *= x;
  scaleMatrix.m_Mat[1][1] *= y;
  *this *= scaleMatrix;
}

void Mat3x3::Scale(const Vec2 &vec)
{
  Mat3x3 scaleMatrix;
  scaleMatrix.Identity();
  scaleMatrix.m_Mat[0][0] *= vec.m_X;
  scaleMatrix.m_Mat[1][1] *= vec.m_Y;
  *this *= scaleMatrix;
}

void Mat3x3::Print()
{
  std::cout << m_Mat[0][0] << " " << m_Mat[0][1] << " "<< m_Mat[0][2] << "\n";
  std::cout << m_Mat[1][0] << " " << m_Mat[1][1] << " "<< m_Mat[1][2] << "\n";
  std::cout << m_Mat[2][0] << " " << m_Mat[2][1] << " "<< m_Mat[2][2] << "\n";
}

void Mat3x3::Ortho(float left, float right, float bottom, float top, float near, float far)
{
  m_Mat[0][0] = 2 / (right - left);
  m_Mat[1][1] = 2 / (top - bottom);
  m_Mat[2][2] = -(2 / (far - near));
}


/////////////////////////////////////////////////

//////////// OPERATOR OVERLOADING ///////////////
// Matrix / Matrix operators
Mat3x3 Mat3x3::operator+(const Mat3x3 &mat)
{
  Mat3x3 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0] + mat.m_Mat[0][0];
  rmat.m_Mat[0][1] = m_Mat[0][1] + mat.m_Mat[0][1];
  rmat.m_Mat[0][2] = m_Mat[0][2] + mat.m_Mat[0][2];

  rmat.m_Mat[1][0] = m_Mat[1][0] + mat.m_Mat[1][0];
  rmat.m_Mat[1][1] = m_Mat[1][1] + mat.m_Mat[1][1];
  rmat.m_Mat[1][2] = m_Mat[1][2] + mat.m_Mat[1][2];

  rmat.m_Mat[2][0] = m_Mat[2][0] + mat.m_Mat[2][0];
  rmat.m_Mat[2][1] = m_Mat[2][1] + mat.m_Mat[2][1];
  rmat.m_Mat[2][2] = m_Mat[2][2] + mat.m_Mat[2][2];
  return rmat;
}

Mat3x3 Mat3x3::operator-(const Mat3x3 &mat)
{
  Mat3x3 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0] - mat.m_Mat[0][0];
  rmat.m_Mat[0][1] = m_Mat[0][1] - mat.m_Mat[0][1];
  rmat.m_Mat[0][2] = m_Mat[0][2] - mat.m_Mat[0][2];

  rmat.m_Mat[1][0] = m_Mat[1][0] - mat.m_Mat[1][0];
  rmat.m_Mat[1][1] = m_Mat[1][1] - mat.m_Mat[1][1];
  rmat.m_Mat[1][2] = m_Mat[1][2] - mat.m_Mat[1][2];

  rmat.m_Mat[2][0] = m_Mat[2][0] - mat.m_Mat[2][0];
  rmat.m_Mat[2][1] = m_Mat[2][1] - mat.m_Mat[2][1];
  rmat.m_Mat[2][2] = m_Mat[2][2] - mat.m_Mat[2][2];
  return rmat;
}

Mat3x3 Mat3x3::operator*(const Mat3x3 &mat)
{
  Mat3x3 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0]*mat.m_Mat[0][0] + m_Mat[0][1]*mat.m_Mat[1][0] + m_Mat[0][2]*mat.m_Mat[2][0];
  rmat.m_Mat[0][1] = m_Mat[1][0]*mat.m_Mat[0][0] + m_Mat[1][1]*mat.m_Mat[1][0] + m_Mat[1][2]*mat.m_Mat[2][0];
  rmat.m_Mat[0][2] = m_Mat[2][0]*mat.m_Mat[0][0] + m_Mat[2][1]*mat.m_Mat[1][0] + m_Mat[2][2]*mat.m_Mat[2][0];

  rmat.m_Mat[1][0] = m_Mat[0][0]*mat.m_Mat[0][1] + m_Mat[0][1]*mat.m_Mat[1][1] + m_Mat[0][2]*mat.m_Mat[2][1];
  rmat.m_Mat[1][1] = m_Mat[1][0]*mat.m_Mat[0][1] + m_Mat[1][1]*mat.m_Mat[1][1] + m_Mat[1][2]*mat.m_Mat[2][1];
  rmat.m_Mat[1][2] = m_Mat[2][0]*mat.m_Mat[0][1] + m_Mat[2][1]*mat.m_Mat[1][1] + m_Mat[2][2]*mat.m_Mat[2][1];

  rmat.m_Mat[2][0] = m_Mat[0][0]*mat.m_Mat[0][2] + m_Mat[0][1]*mat.m_Mat[1][2] + m_Mat[0][2]*mat.m_Mat[2][2];
  rmat.m_Mat[2][1] = m_Mat[1][0]*mat.m_Mat[0][2] + m_Mat[1][1]*mat.m_Mat[1][2] + m_Mat[1][2]*mat.m_Mat[2][2];
  rmat.m_Mat[2][2] = m_Mat[2][0]*mat.m_Mat[0][2] + m_Mat[2][1]*mat.m_Mat[1][2] + m_Mat[2][2]*mat.m_Mat[2][2];
  return rmat;
}

Mat3x3& Mat3x3::operator+=(const Mat3x3 &mat)
{

  m_Mat[0][0] += mat.m_Mat[0][0];
  m_Mat[0][1] += mat.m_Mat[0][1];
  m_Mat[0][2] += mat.m_Mat[0][2];

  m_Mat[1][0] += mat.m_Mat[1][0];
  m_Mat[1][1] += mat.m_Mat[1][1];
  m_Mat[1][2] += mat.m_Mat[1][2];

  m_Mat[2][0] += mat.m_Mat[2][0];
  m_Mat[2][1] += mat.m_Mat[2][1];
  m_Mat[2][2] += mat.m_Mat[2][2];
  return *this;

}

Mat3x3& Mat3x3::operator-=(const Mat3x3 &mat)
{
  m_Mat[0][0] -= mat.m_Mat[0][0];
  m_Mat[0][1] -= mat.m_Mat[0][1];
  m_Mat[0][2] -= mat.m_Mat[0][2];

  m_Mat[1][0] -= mat.m_Mat[1][0];
  m_Mat[1][1] -= mat.m_Mat[1][1];
  m_Mat[1][2] -= mat.m_Mat[1][2];

  m_Mat[2][0] -= mat.m_Mat[2][0];
  m_Mat[2][1] -= mat.m_Mat[2][1];
  m_Mat[2][2] -= mat.m_Mat[2][2];
  return *this;
}

Mat3x3& Mat3x3::operator*=(const Mat3x3 &mat)
{
  Mat3x3 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0]*mat.m_Mat[0][0] + m_Mat[0][1]*mat.m_Mat[1][0] + m_Mat[0][2]*mat.m_Mat[2][0];
  rmat.m_Mat[0][1] = m_Mat[1][0]*mat.m_Mat[0][0] + m_Mat[1][1]*mat.m_Mat[1][0] + m_Mat[1][2]*mat.m_Mat[2][0];
  rmat.m_Mat[0][2] = m_Mat[2][0]*mat.m_Mat[0][0] + m_Mat[2][1]*mat.m_Mat[1][0] + m_Mat[2][2]*mat.m_Mat[2][0];

  rmat.m_Mat[1][0] = m_Mat[0][0]*mat.m_Mat[0][1] + m_Mat[0][1]*mat.m_Mat[1][1] + m_Mat[0][2]*mat.m_Mat[2][1];
  rmat.m_Mat[1][1] = m_Mat[1][0]*mat.m_Mat[0][1] + m_Mat[1][1]*mat.m_Mat[1][1] + m_Mat[1][2]*mat.m_Mat[2][1];
  rmat.m_Mat[1][2] = m_Mat[2][0]*mat.m_Mat[0][1] + m_Mat[2][1]*mat.m_Mat[1][1] + m_Mat[2][2]*mat.m_Mat[2][1];

  rmat.m_Mat[2][0] = m_Mat[0][0]*mat.m_Mat[0][2] + m_Mat[0][1]*mat.m_Mat[1][2] + m_Mat[0][2]*mat.m_Mat[2][2];
  rmat.m_Mat[2][1] = m_Mat[1][0]*mat.m_Mat[0][2] + m_Mat[1][1]*mat.m_Mat[1][2] + m_Mat[1][2]*mat.m_Mat[2][2];
  rmat.m_Mat[2][2] = m_Mat[2][0]*mat.m_Mat[0][2] + m_Mat[2][1]*mat.m_Mat[1][2] + m_Mat[2][2]*mat.m_Mat[2][2];
  *this = rmat;
  return *this;
}

// Matrix / Scalar operators
Mat3x3 Mat3x3::operator*(float scale)
{
  Mat3x3 rmat;
  rmat.m_Mat[0][0] = m_Mat[0][0] * scale;
  rmat.m_Mat[0][1] = m_Mat[0][1] * scale;
  rmat.m_Mat[0][2] = m_Mat[0][2] * scale;

  rmat.m_Mat[1][0] = m_Mat[1][0] * scale;
  rmat.m_Mat[1][1] = m_Mat[1][1] * scale;
  rmat.m_Mat[1][2] = m_Mat[1][2] * scale;

  rmat.m_Mat[2][0] = m_Mat[2][0] * scale;
  rmat.m_Mat[2][1] = m_Mat[2][1] * scale;
  rmat.m_Mat[2][2] = m_Mat[2][2] * scale;
  return rmat;
}

Mat3x3& Mat3x3::operator*=(float scale)
{
  m_Mat[0][0] *= scale;
  m_Mat[0][1] *= scale;
  m_Mat[0][2] *= scale;

  m_Mat[1][0] *= scale;
  m_Mat[1][1] *= scale;
  m_Mat[1][2] *= scale;

  m_Mat[2][0] *= scale;
  m_Mat[2][1] *= scale;
  m_Mat[2][2] *= scale;
  return *this;
}

// Matrix / Vector operators
Vec3 Mat3x3::operator*(const Vec3 &vec)
{
  Vec3 rvec;
  rvec.m_X = m_Mat[0][0] * vec.m_X + m_Mat[0][1] * vec.m_Y + m_Mat[0][2] * vec.m_Z;
  rvec.m_Y = m_Mat[1][0] * vec.m_X + m_Mat[1][1] * vec.m_Y + m_Mat[1][2] * vec.m_Z;
  rvec.m_Z = m_Mat[2][0] * vec.m_X + m_Mat[2][1] * vec.m_Y + m_Mat[2][2] * vec.m_Z;
  return rvec;
}

// Bool overloading
bool Mat3x3::operator==(const Mat3x3 &mat)
{
  bool isEqual = true;
  for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
    if(m_Mat[i][j] != mat.m_Mat[i][j])
    {
      isEqual = false;
      break;
    }
  return isEqual;
}

bool Mat3x3::operator!=(const Mat3x3 &mat)
{
  bool isNotEqual = false;
  for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
    if(m_Mat[i][j] != mat.m_Mat[i][j])
    {
      isNotEqual = true;
      break;
    }
  return isNotEqual;
}

///////////////////////////////////////////////////
