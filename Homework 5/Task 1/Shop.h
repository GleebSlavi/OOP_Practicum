#pragma once
#include "Product.h"
#include "Vector.h"

class Shop
{
private:
	Vector<Product> products;
public:
	size_t getProductsCount() const;

	void addProduct(const Product&);
	void removeProduct(size_t);
	void printProducts() const;
	Product& operator[](size_t) const;
};

