#include "WindCard.h"

WindCard::WindCard()
{
	power = 0;
	bonusPower = 0;
}

WindCard::WindCard(const char* cardName, size_t power, size_t bonusPower)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
	this->power = power;
	this->bonusPower = bonusPower;
}

void WindCard::setCardName(const char* cardName)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
}

void WindCard::setPower(size_t power)
{
	this->power = power;
}

void WindCard::setBonusPower(size_t bonusPower)
{
	this->bonusPower = bonusPower;
}



const char* WindCard::getCardName() const
{
	return cardName.getString();
}

size_t WindCard::getPower() const
{
	return power;
}

size_t WindCard::getBonusPower() const
{
	return bonusPower;
}

int WindCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const WindCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card power: " << card.power << std::endl;
	out << "Card bonus power: " << card.bonusPower << std::endl;
	out << "Card type: Wind" << std::endl;

	return out;
}
