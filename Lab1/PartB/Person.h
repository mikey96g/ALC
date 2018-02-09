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
	virtual void printname();
protected:
	string name;
};

class Employee : public Person
{
public:
	Employee(string,double);
	void printname();

private:
	double salary;
};


class Customer: public Person
{
public:
	Customer(string,string);
	void printname();

private:
	string complaint;
};



#endif