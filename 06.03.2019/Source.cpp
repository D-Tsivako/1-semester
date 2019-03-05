#include <iostream>
#include "ArrayLibrary.h"

using namespace std;
using namespace ArrayExtension;

int inputNumber();
void deleteElements(int*, int, int&);
void inputArrayNew(int*, int*, int, int&);
int shifter(int);
int differenceOfRemainders(int, int, int);
void sort(int*, int, int, int);


int main()
{
	int n = inputNumber();
	int* array = allocateMemory(n);

	cout << "Enter array" << endl;
	inputArray(array, n);
	displayArray(array, n);

	int m = 0;

	int *newArray = allocateMemory(n);
	inputArrayNew(array, newArray, n, m);
	cout << "Array of excess elemets: ";
	displayArray(newArray, m);

	deleteElements(newArray, n, m);
	cout << "Array of shifters: ";
	displayArray(newArray, n - m - 1);

	deleteElements(array, n, m);
	cout << "Array without excess elements: ";
	displayArray(array, n - m);

	int a, b;
	cout << "a: ";
	a = inputNumber();
	cout << "b: ";
	b = inputNumber();

	sort(array, n - m, a, b);
	cout << "Sorted array: ";
	displayArray(array, n - m);

	system("pause");
	return 0;
}

int inputNumber()
{
	int n;
	cout << "Enter number: ";
	cin >> n;

	return n;
}

void deleteElements(int* array, int n, int& m)
{
	m = 0;

	for (int i = 0; i < n - 1 - m; i++)
	{
		for (int j = i + 1; j < n - m; j++)
		{
			if (array[i] == array[j])
			{
				for (int k = j; k < n - m; k++)
				{
					array[k] = array[k + 1];
				}

				i--;
				m++;
			}
		}

	}
}

void inputArrayNew(int* array, int* arrayNew, int n, int& m)
{
	m = 0;
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i] == array[j])
			{
				arrayNew[k] = shifter(array[i]);
				k++;
				m++;
			}
		}

	}
}

int shifter(int number)
{
	int rem = 0;
	int newNumber = 0;
	int i = 0;
	int n = number;

	while (number)
	{
		rem = number % 10;
		number /= 10;
		i++;
	}
	rem = 0;


	for (int j = i; j > 0; j--)
	{
		rem = n % 10;
		newNumber += rem * pow(10, j - 1);
		n /= 10;
	}

	return newNumber;
}

int differenceOfRemainders(int number, int a, int b)
{
	int remA, remB, dif;

	remA = number / a;
	remB = number / b;

	if (remA > remB)
	{
		dif = remA - remB;
	}
	else
	{
		dif = remB - remA;
	}

	return dif;
}

void sort(int* array, int n, int a, int b)
{
	bool swapped = true;

	while (swapped)
	{
		swapped = false;

		for (int i = 0; i < n - 1; i++)
		{
			if (differenceOfRemainders(array[i], a, b) < differenceOfRemainders(array[i + 1], a, b))
			{
				swap(array[i], array[i + 1]);

				swapped = true;
			}
		}
	}
}