#include <iostream>
#include <math.h>

using namespace std;

double InputValue();
double InputLimit();
double CosX(double, double);

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		double x = InputValue();
		double lim = InputLimit();
		double cosA = CosX(x, lim);

		cout << "The sum: " << cosA << endl;
		cout << "Cos: " << cos(x) << endl;

		cout << "If you want continue enter y or Y" << endl;
		cin >> esc;
		system("cls");
	}

	system("pause");
	return 0;
}

double InputValue()
{
	double x;
	while (true)
	{
		cout << "Enter the value of x:\nx = ";
		cin >> x;
		system("cls");
		if (x > 0)
		{
			return x;
		}
	}
}

double InputLimit()
{
	double lim;
	while (true)
	{
		cout << "Enter the limit:\nlim = ";
		cin >> lim;
		system("cls");
		if (lim > 0)
		{
			return lim;
		}
	}
}

double CosX(double x, double lim)
{
	double term = 1;
	double sum = 1;
	int n;
	int i = 1;

	cout << "Enter the quantity of terms:\nn = ";
	cin >> n;

	while (fabs(term) > lim && i <= n)
	{
		term *= -x * x / ((2 * i - 1) * 2 * i);
		sum += term;
		
		i++;

	}


	return sum;
}