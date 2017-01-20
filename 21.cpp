#include <iostream>

using namespace std;

class Shape
{
	double m_x;
	double m_y;
public:
	Shape(double xVal, double yVal):m_x(xVal), m_y(yVal){
	};
	virtual double square() const = 0;
};

class Rectangle : public Shape
{
	double m_width;
	double m_height;
public:
	Rectangle(double x, double y, double width, double height): Shape(x,y), m_width(width), m_height(height){

	}
	double square() const override
	{
		return m_width*m_height;
	};
};

class Triangle : public Shape
{
	double m_base;
	double m_height;
public:
	Triangle(double x, double y, double base, double height): Shape(x, y), m_base(base), m_height(height){
	}
	double square() const override
	{
		return m_base * m_height / 2;
	};
};

class Circle : public Shape
{
	double m_radius;
	const double m_pi = 3.14;
public:
	Circle(double x, double y, double radius) : Shape(x,y), m_radius(radius){
	}
	double square() const override
	{
		return m_pi * m_radius * m_radius;
	};
};

int main(){
	const int length = 3;
	Shape* shapes[length];
	shapes[0] = new Rectangle(0, 0, 5, 5);
	shapes[1] = new Triangle(0, 0, 5, 5);
	shapes[2] = new Circle(0, 0, 5);
	for (size_t i = 0; i < length; i++)
	{
		cout << shapes[i]->square() << endl;
	}

	for (size_t i = 0; i < length; i++)
	{
		delete shapes[i];
	}
	return 0;
}