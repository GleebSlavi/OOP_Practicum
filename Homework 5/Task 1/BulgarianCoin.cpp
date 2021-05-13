#include "BulgarianCoin.h"

BulgarianCoin::BulgarianCoin() : Coin()
{
	strcpy_s(nationality,3,"BG");
}

BulgarianCoin::BulgarianCoin(int value) : Coin(value)
{
	nationality = new char[3];
	strcpy_s(nationality, 3, "BG");
}

void BulgarianCoin::flip()
{
	srand(time(0));

	int flipVariable = rand() % 10 + 1;
	if (flipVariable <= 3)
	{
		side = HEADS;
	}
	else
	{
		side = TAILS;
	}
}

void BulgarianCoin::coinValue(int coinsCount) const
{
	std::cout << coinsCount << " BulgarianCoin with value " << value << " = " << coinsCount << " GermanCoin with value " << 6 * value << std::endl;
	std::cout << coinsCount << " BulgarianCoin with value " << value << " = " << coinsCount << " AmericanCoin with value " << 3 * value << std::endl;
}
