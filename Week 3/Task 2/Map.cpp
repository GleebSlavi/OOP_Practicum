#include "Map.h"

void Map::copyMap(const Map& map)
{
	this->locationsArray = new Location[map.locationsCapacity];
	for (int i = 0; i < map.locationsCount; ++i)
	{
		this->locationsArray[i] = map.locationsArray[i];
	}
	this->locationsCount = map.locationsCount;
	this->locationsCapacity = map.locationsCapacity;
}

void Map::eraseLocations()
{
	delete[] this->locationsArray;
}

Map::Map()
{
	for (int i = 0; i < locationsCount; ++i)
	{
		this->locationsArray[i];
	}
	this->locationsCount = 0;
	this->locationsCapacity = 0;
}

Map& Map::operator=(const Map& map)
{
	if (this != &map)
	{
		this->eraseLocations();
		this->copyMap(map);
	}
	return *this;
}

Map::Map(const Map& map)
{
	this->copyMap(map);
}

Map::~Map()
{
	this->eraseLocations();
}

void Map::setLocations(const Location locations[], int locationsCount, int locationsCapacity)
{
	delete[] this->locationsArray;
	this->locationsArray = new Location[locationsCapacity];
	for (int i = 0; i < locationsCount; ++i)
	{
		this->locationsArray[i] = locations[i];
	}
	this->locationsCount = locationsCount;
	this->locationsCapacity = locationsCapacity;
}


const Location* Map::getLocations() const
{
	return this->locationsArray;
}

int Map::getLocationsCount() const
{
	return this->locationsCount;
}

int Map::getLocationsCapacity() const
{
	return this->locationsCapacity;
}

void Map::printLocations() const
{
	for (int i = 0; i < locationsCount; ++i)
	{
		std::cout << "Location with index " << i << ":" << std::endl;
		locationsArray[i].printData();
	}
}

void Map::addLocation(Location location) 
{
	if (locationsCount < locationsCapacity)
	{
		++locationsCount;
		locationsArray[locationsCount - 1] = location;
	}
	else
	{
		std::cout << "There is no capacity for more locations!" << std::endl;
	}
}

void Map::resizeLocationsArray(int locationsCapacity)
{
	if (this->locationsCapacity >= locationsCapacity)
	{
		do
		{
			std::cout << "Please enter bigger capacity: ";
			std::cin >> locationsCapacity;
		} while (this->locationsCapacity >= locationsCapacity);
	}

	Location* newLocationsArray = new Location[locationsCapacity];
	for (int i = 0; i < locationsCount; ++i)
	{
		newLocationsArray[i] = locationsArray[i];
	}

	delete[] locationsArray;
	locationsArray = newLocationsArray;
	this->locationsCapacity = locationsCapacity;
}

double Map::distance(int firstIndex, int secondIndex)
{
	double differenceCoordinatesX = pow(locationsArray[secondIndex].getCoordinateX() - locationsArray[firstIndex].getCoordinateX(), 2);
	double differenceCoordinatesY = pow(locationsArray[secondIndex].getCoordinateY() - locationsArray[firstIndex].getCoordinateY(), 2);
	return sqrt(differenceCoordinatesX + differenceCoordinatesY);
}

void Map::getShortestDistance(int index)
{
	double shortestDistance = distance(0,index);
	int tempIndex = 0;
	for (int i = 1; i < locationsCount; ++i)
	{
		if (i != index)
		{
			if (distance(i, index) > shortestDistance)
			{
				shortestDistance = distance(i, index);
				tempIndex = i;
			}
		}
	}
	std::cout << "Location with shortest distance: " << locationsArray[tempIndex].getLocationName() << std::endl;
	std::cout << shortestDistance << " km" << std::endl;
}



