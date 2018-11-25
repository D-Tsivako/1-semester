#include<iostream>

using namespace std;

void inputArray(int*, int);
bool CheckIncreasing(int*, int);
int InputNumber(int*, int);
int LinearSearch(int*, int, int);
int BinarySearch(int*, int, int);


int main()
{
	char esc = 'Y';
	while (esc == 'y' || esc == 'Y')
	{

		const int N = 100;

		int array[N] = { 0 };

		int n;

		while (true)
		{
			cout << "Enter dimention of array <= " << N << " :";
			cin >> n;
			if (n >= 1 && n <= N)
			{
				break;
			}

			cout << "Invalid data!" << endl;
		}

		inputArray:
		
		inputArray(array, n);

		if (CheckIncreasing(array, n) == false)
		{
			memset(array, 0, sizeof(array));
			goto inputArray;
		}

		int number = InputNumber(array, n);
		cout << "Number of elements smaller (linear search):  " << LinearSearch(array, n, number) << endl;
		cout << "Number of elements smaller (binary search):  " << BinarySearch(array, n, number) << endl;


		cout << "If you want to continue please enter y or Y";
		cin >> esc;
		system("cls");
	}
	return 0;
}

void inputArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
}

bool CheckIncreasing(int* array, int n)
{
	bool stdecreasing = true;
	bool decreasing = true;
	bool stincremental = true;
	bool incremental = true;

	for (int i = 0; i <= n - 2; i++)
	{
		if (array[i + 1] > array[i])
		{
			stdecreasing = false;
			decreasing = false;
		}
		else if (array[i + 1] == array[i])
		{
			stincremental = false;
			stdecreasing = false;
		}
		else
		{
			stincremental = false;
			incremental = false;
		}
	}
	if (stincremental || incremental)
	{
		return true;
	}
	else
	{
		cout << "Your sequence is decreasing or not ordered, try gain" << endl;
		return false;
	}
}

int InputNumber(int*array, int n)
{
	while (true)
	{
		int number;
		cout << "Enter number : ";
		cin >> number;

		if (number < array[n - 1] || number > array[0])
		{
			return number;
		}

	}
	system("cls");
}

int LinearSearch(int* array, int n, int number)
{
	int quantity = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < number)
		{
			quantity++;
		}
	}

	return quantity;
}


int BinarySearch(int* array, int n, int number)
{
	int left = 0;
	int right = n;
	int midd = 0;

	while (1)
	{
		midd = (left + right) / 2;

		if (number < array[midd])
		{
			right = midd - 1;
		}
		else if (number > array[midd])
		{
			left = midd + 1;
		}
		else
		{
			return midd;
		}
	}
}