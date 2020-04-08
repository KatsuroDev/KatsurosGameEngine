#ifndef VECTOR2_H
#define VECTOR2_H

class Vec2
{
public:
    float m_X, m_Y;

    Vec2() {}
    Vec2(const Vec2& vec);
    Vec2(float x, float y);

    float Length();
    float Dot(const Vec2& vec);
    void Normalize();

    /* operator overloading */
    // vector/vector overloading
    Vec2 operator+ (const Vec2 &right);
    Vec2 operator- (const Vec2 &right);

    // this vector overloading
    Vec2 operator- ();

    // vector/scalar overloading
    Vec2 operator* (float scale);
    Vec2 operator/ (float scale);
};

#endif
