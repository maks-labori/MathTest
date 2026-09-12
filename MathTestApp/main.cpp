#include "MathTest.h"

int main() {
	std::cout << "Hello world";
	std::srand(std::time(nullptr));
	MathTest m(10,0,10);
	m.run();
	m.show_statistic();
	return 0;
}