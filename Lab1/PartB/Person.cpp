#include "Person.h"
#include <iostream>
#include <string>


Employee::Employee(string nameInput, double salaryIn) :Person(nameInput), salary(salaryIn)
{

}

void Employee::printname()
{
	Person::printname();
	cout << "Salary: " << salary;

}

Person::Person(string nameInput)
{
	name = nameInput;
}

void Person::printname()
{
	cout << "Name: " << name;
}

Customer::Customer(string nameInput):Person(nameInput)
{

}

void Customer::printname()
{
	Person::printname();
	cout << "Has a Complaint!!";
}
