#include "Game.h"

//#define _USE_MATH_DEFINES
//#include <cmath>

int main()
{
	Vec2 A(3, 4);
	Vec2 B(5, 2);
	Vec2 D(0, 4);
	Vec2 E(5, 0);

	std::cout << "Vector A: ";
	A.print();
	std::cout << "Vector B: ";
	B.print();
	std::cout << "Vector D: ";
	D.print();
	std::cout << "Vector E: ";
	E.print();

	std::cout << A.length() << "\t\t" << B.length() << "\t\t" << D.length() << "\t\t" << E.length() << "\n";

	std::cout << A.angle() << "\t" << B.angle() << "\t" << D.angle() << "\t\t" << E.angle() << "\n";

	std::cout << D.distTo(A) << "\t\t" << A.distTo(B) << "\t\t" << B.distTo(E) << "\n";

	std::cout << A.angleTo(D) << "\t\t" << A.angleTo(B) << "\t\t" << B.angleTo(E) << "\n";

	std::cout << A.angleBetween(D) << "\t" << A.angleBetween(B) << "\t\t" << B.angleBetween(E) << "\n";

	float angleAToB = A.angleBetween(B);
	A.rotateByDegrees(angleAToB);
	std::cout << A.angle() << "\n";

	float angleAToD = A.angleBetween(D);
	A.rotateByDegrees(angleAToD);
	std::cout << A.angle() << "\n";

	float angleAToE = A.angleBetween(E);
	A.rotateByDegrees(angleAToE);
	std::cout << "Rotate by " << angleAToE << " " << A.angle() << "\n";

	float angle = B.angle();
	float length = B.length();

	Vec2::fromAngle(angle, length).print();

	//Game g("a2config.txt");
	//g.run();

	return 0;
}