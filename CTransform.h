#include "Vec2.h"

class CTransform
{
public:
	Vec2 pos		= { 0.0, 0.0 };
	Vec2 velocity	= { 0.0, 0.0 };
	float angle		= 0;
	Vec2 scale		= { 1.0, 1.0 };

	CTransform(const Vec2& p)
		: pos(p) {}

	CTransform(const Vec2& p, const Vec2& v)
		: pos(p), velocity(v) {}

	CTransform(const Vec2& p, const Vec2& v, float a)
		: pos(p), velocity(v), angle(a) {}

	CTransform(const Vec2& p, const Vec2& v, float a, const Vec2& s)
		: pos(p), velocity(v), angle(a), scale(s) {}
};