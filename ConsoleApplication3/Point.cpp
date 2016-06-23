#include "stdafx.h"
#include "Point.h"


Point::Point() : x(0.0), y(0.0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

std::string Point::toString() {
	std::ostringstream sstm;
	sstm << "(" << x << ", " << y << ")";
	return sstm.str();
}

Point Point::operator=(const double val[2]) {
	return Point(val[0], val[1]);
}

Point operator+(Point &a, Point &b) {
	return Point(a.getX() + b.getX(), a.getY() + b.getY());
}

Point operator-(Point &a, Point &b) {
	return Point(a.getX() - b.getX(), a.getY() - b.getY());
}

Point operator*(Point &a, double s) {
	return Point(a.getX() * s, a.getY() * s);
}
Point operator*(double s, Point &a) {
	return a * s;
}

Point operator/(Point &a, double s) {
	return Point(a.getX() / s, a.getY() / s);
}
Point operator/(double s, Point &a) {
	return Point(s / a.getX(), s / a.getY());
}
