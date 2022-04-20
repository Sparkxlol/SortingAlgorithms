#include <iostream>
#include "Sorter.h"


int main()
{
	int testArr[] = { 4, 63, 199, 23, 5, 3 };
	Sorter::radixSort(testArr, 6);
	for (int i = 0; i < 6; i++)
		std::cout << testArr[i] << " ";
	std::cout << "\n";
}

