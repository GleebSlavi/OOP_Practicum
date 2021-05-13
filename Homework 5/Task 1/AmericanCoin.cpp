#include "AmericanCoin.h"

AmericanCoin::AmericanCoin() : Coin()
{
	strcpy_s(nationality, 3, "US");
}

AmericanCoin::AmericanCoin(int value) : Coin(value)
{
	nationality = new char[3];
	strcpy_s(nationality, 3, "US");
}

void AmericanCoin::flip()
{
	srand(time(0));

	int flipVariable = rand() % 10 + 1;
	if (flipVariable == 1)
	{
		side = TAILS;
	}
	else
	{
		side = HEADS;
	}
}

void AmericanCoin::coinValue(int coinsCount) const
{
	std::cout << coinsCount << " AmericanCoin with value " << value << " = " << coinsCount << " GermanCoin with value " << (5 / 2.0) * value << std::endl;
	std::cout << coinsCount << " AmericanCoin with value " << value << " = " << coinsCount << " BulgarianCoin with value " << (1 / 3.0) * value << std::endl;
}
