#include "MathTest.h"

Task::Task() {
	num_1 = rand() % 100;
	num_2 = rand() % 100;
	int num = rand() % 4;
	switch (num) {
	case 0:operation = '+';break;
	case 1:operation = '-';break;
	case 2:operation = '*';break;
	case 3:operation = '/';}
}
Task::Task(int barrier_min, int barrier_max, char _operation) {
	if (barrier_min > barrier_max) { throw std::logic_error("min > max barrier"); }
	if (barrier_min < 0 or barrier_max < 0) { throw std::logic_error("barrier must be > 0"); }

	if (barrier_max == barrier_min) { num_1 = barrier_min;num_2 = barrier_min; }
	else{
		num_1 = rand() % (barrier_max - barrier_min)+barrier_min;
		num_2 = rand() % (barrier_max - barrier_min) + barrier_min;
	}

	if (_operation == '\0') {
		int num = rand() % 4;
		switch (num) {
		case 0:operation = '+';break;
		case 1:operation = '-';break;
		case 2:operation = '*';break;
		case 3:operation = '/';}
	}
	else if(_operation == '+' or _operation == '-' or _operation == '*' or _operation == '/') {
		operation = _operation;
	}
	else {
		throw std::logic_error("No way operation");
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