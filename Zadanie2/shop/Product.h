#pragma once
#include <iostream>
#include <string>
#include "Amount.h"
#include "../../Zadanie1/Date.h"

class Product
{
private:
	std::string Name;
	Amount Prices;
	std::string Producer;
	int ProductNumber;
	Date EatByDate;
public:
	Product(const char* name, Amount prices, std::string producer, int product_number, Date eatbydate);
	std::string getName();
};

