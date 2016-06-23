#pragma once

#include "Point.h"

class Poly {
public:
	Poly();
	Poly(std::vector<Point> pntList);
	~Poly();

	void addPoint(Point, int);
	Point popPoint(int);
	Point getPoint(int);
	Point getCenter();

	void draw();

	void rotate(double);
	void scale(double);
	void translate(double, double);

	std::string toString();
private:
	std::vector<Point> _pntList;
};

