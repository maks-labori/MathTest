#include "MathTest.h"

Task::Task() {
	num_1 = rand() % 100;
	num_2 = (rand() % 99) + 1;
	int num = rand() % 4;
	switch (num) {
	case 0:operation = '+';answer = num_1 + num_2;break;
	case 1:operation = '-';answer = num_1 - num_2;break;
	case 2:operation = '*';answer = num_1 * num_2;break;
	case 3:operation = '/';answer = rand() % 10;num_1 = answer * num_2;
	}

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
	operation = (_operation == '\0') ? "+-*/"[rand() % 4] : _operation;
	switch (operation) {
	case '+':answer = num_1 + num_2;break;
	case '-':answer = num_1 - num_2;break;
	case '*':answer = num_1 * num_2;break;
	case '/':answer = rand() % 10;num_1 = answer * num_2;
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

int Task::get_answer() {
	return answer;
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


int MathTest::get_count() {
	return count;
}

void MathTest::run(){
	std::cout << "\nStart math test";
	for (int i = 0;i < count;++i) {
		std::cout << "\nQuestion " << i + 1 << ": " << tasks[i]->get_num_1() << tasks[i]->get_operation() << tasks[i]->get_num_2() << "=";
		try { 
			int us_answer = answer();
			user_answer[i] = us_answer;
			if (us_answer == tasks[i]->get_answer()) { correct_answer++; }
		}
		catch (...) { std::cout << "\nUn corrct input\n";--i;continue; }
	}

}
void MathTest::show_statistic() {
	auto print_line = [this]() {
		std::cout << "\n+--------------+";
		for (int i = 0; i < count; ++i) {
			std::cout << "-----------+"; 
		}
		std::cout << "\n";
		};

	std::cout << "\n| "<< std::setw(12) << "No" << " | ";
	for (int i = 0;i < count;++i) {
		std::cout << std::setw(9) << i+1 << " | ";
	}

	print_line();
	std::cout << "| " << std::setw(12) << "Question" << " | ";
	for (int i = 0;i < count;++i) {
		std::string question = std::to_string(tasks[i]->get_num_1()) + tasks[i]->get_operation() + std::to_string(tasks[i]->get_num_2());
		std::cout << std::setw(9) << question << " | ";
	}

	print_line();
	std::cout << "| " << std::setw(12) << "True answer" << " | ";
	for (int i = 0;i < count;++i) {
		std::cout << std::setw(9) << tasks[i]->get_answer() << " | ";
	}

	print_line();
	std::cout << "| " << std::setw(12) << "Your answer" << " | ";
	for (int i = 0;i < count;++i) {
		std::cout << std::setw(9) << user_answer[i] << " | ";
	}

	print_line();
	std::cout << "| " << std::setw(12) << "Result" << " | ";
	for (int i = 0;i < count;++i) {
		char res = (tasks[i]->get_answer() == user_answer[i]) ? '+' : '-';
		std::cout << std::setw(9) << res << " | ";
	}
	char rate = mark(correct_answer, count);
	std::cout << "\n\nTotal Result : " << correct_answer << "/" << count << "(mark: " << rate << ")\n";
}
int answer() {
	std::string str;
	int ans;
	std::getline(std::cin, str);
	ans = std::stoi(str);
	if(ans){return ans;}
	else if (ans == 0) { return 0; }
	else { throw std::logic_error("it not digit"); }
}
char mark(int correct, int total) {
	double percentage = (static_cast<double>(correct) / total) * 100.0;
	if (percentage >= 95) { return 'A'; }
	if (percentage >= 70) { return 'B'; }
	if (percentage >= 40) { return 'C'; }
	return 'D';
}