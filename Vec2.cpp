#include "Vec2.h"

Vec2::Vec2(float xin, float yin)
	: x(xin), y(yin) {}

float Vec2::distTo(Vec2 target)
{
	Vec2 diff = target - *this;
	return diff.length();
}

float Vec2::sqDistTo(Vec2 target)
{
	Vec2 diff = target - *this;
	return (powf(diff.x, 2) + powf(diff.y, 2));
}

float Vec2::angleTo(const Vec2& target)
{
	const float pi = atan(1) * 4;
	Vec2 diff = target - *this;
	return -atan2f(diff.y, diff.x) * 180.f / pi;
}

float Vec2::length()
{
	return sqrtf(powf(x, 2) + powf(y, 2));
}

void Vec2::normalize()
{
	float len = length();
	if (len > 0)
	{
		x /= len;
		y /= len;
	}
}

const Vec2& Vec2::normalized()
{
	float len = length();
	return Vec2(x / len, y / len);
}

void Vec2::print() const
{
	std::cout << "(" << x << ", " << y << ")\n";
}

//rotating
Vec2& Vec2::rotateByDegrees(float degrees)
{
	const float pi = atan(1) * 4;
	float newX = cos(-degrees * pi / 180.f) * x - sin(-degrees * pi / 180.f) * y;
	float newY = sin(-degrees * pi / 180.f) * x + cos(-degrees * pi / 180.f) * y;

	x = newX;
	y = newY;

	return *this;
}

const Vec2& Vec2::rotatedByDegrees(float degrees)
{
	const float pi = atan(1) * 4;
	float newX = cos(-degrees * pi / 180.f) * x - sin(-degrees * pi / 180.f) * y;
	float newY = sin(-degrees * pi / 180.f) * x + cos(-degrees * pi / 180.f) * y;

	return Vec2(newX, newY);
}

//scaling
Vec2& Vec2::scaleByVector(const Vec2& vector)
{
	x *= vector.x; y *= vector.y; return *this;
}
Vec2& Vec2::scale(float scale)
{
	x *= scale; y *= scale; return *this;
}
//adding
Vec2& Vec2::addVector(const Vec2& vector)
{
	x += vector.x; y += vector.y; return *this;
}
Vec2& Vec2::add(float val)
{
	x += val; y += val; return *this;
}

//addition operators	--------------------
	//by vector
Vec2 Vec2::operator + (const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}
void Vec2::operator += (const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}
//by value
Vec2 Vec2::operator + (float val) const
{
	return Vec2(x + val, y + val);
}
void Vec2::operator += (float val)
{
	x += val;
	y += val;
}
//----------------------------------------
//subsctraction operators	--------------------
	//by vector
Vec2 Vec2::operator - (const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}
void Vec2::operator -= (const Vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}
//by value
Vec2 Vec2::operator - (float val) const
{
	return Vec2(x - val, y - val);
}
void Vec2::operator -= (float val)
{
	x -= val;
	y -= val;
}
//----------------------------------------

//multiplication operators	--------------------
	//by vector
Vec2 Vec2::operator * (const Vec2& rhs) const
{
	return Vec2(x * rhs.x, y * rhs.y);
}
void Vec2::operator *= (const Vec2& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
}
//by value
Vec2 Vec2::operator * (float val) const
{
	return Vec2(x * val, y * val);
}
void Vec2::operator *= (float val)
{
	x *= val;
	y *= val;
}
//----------------------------------------

//division operators		--------------------
	//by vector
Vec2 Vec2::operator / (const Vec2& rhs) const
{
	return Vec2(x / rhs.x, y / rhs.y);
}
void Vec2::operator /= (const Vec2& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
}
//by value
Vec2 Vec2::operator / (float val) const
{
	return Vec2(x / val, y / val);
}
void Vec2::operator /= (float val)
{
	x /= val;
	y /= val;
}
//----------------------------------------

//compare operators			--------------------
bool Vec2::operator == (const Vec2& rhs) const
{
	return x == rhs.x && y == rhs.y;
}
bool Vec2::operator != (const Vec2& rhs) const
{
	return x != rhs.x || y != rhs.y;
}
//----------------------------------------
