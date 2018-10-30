#include <iostream>
#include <math.h>

using namespace std;

long long InputNumber();
int MaxDigit(long long);
int MinDigit(long long);
bool IsPrimeNumber(long long);
void Switch(long long);

int main()
{
	char esc = 'y';

	while (esc == 'y' || esc == 'Y')
	{
		long long number = InputNumber();

		cout << "Max digit: " << MaxDigit(number) << endl;
		cout << "Min digit: " << MinDigit(number) << endl;
		Switch(number);

		if (IsPrimeNumber(number))
		{
			cout << number << ": prime number\n";
		}
		else
		{
			cout << number << ": not prime number\n";
		}

		cout << "If you want continue enter y or Y" << endl;
		cin >> esc;
		system("cls");
	}

	return 0;
}

long long InputNumber()
{
	long long number;
	while (true)
	{
		cout << "Enter the value of number:\nnumber = ";
		cin >> number;
		system("cls");
		if (number > 0)
		{
			return number;
		}
	}
}

int MaxDigit(long long number)
{
	int max = 0;

	while (number)
	{
		int digit = number % 10;
		max = __max(max, digit);
		number /= 10;
	}

	return max;
}

int MinDigit(long long number)
{
	int min = 9;

	while (number)
	{
		int digit = number % 10;
		min = __min(min, digit);
		number /= 10;
	}

	return min;
}

bool IsPrimeNumber(long long number)
{

	if (number <= 1)
	{
		return false;
	}

	bool result = true;

	for (int i = 2; i <= sqrt(number); i++)
	{
		if (!(number % i))
		{
			result = false;
			break;
		}
	}
	return result;
}

void Switch(long long number)
{
	int zero = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;

	while (number)
	{
		int digit = number % 10;

		switch (digit)
		{
		case 0:
		{
			zero++;
			break;
		}
		case 1:
		{
			one++;
			break;
		}
		case 2:
		{
			two++;
			break;
		}
		case 3:
		{
			three++;
			break;
		}
		case 4:
		{
			four++;
			break;
		}
		case 5:
		{
			five++;
			break;
		}
		case 6:
		{
			six++;
			break;
		}
		case 7:
		{
			seven++;
			break;
		}
		case 8:
		{
			eight++;
			break;
		}
		case 9:
		{
			nine++;
			break;
		}
		}
		number /= 10;
	}
	cout << "the quantity of zeros: " << zero << endl;
	cout << "the quantity of units: " << one << endl;
	cout << "the quantity of twos: " << two << endl;
	cout << "the quantity of triples: " << three << endl;
	cout << "the quantity of fours: " << four << endl;
	cout << "the quantity of fives: " << five << endl;
	cout << "the quantity of sixes: " << six << endl;
	cout << "the quantity of sevens: " << seven << endl;
	cout << "the quantity of eights: " << eight << endl;
	cout << "the quantity of nines: " << nine << endl;
}
