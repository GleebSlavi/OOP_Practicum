#include "Location.h"

void Location::copy(const Location& location)
{
	locationName = new char[strlen(location.locationName) + 1];
	strcpy_s(locationName, strlen(location.locationName) + 1, location.locationName);
	coordinateX = location.coordinateX;
	coordinateY = location.coordinateY;
}

void Location::erase()
{
	delete[] locationName;
}

Location::Location()
{
	locationName = new char[6];
	strcpy_s(locationName, 6, "Empty");
	coordinateX = 0;
	coordinateY = 0;
}

Location& Location::operator=(const Location& location)
{
	if (this != &location)
	{
		this->erase();
		this->copy(location);
	}
	return *this;
}

Location::Location(const Location& location)
{
	this->copy(location);
}

Location::~Location()
{
	this->erase();
}

void Location::setLocationName(const char locationName[])
{
	delete[] this->locationName;
	this->locationName = new char[strlen(locationName) + 1];
	strcpy_s(this->locationName, strlen(locationName) + 1, locationName);
}

void Location::setCoordinateX(double coordinateX)
{
	this->coordinateX = coordinateX;
}

void Location::setCoordinateY(double coordinateY)
{
	this->coordinateY = coordinateY;
}

const char* Location::getLocationName() const
{
	return locationName;
}

double Location::getCoordinateX() const
{
	return coordinateX;
}

double Location::getCoordinateY() const
{
	return coordinateY;
}

void Location::printData() const
{
	std::cout << "Location: " << locationName << std::endl;
	std::cout << "Coordinates: (" << coordinateX << "," << coordinateY << ")" << std::endl;
	std::cout << std::endl;
}