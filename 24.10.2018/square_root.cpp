#include <iostream>
#include <math.h>

using namespace std;

double InputValue();
double InputLimit();
double SquareRoot(double, double);

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		double x = InputValue();
		double lim = InputLimit();
		double sr = SquareRoot(x, lim);

		cout << "The square root: " << sr << endl;

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

double SquareRoot(double x, double lim)
{
	double y_prev = 1;
	double y_next = 0.5 * (y_prev + x / y_prev);

	while (fabs(y_prev - y_next) > lim)
	{
		y_prev = y_next;
		y_next = 0.5 * (y_prev + x / y_prev);
	}


	return y_next;
}