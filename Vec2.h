#pragma once

#include <iostream>
#include <cmath>

class Vec2
{
public:
	float x = 0;
	float y = 0;

	Vec2() {}
	Vec2(float xin, float yin);
	Vec2(const Vec2& vector);

	float distTo(Vec2 target); // get distance vector from this to target vector
	float sqDistTo(Vec2 target); // get squared distance vector from this to target vector

	float angleTo(const Vec2& target); // get this vector angle to target vector)

	float length(); // get vector length

	void normalize(); // NORMALIZE this vector

	const Vec2& normalized(); // get NORMALIZED copy of this vector

	void print() const;

	Vec2& rotateByDegrees(float degrees); // ROTATE this vector
	const Vec2& rotatedByDegrees(float degrees); // get ROTATED copy of this vector

	Vec2& scaleByVector	(const Vec2& vector);
	Vec2& scale			(float scale);
	Vec2& addVector		(const Vec2& vector);
	Vec2& add			(float val);

	Vec2 operator +		(const Vec2& rhs)	const;
	void operator +=	(const Vec2& rhs);
	Vec2 operator +		(float val)			const;
	void operator +=	(float val);

	Vec2 operator -		(const Vec2& rhs)	const;
	void operator -=	(const Vec2& rhs);
	Vec2 operator -		(float val)			const;
	void operator -=	(float val);

	Vec2 operator *		(const Vec2& rhs)	const;
	void operator *=	(const Vec2& rhs);
	Vec2 operator *		(float scale)		const;
	void operator *=	(float scale);

	Vec2 operator /		(const Vec2& rhs)	const;
	void operator /=	(const Vec2& rhs);
	Vec2 operator /		(float scale)		const;
	void operator /=	(float scale);

	bool operator ==	(const Vec2& rhs)	const;
	bool operator !=	(const Vec2& rhs)	const;
};
