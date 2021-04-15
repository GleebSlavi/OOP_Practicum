#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

class Player
{
private:
	char playerName[11];
	char playerTeamName[11];
	size_t playerWins;
	size_t playerDefeats;

	void nameReader(std::ifstream&, char* );
public:
	Player();
	Player(const char*, const char*, size_t, size_t);

	void setPlayerName(const char*);
	void setPlayerTeamName(const char*);
	void setPlayerWins(size_t);
	void setPlayerDefeats(size_t);

	const char* getPlayerName() const;
	const char* getPlayerTeamName() const;
	size_t getPlayerWins() const;
	size_t getPlayerDefeats() const;

	Player& operator++();
	Player& operator--();

	friend std::ostream& operator<<(std::ostream& out, const Player&);
	friend std::istream& operator>>(std::istream& in, Player&);

	bool operator==(const Player&);
	bool operator!=(const Player&);

	void printPlayer() const;

	void safePlayer(const char*) const;
	void loadPlayer(const char*);
};

