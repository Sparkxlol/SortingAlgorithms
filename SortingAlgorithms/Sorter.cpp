#include "Sorter.h"


/*
* Goes through the array moving greater elements higher twice
* until nothing is sorted in a loop.
* Must go twice to check for each index in the array.
* 
* Big O Best: O(n)
* Big O Worst/Average: O(n^2)
* Stable
*/
void Sorter::bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		bool sorted = true;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				sorted = false;
				swap(arr, j, j + 1);
			}
		}
		
		if (sorted)
			return;
	}
}


/*
* Creates a line for each element in the arr >= 1.
* Moves up element each loop and moves the current element
* down the array until the i - 1 is less than the current line element.
* 
* Big O Best: O(n)
* Big O Worst/Average: O(n^2)
* Stable
*/
void Sorter::insertionSort(int arr[], int size)
{
	int current;
	int j;
	for (int i = 1; i < size; i++)
	{
		j = i - 1;
		current = arr[i];
		while (j >= 0 && arr[j] > current)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
	}
}


/*
* Searches through the array for each index and finds the minimum value.
* This value is then moved to the non-sorted front.
* 
* Big O All: O(n^2) 
* Unstable
*/
void Sorter::selectionSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr, min, i);
	}
}


void Sorter::swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
