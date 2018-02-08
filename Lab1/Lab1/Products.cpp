#include "Products.h"

Products::Products(double price)
{
	netPrice = price;
}

double Products::getGrossPrice()
{
	return netPrice * 1.21;
}


Software::Software(double price):Products(price)
{
	
}



Books::Books(double price):Products(price)
{
}

double Books::getGrossPrice()
{

	return netPrice;
}
