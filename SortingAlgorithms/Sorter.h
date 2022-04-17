#pragma once
class Sorter
{
public:
	static void bubbleSort(int[], int);
	static void insertionSort(int[], int);
	static void selectionSort(int[], int);
private:
	static void swap(int[], int, int);
};

