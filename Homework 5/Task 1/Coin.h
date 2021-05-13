#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>

enum Side {HEADS = 1, TAILS = 2};

class Coin
{
protected:
	Side side;
	char* nationality;
	int value;

	void copy(const Coin&);
	void erase();
public:
	Coin();
	Coin(int);
	Coin(const Coin&);
	Coin& operator=(const Coin&);
	~Coin();

	Side getSide() const;
	int getValue() const;

	virtual void coinValue(int) const = 0;
	virtual void flip() = 0;
	void printData() const;
};

