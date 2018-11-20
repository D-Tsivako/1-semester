#include <iostream>
#include <math.h>

using namespace std;


void InputArray(int*, int);
char InputSymbol();
void QuantityZeros(int*, int);
void QuantityUnits(int*, int);
void QuantitySymbol(int*, int, char);

int main()
{
	char escape = 'y';
	while (escape == 'y' || escape == 'Y')
	{
		const int N = 100;
		int myarray[N] = { 0 };
		int n;
		int symbol = InputSymbol();
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
		QuantityZeros(myarray, n);
		QuantityUnits(myarray, n);
		QuantitySymbol(myarray, n, symbol);
		cout << "If you want to continue please enter y or Y";
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

char InputSymbol()
{
	char symbol;
	cout << "Enter the symbol(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F): ";
	cin >> symbol;
	cout << symbol;
	return symbol;
}

void QuantityZeros(int* myarray, int n)
{
	int quantity = 0;
	int i = 0;
	int number = myarray[i];
	while (i <= n - 1)
	{
		while (number)
		{
			if (number % 2 == 0)
			{
				quantity++;
			}
			number /= 2;
		}
		cout << "The quantity of zeros in number " << myarray[i] << " is: " << quantity << endl;
		number = myarray[i];
		i++;
		quantity = 0;
	}
}

void QuantityUnits(int* myarray, int n)
{
	int quantity = 0;
	int i = 0;
	int number = myarray[i];
	while (i <= n - 1)
	{
		while (number)
		{
			if (number % 2 == 1)
			{
				quantity++;
			}
			number /= 2;
		}
		cout << "The quantity of units in number " << myarray[i] << " is: " << quantity << endl;
		number = myarray[i];
		i++;
		quantity = 0;
	}
}

void QuantitySymbol(int* myarray, int n, char symbol)
{
	int quantity = 0;
	int i = 0;
	int number = myarray[i];
	int remaider;
	char symbols[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	while (i <= n - 1)
	{
		while (number)
		{


			remaider = number % 16;

			if (symbols[remaider] == symbol)
			{
				quantity++;
			}

			number /= 16;
		}
		cout << "The quantity of symbols in number " << myarray[i] << " is: " << quantity << endl;
		number = myarray[i];
		i++;
		quantity = 0;
	}

	/*char arr[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };;
	int rmd = 0;
	cout << arr[rmd] << endl;*/
}

