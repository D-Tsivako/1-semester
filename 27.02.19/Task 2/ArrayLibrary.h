#pragma once

namespace ArrayExtension
{
	typedef int(*key)(int);
	typedef double(*keyD)(int);

	int* allocateMemory(int);
	double* allocateMemoryDouble(int);

	void inputArray(int *, int);

	void inputArray(double *, int);

	void randomArray(int *, int);

	void displayArray(int *, int);
	
	void displayArray(double *, int);

	void bubbleSort(int *, int);

	void bubbleSort(int*, int*, int);

	void bubbleSort(int*, int*, int, int*, int);

	void bubbleSort(int *, int, key);
	//void bubbleSort(int *, int, int(*key)(int));

	void swap(int&, int&);

	int* createKeys(int*, int);

	int* createKeys(int*, int, key);
	
	//int* createKeys(int*, int, int);

	int countOfUnitInBinaryPresentation(int);

	int sqr(int);
}