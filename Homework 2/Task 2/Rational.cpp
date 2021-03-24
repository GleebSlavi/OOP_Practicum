#include "Rational.h"

int Rational::lcd(int firstDenom, int secondDenom)
{
	int lowestCommonDenominator;
	if (firstDenom > secondDenom)
	{
		lowestCommonDenominator = firstDenom;
	}
	else
	{
		lowestCommonDenominator = secondDenom;
	}

	while (1)
	{
		if (lowestCommonDenominator % firstDenom == 0 && lowestCommonDenominator % secondDenom == 0)
		{
			return lowestCommonDenominator;
		}
		++lowestCommonDenominator;
	}
}

Rational::Rational()
{
	nom = 0;
	denom = 0;
}

Rational::Rational(int nom, int denom)
{
	this->nom = nom;
	this->denom = denom;
}

void Rational::setNom(int nom)
{
	this->nom = nom;
}

void Rational::setDenom(int denom)
{
	this->denom = denom;
}

int Rational::getNom() const
{
	return nom;
}

int Rational::getDenom() const
{
	return denom;
}

void Rational::printRational() const
{
	std::cout << nom << "/" << denom << std::endl;
}

Rational& Rational::operator+(const Rational& other)
{
	nom = nom * (lcd(denom, other.denom) / denom) + other.nom * (lcd(denom, other.denom) / other.denom);
	denom = lcd(denom, other.denom);
	return *this;
}

Rational& Rational::operator-(const Rational& other)
{
	nom = nom * (lcd(denom, other.denom) / denom) - other.nom * (lcd(denom, other.denom) / other.denom);
	denom = lcd(denom, other.denom);
	return *this;
}

Rational& Rational::operator*(const Rational& other)
{
	nom *= other.nom;
	denom *= other.denom;
	return *this;
}

Rational& Rational::operator/(const Rational& other)
{
	nom *= other.denom;
	denom *= other.nom;
	return *this;
}

bool Rational::operator==(const Rational& other)
{
	if (nom * (lcd(denom, other.denom) / denom) == other.nom * (lcd(denom, other.denom) / other.denom))
	{
		return true;
	}
	return false;
}

bool Rational::operator!=(const Rational& other)
{
	if (this->operator==(other))
	{
		return false;
	}
	return true;
}

bool Rational::operator>=(const Rational& other)
{
	if (nom * (lcd(denom, other.denom) / denom) >= other.nom * (lcd(denom, other.denom) / other.denom))
	{
		return true;
	}
	return false;
}

bool Rational::operator<=(const Rational& other)
{
	if (nom * (lcd(denom, other.denom) / denom) <= other.nom * (lcd(denom, other.denom) / other.denom))
	{
		return true;
	}
	return false;
}

Rational& Rational::operator=(const Rational& other)
{
	if (this != &other)
	{
		nom = other.nom;
		denom = other.denom;
	}
	return *this;
}

Rational& Rational::operator+=(const Rational& other)
{
	this->operator+(other);
	return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
	this->operator-(other);
	return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
	this->operator*(other);
	return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
	this->operator/(other);
	return *this;
}

