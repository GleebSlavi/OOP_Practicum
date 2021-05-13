#pragma once
#include "Coin.h"

class BulgarianCoin : public Coin
{
public:
	BulgarianCoin();
	BulgarianCoin(int);

	void flip() override;
	void coinValue(int) const override;
};

