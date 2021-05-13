#include "Buyer.h"

int Buyer::discountCheck(size_t index, Shop& shop)
{
	srand(time(0));

	int flipCoinVariable = rand() % 3 + 1;
	if (flipCoinVariable == 1)
	{
		americanPurse.operator[](0)->flip();
		if (americanPurse.operator[](0)->getSide() == shop[index].getDiscountChance())
		{
			shop[index].setPrice(shop[index].getPrice() * (shop[index].getDiscountProcent() / 100.0));
		}
		americanPurse.moveToTheBack();
	}
	else if (flipCoinVariable == 2)
	{
		bulgarianPurse.operator[](0)->flip();
		if (bulgarianPurse.operator[](0)->getSide() == shop[index].getDiscountChance())
		{
			shop[index].setPrice(shop[index].getPrice() * (shop[index].getDiscountProcent() / 100.0));
		}
		bulgarianPurse.moveToTheBack();
	}
	else
	{
		germanPurse.operator[](0)->flip();
		if (germanPurse.operator[](0)->getSide() == shop[index].getDiscountChance())
		{
			shop[index].setPrice(shop[index].getPrice() * (shop[index].getDiscountProcent() / 100.0));
		}
		germanPurse.moveToTheBack();
	}
	return flipCoinVariable;
}

void Buyer::coinCheck(Vector<Coin*>& purse, size_t index, Shop& shop)
{
	size_t size = purse.getSize();

	if (purse.getSize() == 0)
	{
		std::cout << "There are coins left in this purse!" << std::endl;
		return;
	}

	double value = shop[index].getPrice();
	int minValue = 0;
	size_t counter = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (purse[i]->getValue() >= value)
		{
			if (minValue == 0)
			{
				minValue = purse[i]->getValue();
				counter = i;
			}
			if (purse[i]->getValue() < minValue)
			{
				minValue = purse[i]->getValue();
				counter = i;
			}
			if (purse[i]->getValue() == value)
			{
				break;
			}
		}
	}
	purse.removeFromIndex(counter);
	products.add(shop[index]);
	shop.removeProduct(index);
}

void Buyer::addAmericanCoin(size_t value)
{
	Coin* americanCoin = new AmericanCoin(value);
	americanPurse.addCoin(americanCoin);
}

void Buyer::addBulgarianCoin(size_t value)
{
	Coin* bulgarianCoin = new BulgarianCoin(value);
	bulgarianPurse.addCoin(bulgarianCoin);
}

void Buyer::addGermanCoin(size_t value)
{
	Coin* germanCoin = new GermanCoin(value);
	germanPurse.addCoin(germanCoin);
}

void Buyer::removeAmericanCoin(size_t index)
{
	americanPurse.removeFromIndex(index);
}

void Buyer::removeBulgarianCoin(size_t index)
{
	bulgarianPurse.removeFromIndex(index);
}

void Buyer::removeGermanCoin(size_t index)
{
	germanPurse.removeFromIndex(index);
}

void Buyer::enterShop(Shop& shop)
{
	int productNumber;
	do
	{
		shop.printProducts();

		std::cout << "Enter product number or enter 0 to leave the shop: ";
		std::cin >> productNumber;
		std::cout << std::endl;

		if (productNumber > 0)
		{
			this->buy(productNumber - 1, shop);
		}

	}while (productNumber != 0);
}

void Buyer::buy(size_t index, Shop& shop)
{
	int buyVariable = discountCheck(index, shop);
	if (buyVariable == 1)
	{
		coinCheck(americanPurse, index, shop);
	}
	else if (buyVariable == 2)
	{
		coinCheck(bulgarianPurse, index, shop);
	}
	else
	{
		coinCheck(germanPurse, index, shop);
	}
}

void Buyer::printProducts() const
{
	std::cout << "Bought products: " << std::endl;
	std::cout << std::endl;
	products.printData();
	std::cout << std::endl;
}

