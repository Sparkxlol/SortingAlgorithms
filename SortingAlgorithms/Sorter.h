#pragma once
#include <iostream>
#include <vector>

class Sorter
{
public:
	static void bubbleSort(int[], const int);
	static void insertionSort(int[], const int);
	static void selectionSort(int[], const int);
	static void gnomeSort(int[], const int);
	static void bucketSort(int[], const int, const int);
	static void countingSort(int[], const int);
	static void radixSort(int[], const int);
	static void mergeSort(int[], const int, const int);
private:
	static void digitCountingSort(int[], const int, const int);
	static void swap(int[], int, int);
};

