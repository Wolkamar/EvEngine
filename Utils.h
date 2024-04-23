#pragma once
#include <random>
#include "Entity.h"

static class Utils
{
public:
	static int random(int min, int max);

	static bool areCollide(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);
};
