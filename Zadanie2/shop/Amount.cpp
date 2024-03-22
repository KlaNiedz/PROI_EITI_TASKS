#include "Amount.h"
#include "Product.h"

Amount::Amount(double price, double number, std::string unit) {
	if (unit != "piece" && unit != "kg" && unit != "g") {
		throw "Wrong Unit! Avaiable units are 'piece', 'kg' or 'g'.";
	}
	Price = price;
	Number = number;
	Unit = unit;
}
double Amount::getPrice() {
	return Price * Number;

}