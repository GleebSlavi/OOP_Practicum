#include <iostream>
#include "Location.h"

int main()
{
	Location location1;
	location1.setLocationName("Sofia");
	location1.setCoordinateX(0);
	location1.setCoordinateY(0);

	location1.printData();

	Location location2(location1);
	location2.printData();

	Location location3;
	location3.setLocationName("Dupnitsa");
	location3.setCoordinateX(5.9);
	location3.setCoordinateY(3.7);

	location1 = location3;
	location1.printData();
	return 0;
}