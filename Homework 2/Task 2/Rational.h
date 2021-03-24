#pragma once
#include <iostream>
#include <cstring>

class Rational
{
private:
	int nom;
	int denom;

	int lcd(int firstDenom, int secondDenom);
public:
	Rational();
	Rational(int nom, int denom);

	void setNom(int nom);
	void setDenom(int denom);

	int getNom() const;
	int getDenom() const;

	void printRational() const;

	Rational& operator+(const Rational& other);
	Rational& operator-(const Rational& other);
	Rational& operator*(const Rational& other);
	Rational& operator/(const Rational& other);

	bool operator==(const Rational& other);
	bool operator!=(const Rational& other);
	bool operator>=(const Rational& other);
	bool operator<=(const Rational& other);

	Rational& operator=(const Rational& other);

	Rational& operator+=(const Rational& other);
	Rational& operator-=(const Rational& other);
	Rational& operator*=(const Rational& other);
	Rational& operator/=(const Rational& other);
};

