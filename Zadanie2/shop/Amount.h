#pragma once
#include <iostream>


class Amount
{
private:
	double Price;
	double Number;
	std::string Unit;
public:

	Amount(double price, double number, std::string unit);
	double getPrice();

	Amount() = default;
};