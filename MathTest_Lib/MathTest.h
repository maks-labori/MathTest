#pragma once
#include <iostream>
#include <cmath>
struct Task {
	int num_1;
	int num_2;
	char operation;
	double answer;
	Task();
	Task(int barrier_num_1, int barrier_num_2, char _operation = '\0');
	int get_num_1();
	int get_num_2();
	char get_operation();
};
class MathTest;
class MyTest;
