#include <iostream>;
#include "matrix.h";

using namespace std;

void matrixFromArray(int(*)[M], int *, int);

int main()
{
	int n = -1;
	int matrix[M][M];
	int myarray[M];

	while (n < 0 || n > 100)
	{
		cout << "Choose the array size (1-100) ";
		cin >> n;
	}

	inputArray(myarray, n);

	matrixFromArray(matrix, myarray, n);
	displayMatrix(matrix, n, n);

	system("pause");
	return  0;
}

void matrixFromArray(int(*matrix)[M], int * myarray, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n - j)
			{
				matrix[i][j] = myarray[n - 1 - (abs(n - (i + j + 1)))];
			}
			else
			{
				matrix[i][j] = myarray[abs(n - (i + j + 1)) - 1];
			}
		}
	}
}