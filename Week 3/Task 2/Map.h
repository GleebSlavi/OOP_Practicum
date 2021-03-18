#pragma once
#include <iostream>
#include "Location.h"
#include <cmath>

class Map
{
private:
	Location* locationsArray;
	int locationsCount;
	int locationsCapacity;

	void copyMap(const Map& map);
	void eraseLocations();
public:
	Map();
	Map& operator=(const Map& map);
	Map(const Map& map);
	~Map();

	void setLocations(const Location locations[], int locationsCount, int locationsCapacity);

	const Location* getLocations() const;
	int getLocationsCount() const;
	int getLocationsCapacity() const;
	
	void printLocations() const;
	void addLocation(Location location);
	void resizeLocationsArray(int locationsCapacity);
	double distance(int firstIndex, int secondIndex);
	void getShortestDistance(int index);
};

