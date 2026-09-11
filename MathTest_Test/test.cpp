#include "pch.h"
#include "MyTest.h"

TEST_F(MyTest, TestConstructor) {

	EXPECT_THROW([]() {Task t(-1, 5, '\0');}(), std::logic_error);
	EXPECT_THROW([]() {Task t(0, -6, '\0');}(), std::logic_error);
	EXPECT_THROW([]() {Task t(1, 5, 'G');}(), std::logic_error);
	EXPECT_THROW([]() {Task t(100, 5, '+');}(), std::logic_error);

	EXPECT_NO_THROW([]() {Task t(1, 5, '\0');}());
	EXPECT_NO_THROW([]() {Task t(8, 45, '/');}());
	EXPECT_NO_THROW([]() {Task t(1, 90);}());
}