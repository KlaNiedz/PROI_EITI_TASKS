#pragma once
#include <iostream>
#include "Weight.h"
#include "Price.h"

//class WrongUnitException : public std::exception {
//public:
//	const char* what() const noexcept override {
//		return "Wrong Unit! Available units are 'piece', 'kg' or 'g'.";
//	}
//};



class Amount
{
private:
	Price PriceOfProd;
	Weight AmountOfProd;
public:
	Amount(Price price_of_prod, Weight amount_of_prod);
	Amount();
	Weight getWeight();
	double getPrice();
	double getNumber();
	myUnit getUnit();

	void setPrice(double price);
	void setNumber(double number);
	void setUnit(myUnit unit);

	double calculatePrice();
	

	//Amount() = default;


};