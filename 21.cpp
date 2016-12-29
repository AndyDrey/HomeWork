#include <iostream>

using namespace std;

class Shape
{
	double x;
	double y;
public:
	Shape(double xVal, double yVal){
		x = xVal;
		y = yVal;
	};
	virtual double square() = 0;
};

class Rectangle : public Shape
{
	double width;
	double height;
public:
	Rectangle(double x, double y, double width, double height): Shape(x,y){
		this->width = width;
		this->height = height;
	}
	double square() override
	{
		return width*height;
	};
};

class Triangle : public Shape
{
	double base;
	double height;
public:
	Triangle(double x, double y, double base, double height): Shape(x, y){
		this->base = base;
		this->height = height;
	}
	double square() override
	{
		return base * height / 2;
	};
};

class Circle : public Shape
{
	double radius;
	double pi = 3.14;
public:
	Circle(double x, double y, double radius) : Shape(x,y){
		this->radius = radius;
	}
	double square() override
	{
		return pi * radius * radius;
	};
};

int main(){
	Rectangle rectangle(0, 0, 5, 5);
	Triangle triangle(0, 0, 5, 5);
	Circle circle(0, 0, 5);
	cout << rectangle.square() << endl;
	cout << triangle.square() << endl;
	cout << circle.square() << endl;
	return 0;
}