#include<iostream>

using namespace std;

void EquivalenceRelation(char*, int, char*, int);
void OrderRelation(char*, int, char*, int);
void inputArrayA(char*, int);
void inputArrayB(char*, int);
void AnotherWayOfComparing(char*, char*);

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
			cout << "Enter dimention of arrayA <= " << N << " : ";
			cin >> n;
			cout << "Enter dimention of arrayB <= " << N << " : ";
			cin >> m;

			if (n >= 1 && n <= N && m >= 1 && m <= N)
			{
				break;
			}
			cout << "Invalid data! Try again";
		}

		cout << "Enter members of the arrayA" << endl;
		inputArrayA(arrayA, n);
		cout << "Enter members of the arrayB" << endl;
		inputArrayB(arrayB, m);
		EquivalenceRelation(arrayA, n, arrayB, m);
		OrderRelation(arrayA, n, arrayB, m);
		AnotherWayOfComparing(arrayA, arrayB);

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

void EquivalenceRelation(char* arrayA, int n, char* arrayB, int m)
{
	if (strcmp(arrayA, arrayB) == 0)
	{
		cout << "Your arrays are equal" << endl;
	}
	else
	{
		cout << "Your arrays aren't equal" << endl;
	}
}

void OrderRelation(char* arrayA, int n, char* arrayB, int m)
{
	bool equal = true;
	bool less = true;
	bool greater = true;
	int i = 0;
	int j = 0;

	if (n == m)
	{
		while (i < n && j < m)
		{
			if (arrayA[i] > arrayB[j])
			{
				equal = false;
				less = false;
			}
			else if (arrayA[i] < arrayB[j])
			{
				equal = false;
				greater = false;
			}
			else
			{
				less = false;
				greater = false;
			}

			i++;
			j++;
		}

		if (equal)
		{
			cout << "Arrays are equal" << endl;
		}
		else if (less)
		{
			cout << "ArrayA less than arrayB" << endl;
		}
		else
		{
			cout << "ArrayA greater than arrayB" << endl;
		}
	}
	else if (n > m)
	{
		cout << "ArrayA greater than arrayB" << endl;
	}
	else
	{
		cout << "ArrayA less than arrayB" << endl;
	}
}

void AnotherWayOfComparing(char* arrayA, char* arrayB)
{
	if (strcmp(arrayA, arrayB) > 0)
	{
		cout << "A>B" << endl;
	}
	else if (strcmp(arrayA, arrayB) < 0)
	{
		cout << "A<B" << endl;
	}
	else
	{
		cout << "A=B" << endl;
	}
}