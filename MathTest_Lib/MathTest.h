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
	int get_num_1()const noexcept;
	int get_num_2()const noexcept;
	char get_operation()const noexcept;
	int get_answer()const noexcept;
};
inline int Task::get_num_1()const noexcept {
	return num_1;
}
inline int Task::get_num_2()const noexcept {
	return num_2;
}
inline char Task::get_operation()const noexcept {
	return Task::operation;
}
inline int Task::get_answer()const noexcept {
	return answer;
}

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
	void run()noexcept;
	void show_statistic()const noexcept;
	int get_count()const noexcept;
	static int answer();
	static char mark(int correct, int total)noexcept;
};
inline int MathTest::get_count()const noexcept {
	return count;
}

