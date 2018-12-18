#include <iostream>;
#include "matrix.h";

using namespace std;

void matrixSymmetricReplace(int(*)[M], int);
void matrixRoundReplace(int(*)[M], int);

int main()
{
	int n = -1;
	int matrix[M][M];

	while (n < 0 || n > 50)
	{
		cout << "Choose size of one square in matrix (1-50) : ";
		cin >> n;
	}
	
	n *= 2;

	inputMatrix(matrix, n);


	matrixSymmetricReplace(matrix, n);
	displayMatrix(matrix, n, n);

	matrixRoundReplace(matrix, n);
	displayMatrix(matrix, n, n);

	system("pause");
	return  0;
}

void matrixSymmetricReplace(int(*matrix)[M], int n)
{
	int half = n / 2;
	for (int i = 0; i < half; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < half)
			{
				matrixSwap(matrix, i, j, i + half, j + half);
			}
			else
			{
				matrixSwap(matrix, i, j, i + half, j - half);
			}
		}
	}
}

void matrixRoundReplace(int(*matrix)[M], int n)
{
	n /= 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrixSwap(matrix, i, j, i, j + n);
			matrixSwap(matrix, i, j, i + n, j + n);
			matrixSwap(matrix, i, j, i + n, j);
		}
	}
}