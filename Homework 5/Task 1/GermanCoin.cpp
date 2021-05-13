#include "GermanCoin.h"

GermanCoin::GermanCoin() : Coin()
{
	strcpy_s(nationality, 3, "DE");
}

GermanCoin::GermanCoin(int value) : Coin(value)
{
	nationality = new char[3];
	strcpy_s(nationality, 3, "DE");
}

void GermanCoin::flip()
{
	srand(time(0));

	int flipVariable = rand() % 2 + 1;
	if (flipVariable == 1)
	{
		side = HEADS;
	}
	else
	{
		side = TAILS;
	}
}

void GermanCoin::coinValue(int coinsCount) const
{
	std::cout << coinsCount << " GermanCoin with value " << value << " = " << coinsCount << " BulgarianCoin with value " << (1 / 6.0) * value << std::endl;
	std::cout << coinsCount << " GermanCoin with value " << value << " = " << coinsCount << " AmericanCoin with value " << (2 / 5.0) * value << std::endl;
}
