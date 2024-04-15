#include "Amount.h"
#include "Product.h"
#include "Weight.h"
#include "Price.h"



Amount::Amount(Price price_of_prod, Weight amount_of_prod) {
	PriceOfProd = price_of_prod;
	AmountOfProd = amount_of_prod;
}
Amount::Amount() : PriceOfProd(0.0, myCurrency::PLN), AmountOfProd(0.0, myUnit::kg) {}

Weight Amount::getWeight() const{
	return AmountOfProd;
}

Price Amount::getPriceClass() const {
	return PriceOfProd;
}

double Amount::getPrice() const {
	return PriceOfProd.getNumber();
}

double Amount::getNumber() {
	return AmountOfProd.getNumber();
}

myUnit Amount::getUnit() {
	return AmountOfProd.getUnit();
}

void Amount::setPrice(double price) {
	PriceOfProd.setNumber(price);
}

void Amount::setNumber(double number) {
	AmountOfProd.setNumber(number);
}

void Amount::setUnit(myUnit unit) {
	AmountOfProd.setUnit(unit);
}

double Amount::calculatePrice() {
	return PriceOfProd.getNumber() * AmountOfProd.getNumber();

}

std::ostream& operator<<(std::ostream& os, const Amount& amount)
{
	os << amount.getPriceClass() << std::endl;
	os << amount.getWeight() << std::endl;
	return os;
}
