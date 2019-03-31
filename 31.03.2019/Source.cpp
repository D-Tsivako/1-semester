#include <iostream>
#include "Triangle.h"

using namespace std;

typedef double(*Key)();

void demo();
Triangle* allocateMemory(int);
void display(Triangle*, int);
void setArrayTriangles(Triangle*, int);

int main()
{
	Triangle triangle(5, 5, 5);

	Triangle* t = allocateMemory(2);
	setArrayTriangles(t, 2);
	display(t, 2);

	Triangle* t = new Triangle();
	cout << t->getPerimeter() << endl;

	cout << sizeof(Triangle) << endl;

	cout << "p = " << triangle.getPerimeter() << endl;

	cout << t[0].equalsTo(t[1]) << endl;
	cout << t[0].compareTo(t[1]) << endl;

	demo();

	system("pause");
	return 0;
}

void demo()
{
	Triangle t1, t2, t3(5, 5, 5);
}

Triangle* allocateMemory(int n)
{
	return new Triangle[n];
}

void display(Triangle* triangles, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		triangles[i].display();
	}
}

void setArrayTriangles(Triangle* triangles, int n)
{
	int x, y, z;

	for (size_t i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		cin >> z;
		triangles[i].setTriangle(x, y, z);
	}

	system("cls");
}