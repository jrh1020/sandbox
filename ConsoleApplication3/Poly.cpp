#include "stdafx.h"
#include "Poly.h"


Poly::Poly() {}

Poly::Poly(std::vector<Point> pntList) : _pntList(pntList) {}

Poly::~Poly() {}

void Poly::addPoint(Point p, int index) {
	_pntList.push_back(p);

}

Point Poly::getCenter() {
	double sumX = 0, sumY = 0;
	int n = 0;
	for (Point p : _pntList) {
		n++;
		sumX += p.getX();
		sumY += p.getY();
	}

	return Point(sumX / n, sumY / n);
}

void Poly::scale(double factor) {
	for (Point p : _pntList) {
		p = p * factor;
	}
}

std::string Poly::toString() {
	std::stringstream sstm;
	sstm << _pntList.begin()->toString();
	for (auto it = _pntList.begin() + 1; it != _pntList.end(); ++it) {
		sstm << ", " << it->toString();
	}	
	return sstm.str();
}