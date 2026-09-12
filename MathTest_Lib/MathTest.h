#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

struct Task {
	int num_1;
	int num_2;
	char operation;
	int answer;
	Task();
	Task(int barrier_min, int barrier_max, char _operation = '\0');
	int get_num_1();
	int get_num_2();
	char get_operation();
	int get_answer();
};
class MathTest {
private:
	Task** tasks;
	int count;
	int* user_answer;
	int correct_answer;
public:
	MathTest(int _count);
	MathTest(int _count, int _min, int _max);
	MathTest(int _count, int _min, int _max, char _operation);
	~MathTest();
	void run();
	void show_statistic();
	int get_count();
};
class MyTestTask;
class MyTestMath;

int answer();
char mark(int correct, int total);