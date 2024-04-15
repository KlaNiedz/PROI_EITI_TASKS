#include "Price.h"
#include <ostream>

//Price::Price() : Number(0.0), Currency(myCurrency::PLN) {}
Price::Price(double number, myCurrency currency)
{
	Number = number;
	Currency = currency;
}

myCurrency Price::getCurrency() const{
	return Currency;
}

double Price::getNumber() const
{
	return Number;
}

void Price::setCurrency(myCurrency& currency)
{
	Currency = currency;
}

void Price::setNumber(double number)
{
	Number = number;
}

std::string Price::currencyToString() const
{
	switch (Currency) {
	case myCurrency::PLN:
		return "PLN";
	case myCurrency::EUR:
		return "EUR";
	case myCurrency::USD:
		return "USD";
	default:
		return "Unknown";
	}
}

std::ostream& operator<<(std::ostream & os, const Price & price) {
	os <<  price.getNumber() << price.currencyToString() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, myCurrency& currency)
{
	int currencyInt;
	is >> currencyInt;
	currency = static_cast<myCurrency>(currencyInt);
	return is;
}


std::istream& operator>>(std::istream& is, Price& price)
{
	is >> price.Number >> price.Currency;
	return is;
}


