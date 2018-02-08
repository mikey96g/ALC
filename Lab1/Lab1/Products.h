2
#pragma once

#ifndef Products_h
#define Products_h


#include <iostream>
#include <cstdlib>

using namespace std;

class Products
{
public:
	Products(double);
	virtual double getGrossPrice();

protected:
	double netPrice;

};

class Software : public Products
{
public:
	Software(double);

};


class Books : public Products
{
public:
	Books(double);
	double getGrossPrice() ;

private:

};

#endif
