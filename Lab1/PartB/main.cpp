#include "Person.h"
#include <iostream>


using namespace std;

int main()
{
	Person* personPtr;

	personPtr = new Person("John");
	personPtr->printname();
	cout << "\n\n";


	personPtr = new Employee("Jim", 20000);
	personPtr->printname();
	cout << "\n\n";


	personPtr = new Customer("James");
	personPtr->printname();
	cout << "\n\n";


	cout << "\n\n";
	system("pause");
	return 0;
}