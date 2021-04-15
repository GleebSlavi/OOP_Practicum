#include "Player.h"

void Player::nameReader(std::ifstream& in, char* name)
{
	char ch = ' ';
	size_t counter = 0;
	
	while (ch != '\n')
	{
		ch = in.get();
		if (ch != '\n' && counter < 10)
		{
			name[counter] = ch;
			++counter;
		}
	}
	name[counter] = '\0';
}

Player::Player()
{
	playerName[0] = '\0';
	playerTeamName[0] = '\0';
	playerWins = 0;
	playerDefeats = 0;
}

Player::Player(const char* playerName, const char* playerTeamName, size_t playerWins, size_t playerDefeats)
{
	if (strlen(playerName) < 11)
	{
		strcpy_s(this->playerName, strlen(playerName) + 1, playerName);
	}
	if (strlen(playerTeamName) < 11)
	{
		strcpy_s(this->playerTeamName, strlen(playerTeamName) + 1, playerTeamName);
	}
	this->playerWins = playerWins;
	this->playerDefeats = playerDefeats;
}

void Player::setPlayerName(const char* playerName)
{
	if (strlen(playerName) < 11)
	{
		strcpy_s(this->playerName, strlen(playerName) + 1, playerName);
	}
}

void Player::setPlayerTeamName(const char* playerTeamName)
{
	if (strlen(playerTeamName) < 11)
	{
		strcpy_s(this->playerTeamName, strlen(playerTeamName) + 1, playerTeamName);
	}
}

void Player::setPlayerWins(size_t playerWins)
{
	this->playerWins = playerWins;
}

void Player::setPlayerDefeats(size_t playerDefeats)
{
	this->playerDefeats = playerDefeats;
}

const char* Player::getPlayerName() const
{
	return playerName;
}

const char* Player::getPlayerTeamName() const
{
	return playerTeamName;
}

size_t Player::getPlayerWins() const
{
	return playerWins;
}

size_t Player::getPlayerDefeats() const
{
	return playerDefeats;
}

Player& Player::operator++()
{
	Player player;
	player.playerWins = ++playerWins;
	return player;
}

Player& Player::operator--()
{
	Player player;
	player.playerDefeats = ++playerDefeats;
	return player;
}

bool Player::operator==(const Player& other)
{
	if (strlen(playerName) != strlen(other.playerName) || strlen(playerTeamName) != strlen(other.playerTeamName))
	{
		return false;
	}

	for (size_t i = 0; i < strlen(playerName); ++i)
	{
		if (playerName[i] != other.playerName[i])
		{
			return false;
		}
	}

	for (size_t i = 0; i < strlen(playerTeamName); ++i)
	{
		if (playerTeamName[i] != other.playerTeamName[i])
		{
			return false;
		}
	}
	return true;
}

bool Player::operator!=(const Player& other)
{
	if (this->operator==(other))
	{
		return false;
	}
	return true;
}

void Player::printPlayer() const
{
	std::cout << "Player name: " << playerName << std::endl;
	std::cout << "Player team name: " << playerTeamName << std::endl;
	std::cout << "Player wins: " << playerWins << std::endl;
	std::cout << "Player defeats: " << playerDefeats << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << "Player name: " << player.playerName << std::endl;
	out << "Player team name: " << player.playerTeamName << std::endl;
	out << "Player wins: " << player.playerWins << std::endl;
	out << "Player defeats: " << player.playerDefeats << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Player& player)
{
	std::cout << "Enter player name: ";
	in.getline(player.playerName, 11);
	std::cout << "Enter player team name: ";
	in.getline(player.playerTeamName, 11);
	std::cout << "Enter player wins: ";
	in >> player.playerWins;
	std::cout << "Enter player defeats: ";
	in >> player.playerDefeats;

	return in;
}

void Player::safePlayer(const char* fileName) const
{
	std::ofstream out(fileName);
	if (out.is_open())
	{
		out << playerName << std::endl;
		out << playerTeamName << std::endl;
		out << playerWins << std::endl;
		out << playerDefeats << std::endl;

		out.close();
	}
	else
	{
		std::cout << "Error!";
	}
}

void Player::loadPlayer(const char* fileName)
{
	std::ifstream in(fileName);
	if (in.is_open())
	{
		nameReader(in, playerName);
		nameReader(in, playerTeamName);
		in >> playerWins;
		in >> playerDefeats;

		in.close();
	}
	else
	{
		std::cout << "Error!";
	}
}

