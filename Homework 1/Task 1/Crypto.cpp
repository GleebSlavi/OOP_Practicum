#include "Crypto.h"

Crypto::Crypto()
{
	strcpy_s(cryptoName, 1, "\0");
	lastPrice = 0;
	currentPrice = 0;
}

Crypto::Crypto(const char cryptoName[], double lastPrice, double currentPrice)
{
	strcpy_s(this->cryptoName, strlen(cryptoName) + 1, cryptoName);
	this->lastPrice = lastPrice;
	this->currentPrice = currentPrice;
}

void Crypto::setCryptoName(const char cryptoName[])
{
	strcpy_s(this->cryptoName, strlen(cryptoName) + 1, cryptoName);
}

void Crypto::setLastPrice(double lastPrice)
{
	this->lastPrice = lastPrice;
}

void Crypto::setCurrentPrice(double currentPrice)
{
	this->currentPrice = currentPrice;
}

const char* Crypto::getCryptoName() const
{
	return cryptoName;
}

double Crypto::getLastPrice() const
{
	return lastPrice;
}

double Crypto::getCurrentPrice() const
{
	return currentPrice;
}

void Crypto::priceDifference()
{
	double percentage;
	if (currentPrice > lastPrice)
	{
		double increase = currentPrice - lastPrice;
		percentage = (increase * 100) / lastPrice;
		std::cout << percentage << "% increase" << std::endl;
	}
	else
	{
		double decrease = lastPrice - currentPrice;
		percentage = (decrease * 100) / lastPrice;
		std::cout << percentage << "% decrease" << std::endl;
	}
}

void Crypto::printCryptoData() const
{
	std::cout << "Crypto name: " << cryptoName << std::endl;
	std::cout << "Crypto last price: " << lastPrice << std::endl;
	std::cout << "Crypto current price: " << currentPrice << std::endl;
}
