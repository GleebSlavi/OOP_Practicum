#pragma once
#include "Coin.h"

class GermanCoin : public Coin
{
public:
	GermanCoin();
	GermanCoin(int);

	void flip() override;
	void coinValue(int) const override;
};

