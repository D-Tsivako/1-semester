#include "ArrayLibrary.h"
#include <iostream>

using namespace std;
using namespace ArrayExtension;

int inputNumber();
int tranformIntoHexadecimal(int);
void deleteElements(int*, int, int&);
char letter();
void inputArrayNew(int*, int*, int, char, int&);
bool presence—heck(char, int);

int main()
{
	int n = inputNumber();
	int* array = allocateMemory(n);
	int m = 0;

	cout << "Enter array: ";
	inputArray(array, n);
	displayArray(array, n);

	bubbleSort(array, n);
	deleteElements(array, n, m);
	displayArray(array, n - m);

	bubbleSort(array, n - m, tranformIntoHexadecimal);
	displayArray(array, n - m);

	char a = letter();
	int* arrayNew = allocateMemory(n);
	inputArrayNew(array, arrayNew, n, a, m);
	displayArray(arrayNew, m);

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

int tranformIntoHexadecimal(int number)
{
	int rem = 0;

	while (number)
	{
		rem = number % 16;
		number /= 16;
	}

	return rem;
}

void deleteElements(int* array, int n, int& m)
{
	for (int i = 1; i < n - 1 - m; i++)
	{
		if (array[i] == array[i - 1])
		{
			for (int j = i; j < n; j++)
			{
				array[i] = array[i + 1];
			}

			i--;
			m++;
		}
	}
}

char letter()
{
	char a;

	while (true)
	{
		cout << "Enter letter :";
		cin >> a;
		if (a >= 65 && a <= 70)
		{
			break;
		}
	}
	return a;
}

void inputArrayNew(int* array, int* arrayNew, int n, char a, int& m)
{
	m = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		if (presence—heck(a, array[i]))
		{
			arrayNew[j] = array[i];
			j++;
			m++;
		}
	}
}

bool presence—heck(char a, int number)
{
	while (number)
	{
		int rem = number % 16;
		if (rem == ((int)(a)-55))
		{
			return true;
		}
		number /= 16;
	}

	return false;
}