#include "Header.h"
#include"Point.h"
#include <tuple>

int main() {
	//1. std::tuple<>, std::tuple_size<>::value,
	//	Реализуйте функцию печати любого tuple, например:
	std::tuple t1{ 1, 2.2, "abc"};
	std::cout << t1;
	printTuple(t1);
	std::tuple t2{ std::string("abc"), 1, 2.2, Point(1,2) };
	printTuple(t2);
	return 0;
}