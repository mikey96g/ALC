#include <algorithm>
#include "Products.h"
#include <iostream>

//using namespace std;

/***************************************************************************************
*    Usage: modified
*    Title: Beginners guide to the std::sort() function
*    Date: 09/02/2018
*    Availability: http://www.cplusplus.com/articles/NhA0RXSz/
***************************************************************************************/

bool wayToSort(Products *i, Products *j)
{
	return i->getGrossPrice() < j->getGrossPrice(); 
}

int main()
{
	int const num = 8;
	Products *var[8];
	int choice;
	

	Books * book;
	Software * software;

	double price;
	std::cout << "Enter Price: ";
	std::cin >> price;

	book = new Books(price);
	software = new Software(price);

	var[0] = book;
    var[1] = software;

	std::cout << book->getGrossPrice();
	std::cout << ("\n\n");

	std::cout << software->getGrossPrice();

	std::cout << ("\n\n");

	for (int i = 2; i < num; i++)
	{

		std::cout << "Enter 1 for Software or 2 for Book: ";
		std::cin >> choice;

		std::cout << ("\n\n");

		std::cout << "Enter Price: ";
		std::cin >> price;		

		if (choice == 1)
		{
			var[i] = new Software(price);
		}
		else if (choice == 2)
		{
			var[i] = new Books(price);
		}
				
	}

	for (int i =0; i<num; i++)
	{
		std::cout << "The Price for item: " << (i +1) << " is: "<< var[i]->getGrossPrice();
		std::cout << "\n\n";
	}

	sort(begin(var), end(var), wayToSort);
	for (int i =0; i < num;++i)
	{
		std::cout << var[i]->getGrossPrice();
		std::cout << "\n";
	}

	system("pause");
	return 0;
}
