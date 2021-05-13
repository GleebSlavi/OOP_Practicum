#pragma once
#include "Coin.h"

class AmericanCoin : public Coin
{
public:
	AmericanCoin();
	AmericanCoin(int);

	void flip() override;
	void coinValue(int) const override;
};

