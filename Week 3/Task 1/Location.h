#pragma once
#include <iostream>
#include <cstring>

class Location
{
private:
	char* locationName;
	double coordinateX;
	double coordinateY;

	void copy(const Location& location);
	void erase();

public:
	Location();
	Location& operator=(const Location& location);
	Location(const Location& location);
	~Location();

	void setLocationName(const char locationName[]);
	void setCoordinateX(double coordinateX);
	void setCoordinateY(double coordinateY);

	const char* getLocationName() const;
	double getCoordinateX() const;
	double getCoordinateY() const;

	void printData() const;
};

