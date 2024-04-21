#include <iostream>

class Vec2
{
public:
	float x = 0;
	float y = 0;

	Vec2() {}
	Vec2(float xin, float yin)
		: x(xin), y(yin) {}

	Vec2& scale		(float scale)		{ x *= scale; y *= scale; return *this; }
	Vec2& add		(float val)			{ x += val; y += val; return *this; }

	Vec2 operator + (const Vec2& rhs)	{ return Vec2(x + rhs.x, y + rhs.y); }
	Vec2 operator + (float val)			{ return Vec2(x + val, y + val); }

	Vec2 operator * (const Vec2& rhs)	{ return Vec2(x * rhs.x, y * rhs.y); }
	Vec2 operator * (float scale)		{ return Vec2(x * scale, y * scale); }

	bool operator == (const Vec2& rhs)	{ return x == rhs.x && y == rhs.y; }

	float dist(const Vec2& rhs)			{ /*later*/ }

	void print()
	{
		std::cout << "(" << x << ", " << y << ")\n";
	}

	friend std::ostream& operator <<(std::ostream& stream, const Vec2& vector)
	{
		return stream << "(" << vector.x << ", " << vector.y << ")";
	}
};