#pragma once
#include <iostream>
#include <cstring>
#include "Coin.h"

class Product
{
private:
	char* name;
	double price;
	int discountProcent;
	Side discountChance;

	void copy(const Product&);
	void erase();
public:
	Product();
	Product(const char*, double, int, Side);
	Product(const Product&);
	Product& operator=(const Product&);
	~Product();

	void setPrice(double);

	const char* getName() const;
	double getPrice() const;
	int getDiscountProcent() const;
	Side getDiscountChance() const;

	friend std::ostream& operator<<(std::ostream&, const Product&);
};

