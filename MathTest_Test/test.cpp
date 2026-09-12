#include "pch.h"
#include "MyTest.h"

int main(int argc, char** argv) {
	std::srand(std::time(nullptr));
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


TEST(TestTask, TestThrowConstructor) {

	EXPECT_THROW([]() {Task t(-1, 5, '\0');}(), std::logic_error);
	EXPECT_THROW([]() {Task t(0, -6, '\0');}(), std::logic_error);
	EXPECT_THROW([]() {Task t(1, 5, 'G');}(), std::logic_error);
	EXPECT_THROW([]() {Task t(100, 5, '+');}(), std::logic_error);

	EXPECT_NO_THROW([]() {Task t(1, 5, '\0');}());
	EXPECT_NO_THROW([]() {Task t(8, 45, '/');}());
	EXPECT_NO_THROW([]() {Task t(1, 90);}());
}
TEST(TestTask, TestAnswer) {
	Task t1(5, 5, '+');
	EXPECT_EQ(t1.get_answer(), 10);

	Task t2(10, 10, '/');
	EXPECT_EQ(t2.get_answer(), 1);
}

TEST(TestTask, TestGenerateNum) {
	Task t1;
	EXPECT_GE(t1.get_num_1(), 0);
	EXPECT_LT(t1.get_num_2(), 100);

	Task t2(0, 10);
	EXPECT_GE(t2.get_num_1(), 0);
	EXPECT_LT(t2.get_num_2(), 10);
	
}

TEST(TestMath, TestThrowConstructor) {
	EXPECT_THROW([]() {MathTest m(0);}(), std::logic_error);
	EXPECT_THROW([]() {MathTest m(-5);}(), std::logic_error);
	MathTest m(10);
	EXPECT_EQ(m.get_count(), 10);
	
	EXPECT_THROW([]() {MathTest m(5,5,1);}(), std::logic_error);
	EXPECT_THROW([]() {MathTest m(5, -1,9);}(), std::logic_error);
	EXPECT_THROW([]() {MathTest m(5, 0, 0);}(), std::logic_error);

	




}