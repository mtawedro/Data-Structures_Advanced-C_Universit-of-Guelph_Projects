#ifndef SORTING_H
#define SORTING_H

typedef int (*CompareFunc)(void* a, void* b);

typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare);

 int CompareFunctionDecreasing(void* a, void* b);

 int CompareFunctionIncreasing(void* a, void* b); 
 
 int CompareFunctionEven(void* a, void* b) ;

void bubbleSort(int* container, int length,  CompareFunc cf);

void selectionSort(int* container, int length,  CompareFunc cf);

void EvenOddCheck(int* container, int* evenCont, int* oddCont, int n,  CompareFunc cf, int* together, int flag);

void togetherAdd(int count, int countO, int* evenCont, int* oddCont, int *together);

void printArray( int* arr, int length );

void printArrayTemp( int* arr, int length );

#endif
