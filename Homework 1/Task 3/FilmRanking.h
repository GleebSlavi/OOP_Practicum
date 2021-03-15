#pragma once
#include <iostream>
#include <cstring>
#include "Film.h"

class FilmRanking
{
private:
	Film* filmsList;
	int filmsCount;

	void copy(const FilmRanking& filmRank);
	void erase();
public:
	FilmRanking();
	FilmRanking(const FilmRanking& filmRank);
	FilmRanking& operator=(const FilmRanking& filmRank);
	~FilmRanking();

	void setFilmsList(const Film filmsList[], int filmsCount);

	const Film* getFilmsList() const;
	int getFilmsCount() const;

	void swap(Film& firstFilm, Film& secondFilm);
	void sortFilms();
	void printTopFilms(int number);
};

