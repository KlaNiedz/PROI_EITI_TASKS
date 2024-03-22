#pragma once
#include <iostream>
#include "../../Zadanie1/Date.h"
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

