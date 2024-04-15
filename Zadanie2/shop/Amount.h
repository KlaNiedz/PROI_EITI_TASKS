#pragma once
#include <iostream>
#include "Weight.h"
#include "Price.h"

class WrongUnitException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Wrong Unit! Available units are 'piece', 'kg' or 'g'.";
	}
};
class WrongCurrencyException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Wrong Currency! Use the same currency in whole receipt.";
	}
};



class Amount
{
private:
	Price PriceOfProd;
	Weight AmountOfProd;
public:
	Amount(Price price_of_prod, Weight amount_of_prod);
	Amount();
	Weight getWeight() const;
	double getPrice() const;
	Price getPriceClass() const;
	double getNumber();
	myUnit getUnit();

	void setPrice(double price);
	void setNumber(double number);
	void setUnit(myUnit unit);

	double calculatePrice();
	friend std::ostream& operator<<(std::ostream& os, const Amount& amount);

};
std::ostream& operator<<(std::ostream& os, const Amount& amount);
