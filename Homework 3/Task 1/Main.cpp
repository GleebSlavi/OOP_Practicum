#include <iostream>
#include "Player.h"

int main()
{
	WindCard Cloudlet("Cloudlet", 150, 240);
	WindCard Chengami("Chengami", 120, 130);
	WindCard Tornadeon("Tornadeon", 100, 90);
	WindCard Tornadus("Tornadus", 240, 120);
	WindCard Clounight("Clounight", 137, 135);

	Deck<WindCard> deck1;
	deck1.addCard(Cloudlet);
	deck1.addCard(Chengami);
	deck1.addCard(Tornadeon);
	deck1.addCard(Tornadus);
	deck1.addCard(Clounight);

	WaterCard Magikarp("Magikarp", 260, 120);
	WaterCard Feebas("Feebas", 150, 670);
	WaterCard Kyogre("Kyogre", 45, 71);
	WaterCard Spongee("Spongee", 351, 12);
	WaterCard Panpour("Panpour", 218, 120);

	Deck<WaterCard> deck2;
	deck2.addCard(Magikarp);
	deck2.addCard(Feebas);
	deck2.addCard(Kyogre);
	deck2.addCard(Spongee);
	deck2.addCard(Panpour);

	Player<WindCard, WaterCard> player1("Slavi", 0, 0, deck1, deck2);

	FireCard Charmander("Charmander", 317, 212);
	FireCard Mokanou("Mokanou", 213, 70);
	FireCard Flareon("Flareon", 202, 45);
	FireCard Entei("Entei", 178, 123);
	FireCard Vulpix("Vulpix", 421, 142);

	Deck<FireCard> deck3;
	deck3.addCard(Charmander);
	deck3.addCard(Mokanou);
	deck3.addCard(Flareon);
	deck3.addCard(Entei);
	deck3.addCard(Vulpix);

	EarthCard Rockruff("Rockruff", 451, 51);
	EarthCard Rampardos("Rampardos", 371, 512);
	EarthCard Boldore("Boldore", 141, 12);
	EarthCard Regirock("Regirock", 612, 87);
	EarthCard Tactite("Tactite", 51, 123);

	Deck<EarthCard> deck4;
	deck4.addCard(Rockruff);
	deck4.addCard(Rampardos);
	deck4.addCard(Boldore);
	deck4.addCard(Regirock);
	deck4.addCard(Tactite);

	Player<FireCard, EarthCard> player2("Ivan", 0, 0, deck3, deck4);
	//player2.loadPlayer("player1.txt");
	player2.printPlayer();
	return 0;
}