#include <iostream>
#include <math.h>

using namespace std;

int InputNumber();
char InputSymbol();
int QuantityUnits(int);
int QuantityZeros(int);
int QuantitySymbols(int, char);

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int number = InputNumber();
		char symbol = InputSymbol();
		cout << "The quatity of units: " << QuantityUnits(number) << endl;
		cout << "The quatity of zeros: " << QuantityZeros(number) << endl;
		cout << "The quatity of symbols: " << QuantitySymbols(number, symbol) << endl;



		cout << "If you want continue enter y or Y" << endl;
		cin >> esc;
		system("cls");
	}
	return 0;
}

int InputNumber()
{
	int number;
	cout << "Enter the number: ";
	cin >> number;

	return number;
}

char InputSymbol()
{
	char symbol;
	cout << "Enter the symbol(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F): ";
	cin >> symbol;

	return symbol;
}

int QuantityUnits(int number)
{
	int remainder = 0;
	int quotient = number;
	int units = 0;

	while (quotient)
	{
		remainder = quotient % 2;

		if (remainder == 1)
		{
			units++;
		}

		quotient = quotient / 2;
	}

	return units;
}

int QuantityZeros(int number)
{
	int remainder;
	int quotient = number;
	int zeros = 0;

	while (quotient)
	{
		remainder = quotient % 2;

		if (remainder == 0)
		{
			zeros++;
		}

		quotient = quotient / 2;
	}

	return zeros;
}

int QuantitySymbols(int number, char symbol)
{
	int remainder = 0;
	int quotient = number;
	int quantity = 0;

	while (quotient)
	{
		remainder = quotient % 16;


		switch (remainder)
		{
		case 0:
		{
			remainder = static_cast<char>('0');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 1:
		{
			remainder = static_cast<char>('1');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 2:
		{
			remainder = static_cast<char>('2');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 3:
		{
			remainder = static_cast<char>('3');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 4:
		{
			remainder = static_cast<char>('4');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 5:
		{
			remainder = static_cast<char>('5');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 6:
		{
			remainder = static_cast<char>('6');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 7:
		{
			remainder = static_cast<char>('7');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 8:
		{
			remainder = static_cast<char>('8');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 9:
		{
			remainder = static_cast<char>('9');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 10:
		{
			remainder = static_cast<char>('A');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 11:
		{
			remainder = static_cast<char>('B');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 12:
		{
			remainder = static_cast<char>('C');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 13:
		{
			remainder = static_cast<char>('D');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 14:
		{
			remainder = static_cast<char>('E');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		case 15:
		{
			remainder = static_cast<char>('F');

			if (remainder == symbol)
			{
				quantity++;
			}
			break;
		}
		}


		quotient = quotient / 16;
	}

	return quantity;
}
