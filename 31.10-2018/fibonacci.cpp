#include<iostream> 

using namespace std;

int Fibonacci();

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int Number_Fibonacci = Fibonacci();
		cout << Number_Fibonacci << endl;

		cout << " To continue enter y ";
		cin >> esc;
		system("cls");
	}
	return 0;
}


int Fibonacci()
{
	int prev_1 = 0, prev_2 = 1, f = 0;
	while (f <= 100)
	{
		f = prev_1 + prev_2;
		prev_1 = prev_2;
		prev_2 = f;
	}
	return f;
}