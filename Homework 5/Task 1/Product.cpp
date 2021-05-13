#include "Product.h"

void Product::copy(const Product& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	price = other.price;
	discountProcent = other.discountProcent;
	discountChance = other.discountChance;
}

void Product::erase()
{
	delete[] name;
}

Product::Product()
{
	name = new char[1];
	name[0] = '\0';
	price = 0;
	discountProcent = 0;
	discountChance = HEADS;
}

Product::Product(const char* name, double price, int discountProcent, Side discountChance)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->price = price;
	this->discountProcent = discountProcent;
	this->discountChance = discountChance;
}

Product::Product(const Product& other)
{
	this->copy(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Product::~Product()
{
	this->erase();
}

void Product::setPrice(double price)
{
	this->price = price;
}

const char* Product::getName() const
{
	return name;
}

double Product::getPrice() const
{
	return price;
}

int Product::getDiscountProcent() const
{
	return discountProcent;
}

Side Product::getDiscountChance() const
{
	return discountChance;
}

std::ostream& operator<<(std::ostream& out, const Product& product)
{
	out << "Product name: " << product.name << std::endl;
	out << "Product price: " << product.price << std::endl;
	out << "Product discount procent: " << product.discountProcent << "%" << std::endl;
	out << "Product procent chance: ";
	if (product.discountChance == 1)
	{
		out << "HEADS" << std::endl;
	}
	else
	{
		out << "TAILS" << std::endl;
	}

	return out;
}
