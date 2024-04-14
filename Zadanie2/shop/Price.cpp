#include "Price.h"

//Price::Price() : Number(0.0), Currency(myCurrency::PLN) {}
Price::Price(double number, myCurrency currency)
{
	Number = number;
	Currency = currency;
}

myCurrency Price::getCurrency() {
	return Currency;
}

double Price::getNumber()
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



