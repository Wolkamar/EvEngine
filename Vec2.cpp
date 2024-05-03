#include "Vec2.h"

const float PI = atanf(1.f) * 4.f;

float deg(float radians)
{
	return radians * 180.f / PI;
}
float rad(float degrees)
{
	return degrees * PI / 180.f;
}

Vec2::Vec2(float xin, float yin)
	: x(xin), y(yin) {}

Vec2::Vec2(const Vec2& vector)
	: x(vector.x), y(vector.y) {}

float Vec2::distTo(Vec2 target) const
{
	Vec2 diff = target - *this;
	return diff.length();
}

float Vec2::sqDistTo(Vec2 target) const
{
	Vec2 diff = target - *this;
	return (powf(diff.x, 2) + powf(diff.y, 2));
}

float Vec2::angleTo(const Vec2& target) const
{
	Vec2 diff = target - *this;
	return -(deg(atan2f(diff.y, diff.x)) + this->angle());
}

float Vec2::angle() const
{
	return deg(-atan2f(y, x));
}

float Vec2::angleBetween(const Vec2& target) const
{
	return target.angle() - this->angle();
}

float Vec2::length() const
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

const Vec2& Vec2::normalized() const
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
	float newX = cosf(rad(-degrees)) * x - sinf(rad(-degrees)) * y;
	float newY = sinf(rad(-degrees)) * x + cosf(rad(-degrees)) * y;
	//bug

	x = newX;
	y = newY;

	return *this;
}

const Vec2& Vec2::rotatedByDegrees(float degrees) const
{
	float newX = cosf(rad(-degrees)) * x - sinf(rad(-degrees)) * y;
	float newY = sinf(rad(-degrees)) * x + cosf(rad(-degrees)) * y;

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

Vec2& Vec2::fromAngle(float angle)
{
	Vec2 vector = Vec2(cosf(rad(-angle)), sinf(rad(-angle)));
	return vector;
}

Vec2& Vec2::fromAngle(float angle, float length)
{
	Vec2 vector = Vec2(length * cosf(rad(-angle)), length * sinf(rad(-angle)));
	return vector;
}