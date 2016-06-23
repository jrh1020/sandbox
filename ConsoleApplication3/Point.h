#pragma once
class Point
{
public:
	Point();
	Point(double, double);

	double getX();
	double getY();
	std::string toString();

	Point operator=(const double val[]);

private:
	double x, y;
};


Point operator+(Point&, Point&);
Point operator-(Point&, Point&);

Point operator*(Point&, double);
Point operator*(double, Point&);

Point operator/(Point&, double);
Point operator/(double, Point&);

