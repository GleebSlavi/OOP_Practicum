#pragma once
#include <iostream>
#include <cstring>

class Crypto
{
private:
	char cryptoName[31];
	double lastPrice;
	double currentPrice;
public:
	Crypto();
	Crypto(const char cryptoName[], double lastPrice, double currentPrice);

	void setCryptoName(const char cryptoName[]);
	void setLastPrice(double lastPrice);
	void setCurrentPrice(double currentPrice);

	const char* getCryptoName() const;
	double getLastPrice() const;
	double getCurrentPrice() const;

	void priceDifference();
	void printCryptoData() const;
};

