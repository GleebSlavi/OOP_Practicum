#pragma once
#include <cstdlib>
#include "EarthCard.h"
#include "WaterCard.h"
#include "FireCard.h"
#include "WindCard.h"

template <class T>
class Deck
{
private:
	T deck[30];
	size_t deckSize;

	bool sameCardsCheck(const T&) const;
	void swap(T&, T&);
public:
	Deck();

	void setDeck(const Deck<T>&);

	T getDeck() const;
	size_t getDeckSize() const;

	void shuffle();
	T& drawCard();
	void addCard(const T&);

	Deck operator+(const T);
	Deck& operator+=(const T);

	void print() const;
};

template <class T>
bool Deck<T>::sameCardsCheck(const T& card) const
{
	if (deckSize == 0)
	{
		return true;
	}
	for (size_t i = 0; i < deckSize; ++i)
	{
		if (deck[i].getCardName() == card.getCardName())
		{
			return false;
		}
	}
	return true;
}

template <class T>
void Deck<T>::swap(T& firstCard, T& secondCard)
{
	T swapTemp = firstCard;
	firstCard = secondCard;
	secondCard = swapTemp;
}

template <class T>
Deck<T>::Deck()
{
	deckSize = 0;
}

template <class T>
void Deck<T>::setDeck(const Deck<T>& other)
{
	if (other.deckSize < 30)
	{
		for (size_t i = 0; i < other.deckSize; ++i)
		{
			deck[i] = other.deck[i];
		}
	}
	deckSize = other.deckSize;
}

template <class T>
T Deck<T>::getDeck() const
{
	return deck;
}

template <class T>
size_t Deck<T>::getDeckSize() const
{
	return deckSize;
}

template<class T>
void Deck<T>::shuffle()
{
	srand(time(0));
	for (size_t i = 0; i < deckSize; ++i)
	{
		size_t tempIndex = i + (rand() % (deckSize - i));
		swap(deck[i], deck[tempIndex]);
	}
}

template <class T>
T& Deck<T>::drawCard()
{
	for (size_t i = 0; i < deckSize - 1; ++i)
	{
		swap(deck[i], deck[i + 1]);
	}
	return deck[deckSize - 1];
}

template <class T>
void Deck<T>::addCard(const T& card)
{
	if(sameCardsCheck(card) && deckSize < 30)
	{
		deck[deckSize] = card;
		++deckSize;
	}
}

template <class T>
Deck<T> Deck<T>::operator+(T card)
{
	if (sameCardsCheck(card) && deckSize < 30)
	{
		Deck<T> newDeck;
		for (size_t i = 0; i < deckSize; ++i)
		{
			newDeck.deck[i] = deck[i];
		}
		newDeck.deck[deckSize] = card;
		++deckSize;
		newDeck.deckSize = deckSize;
		return newDeck;
	}
}

template <class T>
Deck<T>& Deck<T>::operator+=(T card)
{
	if (sameCardsCheck(card) && deckSize < 30)
	{
		*this = *this + card;
		return *this;
	}
}

template<class T>
void Deck<T>::print() const
{
	for (size_t i = 0; i < deckSize; ++i)
	{
		std::cout << deck[i] << std::endl;
	}
}

