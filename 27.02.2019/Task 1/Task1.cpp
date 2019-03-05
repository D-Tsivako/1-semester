#include "ArrayLibrary.h"
#include <iostream>

using namespace std;
using namespace ArrayExtension;

int inputNumber();
int transformIntoInteger(double);
double* deleteArray(double*, int*, int, int, int, int&, key, key);

int main()
{
	int n = inputNumber();
	double* array = allocateMemoryDouble(n);

	cout << "Enter array: ";
	inputArray(array, n);
	displayArray(array, n);

	int* keys = allocateMemory(n);
	keys = createKeys(array, n, transformIntoInteger);
	bubbleSort(array, keys, n, countOfUnitInBinaryPresentation);

	int a, b;
	cout << "Enter number of units";
	a = inputNumber();
	cout << "Enter number of zeros";
	b = inputNumber();

	int dim = 0;
	
	double *newArray = allocateMemoryDouble(n);
	newArray = deleteArray(array, keys, n, b, a, dim, countOfUnitInBinaryPresentation, countOfZerosInBinaryPresentation);
	displayArray(newArray, dim);

	return 0;
}

int inputNumber()
{
	int n;
	cout << "Enter number: ";
	cin >> n;

	return n;
}

int transformIntoInteger(double number)
{
	int transform = (int)number;

	return transform;
}

double* deleteArray(double* array, int* sourse, int n, int zeros, int units, int& dim, key unit, key zero)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}
	
	if (sourse == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	for (int i = 0, j = 0; i < n; i++)
	{
		if (unit(sourse[i]) != units || zero(sourse[i]) != zeros)
		{
			dim++;
		}
	}

	double* result = allocateMemoryDouble(dim);

	for (int i = 0, j = 0; i < n; i++)
	{
		if (unit(sourse[i]) != units || zero(sourse[i]) != zeros)
		{
			result[j] = array[i];
			j++;
		}
	}

	delete[] sourse;

	return result;
}