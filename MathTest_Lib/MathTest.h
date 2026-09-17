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
	inline int get_num_1() {
		return num_1;
	}
	inline int get_num_2() {
		return num_2;
	}
	inline char get_operation() {
		return operation;
	}
	inline int get_answer() {
		return answer;
	}
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
	inline int get_count() {
		return count;
	}
};

int answer();
char mark(int correct, int total);

