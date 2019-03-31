#pragma once
#include <iostream>

using namespace std;

class Triangle
{
public:
	Triangle()
	{

	}

	Triangle(double, double, double);

	void setSideA(double x);
	void setSideB(double x);
	void setSideC(double x);

	double getPerimeter() const;

	double getArea() const;

	bool isEquilateral() const;

	bool isIsossceles() const;

	bool equalsTo(Triangle) const;

	bool rectangular() const;

	bool acute() const;

	bool obtuseTriangle() const;
	void setTriangle(double, double, double);

	int compareTo(Triangle);

	void display() const;

	~Triangle();
private:
	double a, b, c;
	int number;
	static bool isTriangleValid(double, double, double z);
	const double accuracy = 0.00001;
	
	double getSideA() const;
	double getSideB() const;
	double getSideC() const;
};

