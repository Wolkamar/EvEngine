#pragma once
#include <random>

int random(int min, int max)
{
	srand(time(NULL));
	return min + (rand() % (1 + max - min));
}