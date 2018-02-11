#pragma once

#ifndef Products_h
#define Products_h


#include <iostream>
#include <cstdlib>

using namespace std;

class Person
{
public:
	Person(string); // initialise the name
	virtual void printname() = 0 ;
protected:
	string name;
};

class Employee : public Person
{
public:
	Employee(string nameInput,double salaryIn);
	void printname();

private:
	double salary;
};


class Customer: public Person
{
public:
	Customer(string);
	void printname();

private:
	string complaint;
};



#endif