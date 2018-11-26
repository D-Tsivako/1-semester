#include <iostream>;

using namespace std;


void RandomArray(int*, int);
void LinearSort(int*, int);
void swap(int&, int&);
void displayArray(int*, int);

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
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
		RandomArray(myarray, n);
		displayArray(myarray, n);
		cout << endl;
		LinearSort(myarray, n);
		displayArray(myarray, n);
		cout << endl;

		cout << "If you want to continue please enter y or Y" << endl;
		cin >> esc;
		system("cls");
	}

	return 0;
}

void displayArray(int* myarray, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << myarray[i] << " ";
	}
}

void  RandomArray(int *myarray, int n)
{
	for (int i = 0; i < n; i++)
	{
		myarray[i] = rand() % 100;
	}
}


void LinearSort(int * myarray, int n)
{
	int j;

	for (int i = 1; i < n; i++)
	{
		j = i;
		while (myarray[j] < myarray[j - 1])
		{
			swap(myarray[j], myarray[j - 1]);
			j--;
		}
	}
}


void swap(int & x, int & y)
{
	int t = y;
	y = x;
	x = t;
}