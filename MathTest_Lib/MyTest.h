#pragma once
#include <ctime>
#include <gtest/gtest.h>
#include "MathTest.h"

class MyTest : public testing::Test {
protected:
	Task object;
	void SetUp() override;
};
