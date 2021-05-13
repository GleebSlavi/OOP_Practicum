#include <iostream>
#include "Buyer.h"

int main()
{
	Product p1("Table", 10, 25, HEADS);
	Product p2("Chair", 5, 5, TAILS);
	Product p3("Sofa", 25, 50, HEADS);
	Product p4("Vase", 5, 10, HEADS);

	Shop s1;
	s1.addProduct(p1);
	s1.addProduct(p2);
	s1.addProduct(p3);
	s1.addProduct(p4);;

	Buyer b1;
	b1.addAmericanCoin(5);
	b1.addAmericanCoin(10);
	b1.addAmericanCoin(5);
	b1.addAmericanCoin(20);

	b1.addBulgarianCoin(10);
	b1.addBulgarianCoin(50);
	b1.addBulgarianCoin(20);
	b1.addBulgarianCoin(2);

	b1.addGermanCoin(10);
	b1.addGermanCoin(1);
	b1.addGermanCoin(5);
	b1.addGermanCoin(1);

	b1.enterShop(s1);
	b1.printProducts();
	
	return 0;
}