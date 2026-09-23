#include "MyTest.h"

void MyTestTask::SetUp(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}
void MyTestMath::SetUp() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

