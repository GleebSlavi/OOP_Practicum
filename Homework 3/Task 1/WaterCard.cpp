#include "WaterCard.h"

WaterCard::WaterCard()
{
	power = 0;
	bonusPower = 0;
}

WaterCard::WaterCard(const char* cardName, size_t power, size_t bonusPower)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
	this->power = power;
	this->bonusPower = bonusPower;
}

void WaterCard::setCardName(const char* cardName)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
}

void WaterCard::setPower(size_t power)
{
	this->power = power;
}

void WaterCard::setBonusPower(size_t bonusPower)
{
	this->bonusPower = bonusPower;
}

const char* WaterCard::getCardName() const
{
	return cardName.getString();
}

size_t WaterCard::getPower() const
{
	return power;
}

size_t WaterCard::getBonusPower() const
{
	return bonusPower;
}

int WaterCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const WaterCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card power: " << card.power << std::endl;
	out << "Card bonus power: " << card.bonusPower << std::endl;
	out << "Card type: Water" << std::endl;

	return out;
}
