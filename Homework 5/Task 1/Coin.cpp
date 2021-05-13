#include "Coin.h"

void Coin::copy(const Coin& other)
{
	side = other.side;
	value = other.value;

	nationality = new char[strlen(other.nationality) + 1];
	strcpy_s(nationality, strlen(other.nationality) + 1, other.nationality);
}

void Coin::erase()
{
	delete[] nationality;
}

Coin::Coin()
{
	side = HEADS;
	value = 0;
	
	nationality = new char[3];
	nationality[0] = '\0';
}

Coin::Coin(int value)
{
	side = HEADS;
	if (value == 1 || value == 2 || value == 5 || value == 10 || value == 20 || value == 50)
	{
		this->value = value;
	}
	else
	{
		this->value = 1;
	}
}

Coin::Coin(const Coin& other)
{
	this->copy(other);
}

Coin& Coin::operator=(const Coin& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Coin::~Coin()
{
	this->erase();
}

Side Coin::getSide() const
{
	return side;
}

int Coin::getValue() const
{
	return value;
}

void Coin::printData() const
{
	std::cout << "Coin nationality: " << nationality << std::endl;
	std::cout << "Coin value: " << value << std::endl;
	std::cout << "Coin side: ";
	if (side == 1)
	{
		std::cout << "HEADS" << std::endl;
	}
	else
	{
		std::cout << "TAILS" << std::endl;
	}
}
