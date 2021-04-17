#pragma once
#include "String.h"

class WaterCard
{
private:
	String cardName;
	size_t power;
	size_t bonusPower;
	int cardType = 1;
public:
	WaterCard();
	WaterCard(const char*, size_t, size_t);

	void setCardName(const char*);
	void setPower(size_t);
	void setBonusPower(size_t);
	
	const char* getCardName() const;
	size_t getPower() const;
	size_t getBonusPower() const;
	int getCardType() const;

	friend std::ostream& operator<<(std::ostream& out, const WaterCard& card);
};

