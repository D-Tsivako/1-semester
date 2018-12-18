#include <iostream>
#include "matrix.h"

using namespace std;

int MaxLine(int matrix[M][M], int&, int&);

int main()
{
	int n = -1;
	int m = -1;
	int matrix[M][M];

	while (n < 0 || n > 50)
	{
		cout << "Input number of lines of matrix: ";
		cin >> n;

		cout << "Input number of elements in line of matrix: ";
		cin >> m;
	}

	inputMatrix(matrix, n, m);
	displayMatrix(matrix, n, m);

	cout << "The max sum of elements" << MaxLine(matrix, n, m) << endl;

	system("pause");
}

int MaxLine(int matrix[M][M], int& n, int& m)
{
	int maxSum = -1;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;

		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] % 2 != 0)
			{
				sum = 0;
				break;
			}

			sum += abs(matrix[i][j]);
		}

		if (maxSum < sum)
		{
			maxSum = sum;
		}
	}

	return maxSum;
}