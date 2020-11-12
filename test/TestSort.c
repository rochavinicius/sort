#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(sort);

int nrMethods = 6;
int methods[] = { SELECTION, INSERTION, SHELL, QUICK, HEAP, MERGE };
int vector[10];

TEST_SETUP(sort)
{
}

TEST_TEAR_DOWN(sort)
{
}


TEST(sort, allPositiveElements)
{
	int expected[] ={1,2,3,4,5,6,7,8,9,9};
	
	for (int method = 0; method < nrMethods; method++)
    {
        int cont = 10;
        for(int i=0; i < 10; i++)
    	{
    		vector[i] = cont--;
    	}
    	
        sort_array(vector, 10, methods[method]);
	
	    TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);
	}
}

TEST(sort, halfSizeArray)
{
	int expected[] ={1,2,3,4,5,-9,-9,-9,-9,-9};
	
	for (int method = 0; method < nrMethods; method++)
    {
        int cont = 5;
        for(int i=0; i < 5; i++)
	    {
    		vector[i] = cont--;
    	}

    	for(int i=5; i < 10; i++)
    	{
    		vector[i] = -9;
    	}
	
	    sort_array(vector, 5, methods[method]);
    	
    	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
	}
}

TEST(sort, alreadOrdered)
{
	int expected[] ={1,2,3,4,5,6,7,8,9,10};
	
	for (int method = 0; method < nrMethods; method++)
    {
    	int cont = 1;
    	for(int i=0; i < 10; i++)
    	{
    		vector[i] = cont++;
    	}
    
    	sort_array(vector, 10, methods[method]);
    	
    	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);
	}
}


TEST(sort, negativeAndPositive)
{
	int expected[] ={-5,-4,-3,-2,-1,0,1,2,3,4};
	
	for (int method = 0; method < nrMethods; method++)
    {
    	int cont = -5;
    	for(int i=0; i < 10; i++)
    	{
    		vector[i] = cont++;
    	}
    	
    	sort_array(vector, 10, methods[method]);
    	
	    TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
	}
}

TEST(sort, allNegativeNumbers)
{
	int expected[] ={-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};
	
	for (int method = 0; method < nrMethods; method++)
    {
       	int cont = -1;
    	for(int i=0; i < 10; i++)
	    {
    		vector[i] = cont--;
    	}
    	
    	sort_array(vector, 10, methods[method]);
    	
    	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);
	}	
}

TEST(sort, repetedNumbers)
{
	int expected[] ={1,2,2,2,2,2,3,5,7,9};
	
	for (int method = 0; method < nrMethods; method++)
    {
        int cont = 1;
    	for(int i=0; i < 10; i++)
    	{
    		if( cont % 2  == 0){
    			vector[i] = 2;
    			cont++;
    		}
    		else
    		{	
    			vector[i] = cont++;
    		}
    	}
    	
    	sort_array(vector, 10, methods[method]);
    	
    	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
	}
}

TEST(sort, validatedIntMaxAndIntMin)
{
	int expected[] ={INT_MIN,0,0,0,0,0,0,0,0,INT_MAX};
	
	for (int method = 0; method < nrMethods; method++)
    {
	    for(int i=1; i < 9; i++)
    	{
    		vector[i] = 0;
    	}
    	vector[0] = INT_MAX;
    	vector[9] = INT_MIN;
    	
    	sort_array(vector, 10, methods[method]);
    	
    	TEST_ASSERT_EQUAL_INT_ARRAY(expected, vector, 10);
    }	
}

TEST(sort, nullArray)
{	
    for (int method = 0; method < nrMethods; method++)
    {    	
    	TEST_ASSERT_NULL(sort_array(NULL, 10, methods[method]));
    }	
}

TEST(sort, negativeSize)
{
    int expected[] ={10,9,8,7,6,5,4,3,2,1};
	
    for (int method = 0; method < nrMethods; method++)
    {   
	for(int i=0; i < 10; i++)
    	{
    	    vector[i] = expected[i];
    	}
    	sort_array(vector, -1, methods[method]);
    	
    	TEST_ASSERT_EQUAL_INT_ARRAY(expected, vector, 10);
    }	
}

TEST(sort, oddVector)
{
    int expected[] = {1,2,3};
	
    for (int method = 0; method < nrMethods; method++)
    {   
	int vec[] = {3,2,1};

    	sort_array(vec, 3, methods[method]);
    	
    	TEST_ASSERT_EQUAL_INT_ARRAY(expected, vec, 3);
    }	
}

