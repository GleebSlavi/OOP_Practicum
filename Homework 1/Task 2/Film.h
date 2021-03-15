#pragma once
#include <iostream>
#include <cstring>

class Film
{
private:
	char* filmName;
	char* producerName;
	int filmAwardsCount;

	void copy(const Film& film);
	void erase();
public:
	Film();
	Film(const Film& film);
	Film& operator=(const Film& film);
	~Film();

	void setFilmName(const char filmName[]);
	void setProducerName(const char producerName[]);
	void setFilmAwardsCount(int filmAwardsCount);

	const char* getFilmName() const;
	const char* getProducerName() const;
	int getFilmAwardsCount() const;

	void printFilmData() const;
};

