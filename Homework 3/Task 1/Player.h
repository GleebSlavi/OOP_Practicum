#pragma once
#include <fstream>
#include "Deck.h"

template <class T, class V>
class Player
{
private:
	String playerName;
	size_t wins;
	size_t losses;
	Deck<T> firstDeck;
	Deck<V> secondDeck;

public:
	Player();
	Player(const char*, size_t, size_t,const Deck<T>&, const Deck<V>&);

	Deck<T> getFirstDeck() const;
	Deck<V> getSecondDeck() const;

	Player& operator++();
	Player& operator--();

	void drawCard();
	void safePlayer(const char*);
	void loadPlayer(const char*) const;
	void printPlayer() const;
};

template <class T, class V>
Player<T,V>::Player()
{
	wins = 0;
	losses = 0;
}

template <class T, class V>
Player<T,V>::Player(const char* playerName, size_t wins, size_t losses, const Deck<T>& firstDeck, const Deck<V>& secondDeck)
{
	this->playerName.setString(playerName, strlen(playerName) + 1, strlen(playerName) + 2);
	this->wins = wins;
	this->losses = losses;
	this->firstDeck.setDeck(firstDeck);
	this->secondDeck.setDeck(secondDeck);
}

template<class T, class V>
Deck<T> Player<T, V>::getFirstDeck() const
{
	return firstDeck;
}

template<class T, class V>
Deck<V> Player<T, V>::getSecondDeck() const
{
	return secondDeck;
}

template <class T, class V>
Player<T,V>& Player<T,V>::operator++()
{
	Player player;
	player.wins = ++wins;
	return player;
}

template <class T, class V>
Player<T,V>& Player<T,V>::operator--()
{
	Player player;
	player.losses = ++losses;
	return player;
}

template<class T, class V>
 void Player<T, V>::drawCard()
{
	 srand(time(0));
	 int deckChooser = rand() % 2 + 1;

	 if (deckChooser == 1)
	 {
		return firstDeck.drawCard();
	 }
	 else
	 {
		 return secondDeck.drawCard();
	 }
}

template<class T, class V>
void Player<T,V>::safePlayer(const char* fileName)
{
	std::ofstream out(fileName);
	if (out.is_open())
	{
		out << playerName.getString() << std::endl;
		out << wins << std::endl;
		out << losses << std::endl;

		out.close();
	}
	else
	{
		std::cout << "Error! File didn't open!" << std::endl;
	}
}

template <class T, class V>
void Player<T, V>::loadPlayer(const char* fileName) const
{
	std::ifstream in(fileName);
	if (in.is_open())
	{
		char symbol = ' ';
		size_t counter = 0;

		char* tempName = new char[playerName.getStringCapacity()];
		for (size_t i = 0; i < playerName.getStringSize(); ++i)
		{
			tempName[i] = playerName[i];
		}
		tempName[playerName.getStringSize()] = '\0';

		while (symbol != '\n')
		{
			in.get();
			if (symbol != '\n')
			{
				tempName[counter] = symbol;
				++counter;
			}
			tempName[counter] = '\0';
		}
		in >> wins;
		in >> losses;

		in.close();
	}
	else
	{
		std::cout << "Error! File didn't open!" << std::endl;
	}
}

template <class T, class V>
void Player<T,V>::printPlayer() const
{
	std::cout << "Player name: " << playerName.getString() << std::endl;
	std::cout << "Player wins: " << wins << std::endl;
	std::cout << "Player losses: " << losses << std::endl;
}
