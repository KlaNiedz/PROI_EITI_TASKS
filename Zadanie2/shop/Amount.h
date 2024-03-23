#pragma once
#include <iostream>

class WrongUnitException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Wrong Unit! Available units are 'piece', 'kg' or 'g'.";
	}
};

class Amount
{
private:
	double Price;
	double Number;
	std::string Unit;
public:

	Amount(double price, double number, std::string unit);
	double getPrice();
	double getNumber();
	std::string getUnit();
	void setPrice(double price);
	void setNumber(double number);
	void setUnit(std::string);

	double calculatePrice();

	Amount() = default;
};