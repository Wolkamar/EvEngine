#include "Game.h"

#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
	//Vec2 v1(5, 5);
	//Vec2 v2(5, 3);
	//Vec2 v3(10, 0);
	//Vec2 zv(0, 0);

	//Vec2 vr = v1.rotatedByDegrees(45.f);

	//v1.print();
	//vr.print();

	//std::cout << v1.angleTo(v3);
	//std::cout << vr.angleTo(v1);

	//std::cout << atan(1) * 4;

	//std::cout << v1.distTo(v2) << "\n";
	//std::cout << zv.distTo(v1) << "\n";

	Game g("a2config.txt");
	g.run();

	//return 0;
}