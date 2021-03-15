#include "FilmRanking.h"

void FilmRanking::copy(const FilmRanking& filmRank)
{
	filmsList = new Film[filmRank.filmsCount];
	for (int i = 0; i < filmRank.filmsCount; ++i)
	{
		filmsList[i] = filmRank.filmsList[i];
	}
	filmsCount = filmRank.filmsCount;
}

void FilmRanking::erase()
{
	delete[] filmsList;
}

FilmRanking::FilmRanking()
{
	filmsList = new Film[0];
	filmsCount = 0;
}

FilmRanking::FilmRanking(const FilmRanking& filmRank)
{
	this->copy(filmRank);
}

FilmRanking& FilmRanking::operator=(const FilmRanking& filmRank)
{
	if (this != &filmRank)
	{
		this->erase();
		this->copy(filmRank);
	}
	return *this;
}

FilmRanking::~FilmRanking()
{
	this->erase();
}

void FilmRanking::setFilmsList(const Film filmsList[], int filmsCount)
{
	delete[] this->filmsList;
	this->filmsList = new Film[filmsCount];
	for (int i = 0; i < filmsCount; ++i)
	{
		this->filmsList[i] = filmsList[i];
	}
	this->filmsCount = filmsCount;
}

const Film* FilmRanking::getFilmsList() const
{
	return filmsList;
}

int FilmRanking::getFilmsCount() const
{
	return filmsCount;
}

void FilmRanking::swap(Film& firstFilm, Film& secondFilm)
{
	Film swapTemp = firstFilm;
	firstFilm = secondFilm;
	secondFilm = swapTemp;
}

void FilmRanking::sortFilms()
{
	for (int i = 0; i < filmsCount; ++i)
	{
		for (int j = i + 1; j < filmsCount; ++j)
		{
			if (filmsList[i].getFilmAwardsCount() < filmsList[j].getFilmAwardsCount())
			{
				swap(filmsList[i], filmsList[j]);
			}
		}
	}
}

void FilmRanking::printTopFilms(int number)
{
	if (number > filmsCount)
	{
		do
		{
			std::cout << "Enter number smaller or equal than films count: ";
			std::cin >> number;
		} while (number > filmsCount);
	}

	this->sortFilms();
	for (int i = 0; i < number; ++i)
	{
		filmsList[i].printFilmData();
	}
	return;
}
