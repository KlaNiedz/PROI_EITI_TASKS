#pragma once
#include <iostream>
#include "/Users/msi/source/repos/PROI/Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"
class Product
{
private:
	std::string Name;
	int Amount;
	std::string Producer;
	std::string ProductNumber;
	Date EatByDate;
public:
	Product(const char* name, int amount, std::string producer, int product_number, Date eatbydate);
	string getName();
};

