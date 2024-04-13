#pragma once
#include <iostream>
#include <vector>

enum class myCurrency {
	PLN,
	USD,
	EUR,
};

class Price
{
private:
	double Number;
	myCurrency Currency;

public:
	Price() = default;
	Price(double number, myCurrency currency);
	myCurrency getCurrency();
	double getNumber();
	void setCurrency(myCurrency& currency);
	void setNumber(double number);

};

