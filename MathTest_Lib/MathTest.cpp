#include "MathTest.h"

Task::Task() {
	num_1 = rand() % 100;
	num_2 = (rand() % 99) + 1;
	int num = rand() % 4;
	switch (num) {
	case 0:operation = '+';answer = num_1 + num_2;break;
	case 1:operation = '-';answer = num_1 - num_2;break;
	case 2:operation = '*';answer = num_1 * num_2;break;
	case 3:operation = '/';answer = num_1 / num_2;}
}
Task::Task(int barrier_min, int barrier_max, char _operation) {
	if (barrier_min > barrier_max) { throw std::logic_error("min > max barrier"); }
	if (barrier_min < 0 or barrier_max <= 0) { throw std::logic_error("barrier must be > 0"); }
	if (_operation != '+' and _operation != '-' and _operation != '*' and _operation != '/' and _operation != '\0') { throw std::logic_error("No way operation"); }

	if (barrier_max == barrier_min) { num_1 = barrier_min;num_2 = barrier_min; }
	else{
		num_1 = rand() % (barrier_max - barrier_min)+barrier_min;
		num_2 = rand() % (barrier_max - barrier_min) + barrier_min;
		if (num_2 == 0) { num_2++; }
	}
	operation = (operation == '\0') ? "+-*/"[rand() % 4] : _operation;
	switch (operation) {
	case '+':answer = num_1 + num_2;break;
	case '-':answer = num_1 - num_2;break;
	case '*':answer = num_1 * num_2;break;
	case '/':answer = num_1 / num_2;
	}
}

int Task::get_num_1() {
	return num_1;
}
int Task::get_num_2() {
	return num_2;
}
char Task::get_operation() {
	return operation;
}

MathTest::MathTest(int _count) {
	if (_count <= 0) { throw std::logic_error("count must be > 0"); }
	this->tasks = new Task*[_count];
	for (int i = 0;i < _count;++i) {
		tasks[i] = new Task();
	}
	this->count = _count;
	this->user_answer = new int[_count];
	this->correct_answer = 0;
}
MathTest::MathTest(int _count, int min, int max) {
	if (_count <= 0) { throw std::logic_error("count must be > 0"); }
	this->tasks = new Task*[_count];
	for (int i = 0;i < _count;++i) {
		tasks[i] = new Task(min, max);
	}
	this->count = _count;
	this->user_answer = new int[_count];
	this->correct_answer = 0;
}
MathTest::MathTest(int _count, int min, int max,char _operation) {
	if (_count <= 0) { throw std::logic_error("count must be > 0"); }
	this->tasks = new Task*[_count];
	for (int i = 0;i < _count;++i) {
		tasks[i] = new Task(min, max,_operation);
	}
	this->count = _count;
	this->user_answer = new int[_count];
	this->correct_answer = 0;
}
MathTest::~MathTest() {
	for (int i = 0;i < count;++i) {
		delete tasks[i];
	}
	delete[] tasks;
	tasks = nullptr;
}
void MathTest::run(){
	
}