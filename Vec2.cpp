#include <iostream>

class Vec2
{
public:
	double x = 0;
	double y = 0;

	Vec2() {}
	Vec2(double xin, double yin)
		: x(xin), y(yin) {}

	double distTo(Vec2 target)
	{
		Vec2 diff = target - *this;
		return sqrtf(powf(diff.x, 2) + powf(diff.y, 2));
	}

	double angleTo(const Vec2& target)
	{
		return atan2f(target.y, target.x);
	}

	double length()
	{
		return sqrtf(powf(x, 2) + powf(y, 2));
	}

	// NORMALIZE this vector
	void normalize()
	{
		double len = length();
		x /= len;
		y /= len;
	}

	// get NORMALIZED copy of this vector
	const Vec2& normalized()
	{
		double len = length();
		return Vec2(x / len, y / len);
	}

	Vec2& scale		(double scale)		{ x *= scale; y *= scale; return *this; }
	Vec2& add		(double val)		{ x += val; y += val; return *this; }

	Vec2 operator + (const Vec2& rhs)	{ return Vec2(x + rhs.x, y + rhs.y); }
	Vec2 operator + (double val)		{ return Vec2(x + val, y + val); }

	Vec2 operator - (const Vec2& rhs)	{ return Vec2(x - rhs.x, y - rhs.y); }
	Vec2 operator - (double val)		{ return Vec2(x - val, y - val); }

	Vec2 operator * (const Vec2& rhs)	{ return Vec2(x * rhs.x, y * rhs.y); }
	Vec2 operator * (double scale)		{ return Vec2(x * scale, y * scale); }

	Vec2 operator / (const Vec2& rhs)	{ return Vec2(x / rhs.x, y / rhs.y); }
	Vec2 operator / (double scale)		{ return Vec2(x / scale, y / scale); }

	bool operator == (const Vec2& rhs)	{ return x == rhs.x && y == rhs.y; }
	bool operator != (const Vec2& rhs)	{ return x != rhs.x || y != rhs.y; }

	void print()
	{
		std::cout << "(" << x << ", " << y << ")\n";
	}

	friend std::ostream& operator <<(std::ostream& stream, const Vec2& vector)
	{
		return stream << "(" << vector.x << ", " << vector.y << ")";
	}
};

/*
	Vector Subsctraction: Destination - Origin = Distance
	Vector Addition: Origin + Distance = Destination
*/