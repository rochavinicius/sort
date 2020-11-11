#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../src/sort.h"

int nrMethods = 6;
int methods[] = { SELECTION, INSERTION, SHELL, QUICK, HEAP, MERGE };

const char * methodName(int method);
void allPositiveElements(void);
void halfSizeArray(void);
void alreadOrdered(void);
void negativeAndPositive(void);
void allNegativeNumbers(void);
void repetedNumbers(void);
void validatedIntMaxAndIntMin(void);
void nullArray(void);
void negativeSize(void);
void oddVector(void);

int main(void) {	
	printf("Running test methods for each algorithm.\n");
	
	allPositiveElements();
	halfSizeArray();
	alreadOrdered();
	negativeAndPositive();
	allNegativeNumbers();
	repetedNumbers();
	validatedIntMaxAndIntMin();
	nullArray();
	negativeSize();
	oddVector();
	
	printf("Finished all tests.\n");
	
	return 0;
}

const char * methodName(int method) {
	switch (method) {
		case SELECTION:
			return "SELECTION";
		case INSERTION:
			return "INSERTION";
		case SHELL:
			return "SHELL";
		case QUICK:
			return "QUICK";
		case HEAP:
			return "HEAP";
		case MERGE:
			return "MERGE";
		default:
			return "INVALID METHOD";
	}
}

void allPositiveElements(void) {
	printf("[TEST]: allPositiveElements\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[10];
		int cont = 10;
        for(int i=0; i < 10; i++)
    	{
    		vector[i] = cont--;
    	}
    	
        sort_array(vector, 10, methods[method]);
		printf(" OK\n");
	}
}

void halfSizeArray(void) {
	printf("[TEST]: halfSizeArray\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[10];
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
		
		printf(" OK\n");
	}
}

void alreadOrdered(void) {
	printf("[TEST]: alreadOrdered\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[10];
		int cont = 1;
    	for(int i=0; i < 10; i++)
    	{
    		vector[i] = cont++;
    	}
    
    	sort_array(vector, 10, methods[method]);
		printf(" OK\n");
	}
}

void negativeAndPositive(void) {
	printf("[TEST]: negativeAndPositive\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[10];
		int cont = -5;
    	for(int i=0; i < 10; i++)
    	{
    		vector[i] = cont++;
    	}
    	
    	sort_array(vector, 10, methods[method]);
		printf(" OK\n");
	}
}

void allNegativeNumbers(void) {
	printf("[TEST]: allNegativeNumbers\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[10];
		int cont = -1;
    	for(int i=0; i < 10; i++)
	    {
    		vector[i] = cont--;
    	}
    	
    	sort_array(vector, 10, methods[method]);
		printf(" OK\n");
	}
}

void repetedNumbers(void) {
	printf("[TEST]: repetedNumbers\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[10];
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
		printf(" OK\n");
	}
}

void validatedIntMaxAndIntMin(void) {
	printf("[TEST]: validatedIntMaxAndIntMin\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[10];
		for(int i=1; i < 9; i++)
    	{
    		vector[i] = 0;
    	}
    	vector[0] = INT_MAX;
    	vector[9] = INT_MIN;
    	
    	sort_array(vector, 10, methods[method]);
		printf(" OK\n");
	}
}

void nullArray(void) {
	printf("[TEST]: nullArray\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
    	
    	sort_array(NULL, 10, methods[method]);
		printf(" OK\n");
	}
}

void negativeSize(void) {
	printf("[TEST]: negativeSize\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[] = {10,9,8,7,6,5,4,3,2,1};
    	
    		sort_array(vector, -1, methods[method]);
		printf(" OK\n");
	}
}

void oddVector(void) {
	printf("[TEST]: oddVector\n");
	
	for (int method = 0; method < nrMethods; method++) {
		printf("\t\tAlgorithm:  %s", methodName(method));
		
		int vector[] = {3,2,1};
    	
    		sort_array(vector, 3, methods[method]);
		printf(" OK\n");
	}
}

