#pragma once
using namespace std;

int* allocateMemory(int);
void inputArray(int*, int);
void displauArray(int*, int);

int* allocateMemory(int n)
{
	if (n <= 0)
	{
		return nullptr; //!!!!!!!!!!!!!!
	}

	int* array = new int[n];

	return array;
}

void inputArray(int* array, int n)
{
	for (int* p = array, i = 1; p < array + n; p++, i++)
	{
		cout << "Enter a[" << i << "] = ";
		cin >> *p;
	}
}

void displauArray(int* array, int n)
{
	for (int* p = array, i = 1; p < array + n; p++, i++)
	{
		cout << *p << " ";
	}

	cout << endl;
}