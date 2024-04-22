class CCollider
{
public:
	float radius = 0.f;

	CCollider(float r)
		: radius(r) {}

	//later
	//bool collision(CCollider& collider)
	//{
	//	Vec2 diff = collider.transform.pos - transform.pos;
	//	return (pow(diff.x, 2) + pow(diff.y, 2)) < pow(radius + collider.radius, 2);
	//}
};