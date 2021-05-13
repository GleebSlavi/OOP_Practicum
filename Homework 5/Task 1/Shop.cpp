#include "Shop.h"

size_t Shop::getProductsCount() const
{
	return products.getSize();
}

void Shop::addProduct(const Product& product)
{
	products.add(product);
}

void Shop::removeProduct(size_t index)
{
	products.removeFromIndex(index);
}

void Shop::printProducts() const
{
	products.printData();
}

Product& Shop::operator[](size_t index) const
{
	return products[index];
}
