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
};class Employee : public Person{public:	void printname();private:	double salary;};class Customer: public Customer{public:	void printname();private:	string complaint;};


#endif