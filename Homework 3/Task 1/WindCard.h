#pragma once
#include "String.h"

class WindCard
{
private:
	String cardName;
	size_t power;
	size_t bonusPower;
	int cardType = 4;
public:
	WindCard();
	WindCard(const char*, size_t, size_t);

	void setCardName(const char*);
	void setPower(size_t);
	void setBonusPower(size_t);

	const char* getCardName() const;
	size_t getPower() const;
	size_t getBonusPower() const;
	int getCardType() const;

	friend std::ostream& operator<<(std::ostream& out, const WindCard& card);
};

