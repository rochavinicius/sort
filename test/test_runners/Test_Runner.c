#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(sort)
{
    RUN_TEST_CASE(sort, allPositiveElements);
	RUN_TEST_CASE(sort, halfSizeArray);
	RUN_TEST_CASE(sort, alreadOrdered);
	RUN_TEST_CASE(sort, negativeAndPositive);
	RUN_TEST_CASE(sort, allNegativeNumbers);
	RUN_TEST_CASE(sort, repetedNumbers);
	RUN_TEST_CASE(sort, validatedIntMaxAndIntMin);
}
