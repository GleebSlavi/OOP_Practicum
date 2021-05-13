#pragma once
#include "AmericanCoin.h"
#include "BulgarianCoin.h"
#include "GermanCoin.h"
#include "Product.h"
#include "Vector.h"
#include "Shop.h"

class Buyer
{
private:
	Vector<Coin*> americanPurse;
	Vector<Coin*> bulgarianPurse;
	Vector<Coin*> germanPurse;
	Vector<Product> products;

	int discountCheck(size_t, Shop&);
	void coinCheck(Vector<Coin*>&, size_t, Shop&);
public:
	void addAmericanCoin(size_t);
	void addBulgarianCoin(size_t);
	void addGermanCoin(size_t);

	void removeAmericanCoin(size_t);
	void removeBulgarianCoin(size_t);
	void removeGermanCoin(size_t);

	void enterShop(Shop&);
	void buy(size_t, Shop&);
	void printProducts() const;
};

