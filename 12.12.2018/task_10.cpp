#include <iostream>;
#include "matrix.h";

using namespace std;

void LinesReplace(int[M][M], int, int);

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

	LinesReplace(matrix, n, m);
	displayMatrix(matrix, n, m);

	system("pause");
	return  0;
}

void LinesReplace(int matrix[M][M], int n, int m)
{
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m; j++)
		{
			swap(matrix[i][j], matrix[n - 1 - i][j]);
		}
	}
}