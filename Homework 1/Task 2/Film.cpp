#include "Film.h"

void Film::copy(const Film& film)
{
	filmName = new char[strlen(film.filmName) + 1];
	strcpy_s(filmName, strlen(film.filmName) + 1, film.filmName);
	producerName = new char[strlen(film.producerName) + 1];
	strcpy_s(producerName, strlen(film.producerName) + 1, film.producerName);
	filmAwardsCount = film.filmAwardsCount;
}

void Film::erase()
{
	delete[] filmName;
	delete[] producerName;
}

Film::Film()
{
	filmName = new char[1];
	filmName[0] = '\0';
	producerName = new char[1];
	producerName[0] = '\0';
	filmAwardsCount = 0;
}

Film::Film(const Film& film)
{
	this->copy(film);
}

Film& Film::operator=(const Film& film)
{
	if (this != &film)
	{
		this->erase();
		this->copy(film);
	}
	return *this;
}

Film::~Film()
{
	this->erase();
}

void Film::setFilmName(const char filmName[])
{
	delete[] this->filmName;
	this->filmName = new char[strlen(filmName) + 1];
	strcpy_s(this->filmName, strlen(filmName) + 1, filmName);
}

void Film::setProducerName(const char producerName[])
{
	delete[] this->producerName;
	this->producerName = new char[strlen(producerName) + 1];
	strcpy_s(this->producerName, strlen(producerName) + 1, producerName);
}

void Film::setFilmAwardsCount(int filmAwardsCount)
{
	this->filmAwardsCount = filmAwardsCount;
}

const char* Film::getFilmName() const
{
	return filmName;
}

const char* Film::getProducerName() const
{
	return producerName;
}

int Film::getFilmAwardsCount() const
{
	return filmAwardsCount;
}

void Film::printFilmData() const
{
	std::cout << "Film name: " << filmName << std::endl;
	std::cout << "Producer name: " << producerName << std::endl;
	std::cout << "Film awards count: " << filmAwardsCount << std::endl;
	std::cout << std::endl;
}