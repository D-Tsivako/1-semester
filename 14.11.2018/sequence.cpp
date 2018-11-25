#include <iostream>
#include <math.h>

using namespace std;

void InputArray(int*, int);
void Sequence(int*, int);

int main()
{
	char escape = 'y';
	while (escape == 'y' || escape == 'Y')
	{
		const int N = 100;
		int myarray[N] = { 0 };
		int n;

		while (true)
		{
			cout << "Enter dimention of array <= " << N << " : ";
			cin >> n;
			if (n >= 1 && n <= N)
			{
				break;
			}
			cout << "Invalid data! Try again";
		}
		InputArray(myarray, n);
		Sequence(myarray, n);
		cout << "If you want to continue please enter y or Y" << endl;
		cin >> escape;
		system("cls");
	}
	return 0;
}

void InputArray(int* myarray, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << (i + 1) << "] : ";
		cin >> myarray[i];

	}
}

void Sequence(int* myarray, int n)
{
	bool stdecreasing = true;
	bool decreasing = true;
	bool stincremental = true;
	bool incremental = true;

	for (int i = 0; i <= n - 2; i++)
	{
		if (myarray[i + 1] > myarray[i])
		{
			stdecreasing = false;
			decreasing = false;
		}
		else if (myarray[i + 1] == myarray[i])
		{
			stincremental = false;
			stdecreasing = false;
		}
		else
		{
			stincremental = false;
			incremental = false;
		}

		if (!(stdecreasing || decreasing || stincremental || incremental))
		{
			break;
		}

	}

	if (stdecreasing)
	{
		cout << "Strict decreasing" << endl;
	}
	else if (decreasing)
	{
		cout << "decreasing" << endl;
	}
	else if (stincremental)
	{
		cout << "Strict incremental" << endl;
	}
	else if (incremental)
	{
		cout << "incremental" << endl;
	}
	else
	{
		cout << "not ordered" << endl;
	}
}