#include <algorithm>
#include "Products.h"
#include <iostream>

using namespace std;
bool wayToSort(int i, int j) { return i > j; }

int main()
{
	int const num = 8;
	Products *var[8];
	int choice;
	

	Books * book;
	Software * software;

	double price;
	cout << "Enter Price: ";
	cin >> price;

	book = new Books(price);
	software = new Software(price);

	var[0] = book;
    var[1] = software;

	cout << book->getGrossPrice();
	cout << ("\n\n");

	cout << software->getGrossPrice();

	cout << ("\n\n");

	for (int i = 2; i < num; i++)
	{

		cout << "Enter 1 for Software or 2 for Book: ";
		cin >> choice;

		cout << ("\n\n");

		cout << "Enter Price: ";
		cin >> price;		

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
		cout << "The Price for item: " << (i +1) << " is: "<< var[i]->getGrossPrice();
		cout << "\n\n";
	}

	sort(begin(var), end(var), wayToSort);
	for (int i =0; i = num;++i)
	{
		cout << var[i]->getGrossPrice();
	}

	system("pause");
	return 0;
}
