/*
 * =====================================================================================
 *
 *       Filename:  swap.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/30/2014 04:48:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include"sort.h"
//#include"cuda_sort.h"
#include<string.h>
#include<stdlib.h>

clock_t start, end;
double elapsed_time;
int numberOfComparisons;
int numberOfSwaps;


void selection_sort(int *array, int size){
    int i, j, min, aux;

    if (array == NULL || size < 0)
        return;

      for (i = 0; i < (size-1); i++){
        min = i;
        for (j = (i+1); j < size; j++) {
            numberOfComparisons++;
            if(array[j] < array[min]){
                min = j;
              }
        }
        if (i != min){
            aux = array[i];
              array[i] = array[min];
              array[min] = aux;
              numberOfSwaps++;
        }
    }
}


void insertion_sort(int *array, int size) {
   int i, j, selected;

    if (array == NULL || size < 0)
        return;

   for (i = 1; i < size; i++){
      selected = array[i];
      j = i - 1;
      while ((j >= 0) && (selected < array[j])) {
         array[j+1] = array[j];
         j--;
         numberOfComparisons++;
      }
      numberOfSwaps++;
      array[j+1] = selected;
   }
}

void shell_sort(int *array, int size) {
    int i , j , value;
    int gap = 1;

    if (array == NULL || size < 0)
        return;

    while(gap < size) {
        gap = 3*gap+1;
    }
    while (gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = array[i];
            j = i - gap;
            while (j >= 0 && value < array[j]) {
                array [j + gap] = array[j];
                j -= gap;
                numberOfComparisons++;
                numberOfSwaps++;
            }
            array [j + gap] = value;
        }
    }
}

void quick_sort(int *array, int left, int right) {
    int i, j, pivot, y;
    i = left;
    j = right;

    if (array == NULL || left < 0 || right < 0)
        return;

    pivot = array[(i+j) / 2];

    while(i <= j) {
        while(array[i] < pivot && i < right){
            i++;
            numberOfComparisons++;
        }
        while(array[j] > pivot && j > left){
            j--;
            numberOfComparisons++;
        }
        if(i <= j){
            y = array[i];
            array[i] = array[j];
            array[j] = y;
            i++;
            j--;
            numberOfSwaps++;
        }
    }
    /** Recursive call for the function to the left part of the array */
    if(j > left){
        quick_sort(array, left, j);
    }

    /** Recursive call for the function to the right part of the array */
    if(i < right){
        quick_sort(array, i, right);
    }
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heap_sort(int *arr, int n) 
{ 
    if (arr == NULL || n < 0)
        return;

    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(&arr[0], &arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

/*void heap_sort(int array[], int n){
    int i = n/2, father, child, t;

    for(;;) {
        if (i > 0) {
            i--;
            t = array[i];
        }
        else {
            n--;
            if (n == 0)
               return;
            t = array[n];
            array[n] = array[0];
        }

        father = i;

        //Compare with the left child
        child = i*2;

        while (child < n){
            if ((child + 1 < n)  &&  (array[child + 1] > array[child])){
              	child++;
            	numberOfComparisons++;
            }
          	if (array[child] > t){
             	numberOfComparisons++;
             	array[father] = array[child];
             	father = child;
             	child = father*2 + 1;
             	numberOfSwaps++;
          	} else break;
      	}
     	 array[father] = t;
   	}
}*/

void top_down_merge(int* a,int begin,int end,int* b){
    int middle = (end+begin)/2;
    int i0 = begin;
    int i1 = middle;
    int index;
    int n = end-begin;

    if(n < 2){
        return;
    }

    top_down_merge(a, begin, middle, b);
    top_down_merge(a, middle, end, b);

    for (index = begin; index < end; index++) {
        if (i0 < middle && (i1 >= end || a[i0] <= a[i1])){
            b[index] = a[i0];
            i0++;
        }else{
            b[index] = a[i1];
            i1++;
        }
        numberOfComparisons++;
        numberOfSwaps++;
    }

    memcpy((a+begin),(b+begin),sizeof(int)*(n));
    numberOfSwaps+= n;
}

void merge_sort(int* a,int n){
    if (a == NULL || n < 0)
        return;

    int* b = (int*)malloc(sizeof(int)*n);
    top_down_merge(a, 0, n, b);
    free(b);
}

/**
 * Method that receives a pointer to an array that will be sorted,
 * his size and the constant of the method that will be used
 * @param  array  Array to be sorted
 * @param  size   Size of the array
 * @param  method Sorting algorithm constant
 * @return        Pointer to the sorted array
 */
int* sort_array(int *array, int size, int method){

    switch(method){
        case SELECTION:
            start = clock();
            selection_sort(array, size);
            end = clock();
        break;

        case INSERTION:
            start = clock();
            insertion_sort(array, size);
            end = clock();
        break;

        case SHELL:
            start = clock();
            shell_sort(array, size);
            end = clock();
        break;

        case QUICK:
            start = clock();
            quick_sort(array, 0, size - 1);
            end = clock();
        break;

        case HEAP:
            start = clock();
            heap_sort(array, size);
            end = clock();
        break;

        case MERGE:
            start = clock();
            merge_sort(array, size);
            end = clock();
        break;
/*
        case GPUQUICK:
            start = clock();
            gpu_qsort(array,size);
            end = clock();
        break;

        case GPUMERGE:
            start = clock();
            gpumerge_sort(array,size);
            end = clock();
*/            
    }
    elapsed_time = (((double)(end-start))/CLOCKS_PER_SEC);
    return array;
}

double get_elapsed_time(){
    return elapsed_time;
}

int get_swaps(){
    return numberOfSwaps;
}

int get_comparisons(){
    return numberOfComparisons;
}
