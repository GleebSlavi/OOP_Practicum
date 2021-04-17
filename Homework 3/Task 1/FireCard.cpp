#include "FireCard.h"

FireCard::FireCard()
{
	power = 0;
	bonusPower = 0;
}

FireCard::FireCard(const char* cardName, size_t power, size_t bonusPower)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
	this->power = power;
	this->bonusPower = bonusPower;
}

void FireCard::setCardName(const char* cardName)
{
	this->cardName.setString(cardName, strlen(cardName) + 1, strlen(cardName) + 2);
}

void FireCard::setPower(size_t power)
{
	this->power = power;
}

void FireCard::setBonusPower(size_t bonusPower)
{
	this->bonusPower = bonusPower;
}

const char* FireCard::getCardName() const
{
	return cardName.getString();
}

size_t FireCard::getPower() const
{
	return power;
}

size_t FireCard::getBonusPower() const
{
	return bonusPower;
}

int FireCard::getCardType() const
{
	return cardType;
}

std::ostream& operator<<(std::ostream& out, const FireCard& card)
{
	out << "Card name: " << card.cardName.getString() << std::endl;
	out << "Card power: " << card.power << std::endl;
	out << "Card bonus power: " << card.bonusPower << std::endl;
	out << "Card type: Fire" << std::endl;

	return out;
}
