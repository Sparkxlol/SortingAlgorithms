#include <iostream>
#include "Sorter.h"

int main()
{
	int testArr[] = { 4, 6, 1, 2, 5, 3 };
	Sorter::selectionSort(testArr, 6);
	for (int i = 0; i < 6; i++)
		std::cout << testArr[i] << " ";
	std::cout << "\n";
}

