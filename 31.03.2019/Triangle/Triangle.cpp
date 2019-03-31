#include "Triangle.h"

#pragma region ctors
Triangle::Triangle(double x, double y, double z)
{
	setSideA(x);
	setSideB(y);
	setSideC(z);

	if (!isTriangleValid(x, y, z))
	{
		throw invalid_argument("Triangle with these sides does not exist");
	}

	if (!isTriangleValid(a, b, c))
	{
		throw invalid_argument("Triangle with these sides does not exist");
	}

	number = 1;
}

double Triangle::getSideA() const
{
	return a;
}
double Triangle::getSideB() const
{
	return b;
}
double Triangle::getSideC() const
{
	return c;
}
#pragma endregion

#pragma region setters
void Triangle::setSideA(double x)
{
	if (x <= 0)
	{
		throw invalid_argument("The side a of the triangle can't be less or equal 0");
	}

	a = x;
}

void Triangle::setSideB(double y)
{
	if (y <= 0)
	{
		throw invalid_argument("The side b of the triangle can't be less or equal 0");
	}

	b = y;
}

void Triangle::setSideC(double z)
{
	if (z <= 0)
	{
		throw invalid_argument("The side c of the triangle can't be less or equal 0");
	}

	c = z;
}

void Triangle::setTriangle(double x, double y, double z)
{
	setSideA(x);
	setSideB(y);
	setSideC(z);

	if (!isTriangleValid(x, y, z))
	{
		throw invalid_argument("Triangle with these sides does not exist");
	}
}

#pragma endregion

double Triangle::getPerimeter() const
{
	return a + b + c;
}

double Triangle::getArea() const
{
	double p = (a + b + c) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

bool Triangle::isEquilateral() const
{
	return a == b && b == c ? true : false;
}

bool Triangle::isIsossceles() const
{
	return a == b || a == c || b == c ? true : false;
}

int Triangle::compareTo(Triangle other)
{
	if (equalsTo(other))
	{
		return 0;
	}

	return (getPerimeter() < other.getPerimeter()) ? -1 : 1;
}

bool Triangle::isTriangleValid(double x, double y, double z)
{
	return !(x + y <= z || y + z <= x || z + x <= y);
}

bool Triangle::equalsTo(Triangle other) const
{
	return fabs(getPerimeter() - other.getPerimeter()) <= accuracy;
}

bool Triangle::rectangular() const
{
	return a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a ? true : false;
}

bool Triangle::acute() const
{
	return a * a + b * b > c * c || a * a + c * c > b * b || b * b + c * c > a * a ? true : false;
}

bool Triangle::obtuseTriangle() const
{
	return a * a + b * b < c * c || a * a + c * c < b * b || b * b + c * c < a * a ? true : false;
}

void Triangle::display() const
{
	cout << "{" << getSideA() << ", " << getSideB() << ", " << getSideC() << "}" << endl;
}

Triangle::~Triangle()
{
	cout << "I'm dead!!!";
}