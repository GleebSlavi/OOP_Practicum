#include <iostream>
#include "Crypto.h"

int main()
{
	Crypto crypto("Bitcoin",100.20,348.10);
	crypto.printCryptoData();
	
	crypto.priceDifference();
	return 0;
}