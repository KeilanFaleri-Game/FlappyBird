#ifndef __Vector_H__
#define __Vector_H__

namespace fw
{
    static const float PI = 3.1415927f;

    class vec2
    {
    public:
        float x, y;

        vec2() { x = y = 0.0f; }
        vec2(float value) { x = y = value; }
        vec2(float nx, float ny) { x = nx; y = ny; }

        vec2 operator-(const vec2& o) const { return vec2( x - o.x, y - o.y ); }
        vec2 operator*(float o) const { return vec2( x * o, y * o ); }

        void operator+=(const vec2& o) { x += o.x, y += o.y; }

        void Set(float nx, float ny) { x = nx; y = ny; }
        float Length() { return sqrtf( x*x + y*y ); }

        void Normalize() { x /= Length(); y /= Length(); }
    };

} // namespace fw

#endif //__Vector_H__
