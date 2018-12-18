#include <iostream>;
#include "matrix.h";

using namespace std;

void TaskA(int(*)[M], int);
void TaskB(int(*)[M], int);
void TaskC(int(*)[M], int);
void TaskD(int(*)[M], int);

int main()
{
	int n = -1;
	int matrix[M][M];
	int taskNumber = 0;

	while (taskNumber <= 0 || taskNumber > 4)
	{
		cout << "Input number of the task (1-4) ";
		cin >> taskNumber;
	}

	while (n < 0 || n > 100)
	{
		cout << "Choose the size of matrix (1-100) ";
		cin >> n;
	}

	switch (taskNumber)
	{
	case 1:
		TaskA(matrix, n);
		break;
	case 2:
		TaskB(matrix, n);
		break;
	case 3:
		TaskC(matrix, n);
		break;
	case 4:
		TaskD(matrix, n);
		break;
	}

	displayMatrix(matrix, n, n);

	system("pause");
	return 0;

}

void TaskA(int(*matrix)[M], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j] = n;
			}
			else if (i > j)
			{
				matrix[i][j] = n - i + j;
			}
			else
			{
				matrix[i][j] = 0;
			}

		}
	}
}

void TaskB(int(*matrix)[M], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n / 2)
			{
				if (i > j || (n - (i + 1)) < j)
				{
					matrix[i][j] = 0;
				}
				else
				{
					matrix[i][j] = 1;
				}
			}
			else
			{
				if (i < j || (n - (i + 1)) > j)
				{
					matrix[i][j] = 0;
				}
				else
				{
					matrix[i][j] = 1;
				}
			}
		}
	}
}

void TaskC(int(*matrix)[M], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n / 2)
			{
				if (i >= j || (n - (i + 1)) <= j)
				{
					matrix[i][j] = 1;
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
			else
			{
				if (i <= j || (n - (i + 1)) >= j)
				{
					matrix[i][j] = 1;
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
}

void TaskD(int(*matrix)[M], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || (n - 1 - j) == i)
			{
				matrix[i][j] = j + 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
}