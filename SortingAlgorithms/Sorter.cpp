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
void Sorter::bubbleSort(int arr[], const int size)
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
void Sorter::insertionSort(int arr[], const int size)
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
void Sorter::selectionSort(int arr[], const int size)
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


/*
* Goes from the start -> end of an array.
* If the current num is less than the last, swap them
* and move back one. Otherwise, move forward.
* 
* Big O Best: O(n)
* Big O Worst/Average: O(n^2)
* Stable
*/
void Sorter::gnomeSort(int arr[], const int size)
{
	int i = 1;
	while (i < size)
	{
		if (i == 0 || arr[i] >= arr[i - 1])
			i++;
		else
		{
			swap(arr, i, i - 1);
			i--;
		}
	}
}


/*
* Useful for uniformly distributed range of numbers 
* Creates buckets and insert each index into the corresponding bucket.
* These buckets are then sorting with any algorithm (bubble in this case).
* 
* Big O:
* Stability dependent on internal sort used
*/
void Sorter::bucketSort(int arr[], const int size, const int numBuckets)
{
	std::vector<std::vector<int>> newArr;
	int max = 0;
	int min = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	int range = (max - min) / numBuckets;

	// Pushs back each number into their corresponding bucket
	for (int i = 0; i < size; i++)
	{
		int index = arr[i] / numBuckets;
		if (index >= newArr.size())
			newArr.push_back({});
		newArr.at(index).push_back(arr[i]);
	}

	// Simplified bubble sort for every bucket.
	for (int i = 0; i < newArr.size(); i++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
					swap(arr, j, j + 1);
			}
		}
	}

	// Combines each array
	int index = 0;
	for (int i = 0; i < newArr.size(); i++)
	{
		for (int j = 0; j < newArr.at(i).size(); j++)
		{
			arr[index] = newArr.at(i).at(j);
			index++;
		}
	}
}


void Sorter::radixSort(int arr[], const int size)
{

}


/*
* Counts how far the number is in the sorting array by counting
* the amount of numbers before the number in the array.
* This then is used to find the index where each number starts
* 
* Big O: O(n+k)		k: range of numbers
* Stable if built from back -> start
*/
void Sorter::countingSort(int arr[], const int size)
{
	// Finds max value
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	int* countArr = new int[max + 1] {};
	int* newArr = new int[size];

	// Finds the amount of each digit in the original array.
	for (int i = 0; i < size; i++)
		countArr[arr[i]]++;

	// Adds the previous amount in the array to the current index.
	for (int i = 1; i <= max; i++)
		countArr[i] = countArr[i] + countArr[i - 1];

	// Takes the number in countArr and decreases it by one, then sets that
	// index in the new array to the old array's corresponding value.
	// REVIEW!!
	for (int i = size - 1; i >= 0; i--)
	{
		newArr[countArr[arr[i]] - 1] = arr[i];
		countArr[arr[i]]--;
	}

	for (int i = 0; i < size; i++)
		arr[i] = newArr[i];

	delete[] newArr;
	delete[] countArr;
}


void Sorter::swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
