#include "EarthCard.h"

EarthCard::EarthCard()
{
	power = 0;
	bonusPower = 0;
}

EarthCard::EarthCard(const char* cardName, size_t power, size_t bonusPower)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
	this->power = power;
	this->bonusPower = bonusPower;
}

void EarthCard::setCardName(const char* cardName)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
}

void EarthCard::setPower(size_t power)
{
	this->power = power;
}

void EarthCard::setBonusPower(size_t bonusPower)
{
	this->bonusPower = bonusPower;
}



const char* EarthCard::getCardName() const
{
	return cardName.getString();
}

size_t EarthCard::getPower() const
{
	return power;
}

size_t EarthCard::getBonusPower() const
{
	return bonusPower;
}

int EarthCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const EarthCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card power: " << card.power << std::endl;
	out << "Card bonus power: " << card.bonusPower << std::endl;
	out << "Card type: Earth" << std::endl;

	return out;
}
