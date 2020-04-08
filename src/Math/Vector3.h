#ifndef VECTOR3_H
#define VECTOR3_H

class Vec3
{
public:
  float m_X, m_Y, m_Z;

  Vec3() {}
  Vec3(const Vec3 &vec);
  Vec3(float x, float y, float z);

  float Length();
  float Dot(const Vec3& vec);
  Vec3 Cross(const Vec3& vec);
  void Normalize();

  //////////// OPERATOR OVERLOADING ///////////////

  // vector / vector overloading
  Vec3 operator+ (const Vec3& right);
  Vec3 operator- (const Vec3& right);
//  Vec3 operator* (Vec3& right);
  //Vec3 operator/ (Vec3& right);

  // this vector overloading
  Vec3 operator- ();

  // vector/scalar overloading
  Vec3 operator* (float scale);
  Vec3 operator/ (float scale);

};

#endif
