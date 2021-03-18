#include <iostream>
#include "Map.h"

int main()
{
	Location location1;
	location1.setLocationName("Sofia");
	location1.setCoordinateX(6.7);
	location1.setCoordinateY(2.7);

	Location location2;
	location2.setLocationName("Varna");
	location2.setCoordinateX(6.2);
	location2.setCoordinateY(9.2);

	Location location3;
	location3.setLocationName("Dupnitsa");
	location3.setCoordinateX(5.9);
	location3.setCoordinateY(3.7);

	Location location4;
	location4.setLocationName("Stara Zagora");
	location4.setCoordinateX(5.9);
	location4.setCoordinateY(5.9);

	Location locations[4] = { location1,location2,location3 };

	Map map1;
	map1.setLocations(locations, 3, 3);
	map1.resizeLocationsArray(2);
	map1.addLocation(location4);
	map1.printLocations();
	return 0;
}