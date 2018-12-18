#pragma once
#include <iostream>

using namespace std;

const int M = 100;

void displayMatrix(int(*)[M], int, int);
void inputArray(int*, int);
void inputMatrix(int(*)[M], int);
void matrixSwap(int(*)[M], int, int, int, int);

void displayMatrix(int(*a)[M], int n, int m)
{
	cout << "Matrix: " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

void inputArray(int * arr, int n)
{
	cout << "Input array: ";

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void inputMatrix(int(*matrix)[M], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Input " << i + 1 << " line of matrix (" << n << " elements) : ";
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void matrixSwap(int(*matrix)[M], int i, int j, int m, int n)
{
	int t = matrix[i][j];
	matrix[i][j] = matrix[m][n];
	matrix[m][n] = t;
}
