// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Poly.h"
#include "XML.h"

int main(int argc, _TCHAR* argv[])
{
	//std::vector<Point> pntList;

	//unsigned int n = 0;
	//do {
	//	std::cout << "Enter the number of sides: ";
	//	std::cin >> n;
	//} while (n == 0);

	//for (int i = 0; i < n; i++) {
	//	double x, y = 0.0;
	//	std::cout << "Enter X Y: ";
	//	std::cin >> x >> y;
	//	pntList.push_back(Point(x, y));
	//}

	//Poly ngon(pntList);
	//std::cout << "Printed as a polygon: "
	//		  << ngon.toString() << std::endl
	//		  << ngon.getCenter().toString() << std::endl;
	//OutputDebugString(ngon.toString());
	
	XML xmfile("C:\\Users\\Jacob\\Desktop\\test.xml");
	xmfile.open("C:\\Users\\Jacob\\Desktop\\test.xml");
	system("PAUSE");
	return EXIT_SUCCESS;
}

