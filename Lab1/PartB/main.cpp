#include "Person.h"
#include <iostream>


using namespace std;

int main()
{
	Person* personPtr;

	personPtr = new Person("John");
	personPtr->printname();

	personPtr = new Employee("Jim", 20000);
	personPtr->printname();

	personPtr = new Customer("James", "The Employees are idiots!!!");
	personPtr->printname();

	cout << "\n\n";
	system("pause");
	return 0;
}