#include <iostream>
#include <math.h>

using namespace std;

int InputNumber(int, int);
int InputNumber(int = 0);
double SumA(int);
long long SumB(int);
double SumC(int);
double SumD(int);
double SumE(int);
double SumF(int);
double SumG(int);
double SumH(int);
double SumJ(int);
double SumK(int);
void Switch(int);


int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int a;
		cout << "Eneter the number of the sum: ";
		cin >> a;
		Switch(a);
		cout << "If you want continue enter y or Y" << endl;
		cin >> esc;
		system("cls");
	}
	
	system("pause");
	return 0;
}

int InputNumber(int minValue)
{
	int n;
	while (true)
	{
		cout << "Enter the number:\nn = ";
		cin >> n;
		system("cls");
		if (n > minValue)
		{
			return n;
		}
	} 
}

int InputNumber(int minValue, int maxValue)
{
	int n;
	while (true)
	{
		cout << "Enter the number:\nn = ";
		cin >> n;
		system("cls");
		if (n >= minValue && n <= maxValue)
		{
			return n;
		}
	}
}

double SumA(int n)
{
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += 1. / i;
	}

	return sum;
}

long long SumB(int n)
{
	double sum = 0;

	for (int i = 0; i <= n; i++)
	{
		sum += pow(2, i);
		return sum;

	}
}

double SumC(int n)
{
	double sum = 1;

	for (int i = 1; i <= n; i++)
	{
		sum *= (1 + 1. / pow(i, 2));
	}

	return sum;
}

double SumD(int n)
{
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += (pow(-1, i + 1)) / (i*(i + 1));
	}
	return sum;
}

double SumE(int n)
{
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += 1. / (pow(i, 5));
	}

	return sum;
}

double SumF(int n)
{
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += 1. / pow(2 * i + 1, 2);
	}
	return sum;
}

double SumG(int n)
{
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += (pow(-1, i)) / (2 * i + 1);

	}
	return sum;
}

double SumH(int n)
{
	double sum = 0;
	double div = 0;
	int num = 1;

	for (int i = 1; i <= n; i++)
	{
		num *= i;
		div += 1. / i;
		sum += num / div;
	}

	return sum;
}

double SumJ(int n)
{
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum = sqrt(2 + sum);
	}
	return sum;
}

double SumK(int n)
{
	double sum = 0;
	double div = 0;

	for (int i = 1; i <= n; i++)
	{
		div += sin(i*(atan(1) * 4) / 180);
		sum += 1. / div;
	}
	return sum;
}

void Switch(int a)
{
	switch (a)
	{
	case 1: 
	{
		int n = InputNumber();
		double sum = SumA(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 2:
	{
		int n = InputNumber();
		double sum = SumB(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 3:
	{
		int n = InputNumber();
		double sum = SumC(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 4:
	{
		int n = InputNumber();
		double sum = SumD(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 5:
	{
		int n = InputNumber();
		double sum = SumE(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 6:
	{
		int n = InputNumber();
		double sum = SumF(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 7:
	{
		int n = InputNumber();
		double sum = SumG(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 8:
	{
		int n = InputNumber();
		double sum = SumH(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 9:
	{
		int n = InputNumber();
		double sum = SumJ(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	case 10:
	{
		int n = InputNumber();
		double sum = SumK(n);
		cout << "Sum of numbers from " << sum << endl;
		break;
	}
	default:
		cout << "Incorrect sample number" << endl;
	}
}

/*в main вывод функции swich
отдельная функция для swich - занимается посчетом
отдельная функция для факториала
создать inputParameter()
		inputChoice()
		toUpper(char symbol)
сделать перегрузку(пока необязательно




к следующему занятию методичка стр 40 (таблица 7.1 второе задание)*/




