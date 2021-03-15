#include <iostream>
#include "FilmRanking.h"

int main()
{
	Film film1;
	film1.setFilmName("Avengers Endgame");
	film1.setProducerName("Russo Brothers");
	film1.setFilmAwardsCount(10);

	Film film2;
	film2.setFilmName("The Lighthouse");
	film2.setProducerName("Robert Eggars");
	film2.setFilmAwardsCount(5);

	Film film3;
	film3.setFilmName("Get Out");
	film3.setProducerName("Jordan Peele");
	film3.setFilmAwardsCount(7);

	Film filmsList1[3] = { film1,film2,film3 };
	
	FilmRanking filmsList;
	filmsList.setFilmsList(filmsList1, 3);
	filmsList.printTopFilms(2);


	return 0;
}