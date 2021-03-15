#include <iostream>
#include "Film.h"

int main()
{
	Film film1;
	film1.setFilmName("Avengers Endgame");
	film1.setProducerName("Russo Brothers");
	film1.setFilmAwardsCount(10);
	film1.printFilmData();
	
	Film film2;
	film2.setFilmName("The Lighthouse");
	film2.setProducerName("Robert Eggars");
	film2.setFilmAwardsCount(5);

	film1 = film2;
	film1.printFilmData();
	return 0;
}