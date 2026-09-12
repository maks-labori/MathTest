#pragma once
#include <ctime>
#include <gtest/gtest.h>
#include "MathTest.h"

class MyTestTask : public testing::Test {
protected:
	Task object;
	void SetUp() override;
};
class MyTestMath : public testing::Test {
protected:
	MathTest object;
	void SetUp() override;
};
