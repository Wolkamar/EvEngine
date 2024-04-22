#include "CTransform.cpp"

class CCollider
{
public:
	CTransform transform;
	double radius;

	bool collision(CCollider& collider)
	{
		Vec2 diff = collider.transform.pos - transform.pos;
		return (pow(diff.x, 2) + pow(diff.y, 2)) < pow(radius + collider.radius, 2);
	}
};