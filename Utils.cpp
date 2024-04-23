#include "Utils.h"

int Utils::random(int min, int max)
{
	srand(time(NULL));
	return min + (rand() % (1 + max - min));
}

bool Utils::areCollide(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2)
{
	float distance = e1->cTransform->pos.sqDistTo(e2->cTransform->pos);
	float rSum = pow(e1->cCollider->radius + e2->cCollider->radius, 2);
	return distance < rSum;
}