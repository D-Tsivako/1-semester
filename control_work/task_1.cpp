#include <iostream>

using namespace std;

int nextSmallerThan(int);
void nextSmallerThanTests();
void getDigit(int, int *);
bool equalArray(int *, int *, int);
void createStartArray(int *, int);

const int M = 10;

int main()
{
	nextSmallerThanTests();

	system("pause");
	return 0;
}

int nextSmallerThan(int number)
{
	int arrayOfNumbers[M];
	int newArrayOfNumbers[M];

	createStartArray(arrayOfNumbers, M);
	getDigit(number, arrayOfNumbers);

	for (int i = number - 1; i > 0; i--)
	{
		getDigit(i, newArrayOfNumbers);

		if (equalArray(arrayOfNumbers, newArrayOfNumbers, M))
		{
			return i;
		}
	}

	return -1;
}

bool equalArray(int * firstArray, int * secondArray, int size)
{
	for (int j = 0; j < size; j++)
	{
		if (firstArray[j] != secondArray[j])
		{
			return false;
		}
	}

	return true;
}

void createStartArray(int * myarray, int size)
{
	for (int i = 0; i < size; i++)
	{
		myarray[i] = 0;
	}
}

void getDigit(int number, int * myarray)
{
	createStartArray(myarray, M);

	while (number > 0)
	{
		int digit = number % 10;
		myarray[digit] += 1;
		number /= 10;
	}

}

void nextSmallerThanTests()
{
	cout << (nextSmallerThan(21) == 12) << endl;
	cout << (nextSmallerThan(531) == 513) << endl;
	cout << (nextSmallerThan(2071) == 2017) << endl;
	cout << (nextSmallerThan(9) == -1) << endl;
	cout << (nextSmallerThan(111) == -1) << endl;
	cout << (nextSmallerThan(135) == -1) << endl;
	cout << (nextSmallerThan(1027) == -1) << endl;
	cout << (nextSmallerThan(-100) == -1) << endl;
}