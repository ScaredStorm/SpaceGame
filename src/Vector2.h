#pragma once
#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class Vector2
{

public:
    Vector2();
	Vector2(int x, int y);
	static Vector2 zero();
    int x, y;
    
    Vector2 operator+(Vector2& vec);
    Vector2 operator-(Vector2& vec);
    Vector2 operator*(float scalar);
    Vector2 operator/(float scalar);
    
    Vector2& operator+=(const Vector2& vec);
    Vector2& operator-=(const Vector2& vec);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);

};

#endif