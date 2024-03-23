#include "Amount.h"
#include "Product.h"

Amount::Amount(double price, double number, std::string unit) {
	if (unit != "piece" && unit != "kg" && unit != "g") {
		throw WrongUnitException();
	}
	Price = price;
	Number = number;
	Unit = unit;
}

double Amount::getPrice() {
	return Price;
}

double Amount::getNumber() {
	return Number;
}

std::string Amount::getUnit() {
	return Unit;
}

void Amount::setPrice(double price) {
	Price = price;
}

void Amount::setNumber(double number) {
	Number = number;
}

void Amount::setUnit(std::string unit) {
	Unit = unit;
}

double Amount::calculatePrice() {
	return Price * Number;

}