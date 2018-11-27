#include <iostream>

using namespace std;

void inputArrayA(char*, int);
void inputArrayB(char*, int);
int FindSubstringIndex(char*, int, char*, int);

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		const int N = 100;
		char arrayA[N] = { 0 };
		char arrayB[N] = { 0 };
		int n;
		int m;

		while (true)
		{
			cout << "Enter dimention of array <= " << N << " : ";
			cin >> n;
			cout << "Enter quantity of simbol you want to find <= " << N << " : ";
			cin >> m;

			if (n >= 1 && n <= N && m >= 1 && m <= N)
			{
				break;
			}
			cout << "Invalid data! Try again";
		}

		cout << "Enter members of the array" << endl;
		inputArrayA(arrayA, n);
		cout << "Enter nearby symbols that you want to find in array" << endl;
		inputArrayB(arrayB, m);

		int index = FindSubstringIndex(arrayA, n, arrayB, m);
		
		if (index == -1)
		{
			cout << "This array doesn't contain your simbols" << endl;
		}
		else
		{
			cout << "The index os symbols in array: " << index << endl;
		}
		
		cout << "If you want to continue please enter y or Y" << endl;
		cin >> esc;
		system("cls");
	}
	return 0;
}

void inputArrayA(char* arrayA, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> arrayA[i];
	}
}

void inputArrayB(char* arrayB, int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> arrayB[i];
	}
}

int FindSubstringIndex(char* arrayA, int n, char* arrayB, int m)
{
	if (m > n)
	{
		return -1;
	}

	int count = 0, index = 0;//qwert  er

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arrayB[j] == arrayA[i + count])
			{
				index = i;
				count++;
				if (j == m - 1)
				{
					return index;
				}
				else
				{
					continue;
				}
			}
			else
			{
				count = 0;
				break;
			}
		}
	}
	return -1;

}