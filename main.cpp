#include <iostream>
#include "Vec2.cpp"

int main()
{
	Vec2 p1(10, 20);
	Vec2 p2(40, 50);

	Vec2 p3 = p1 + p2;

	p3 = p3 * 5;

	p3.print();
	std::cout << "Meow " << p3 << " vector";

	return 0;
}