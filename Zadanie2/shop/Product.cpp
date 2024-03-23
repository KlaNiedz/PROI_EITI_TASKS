#include "Product.h"
#include "../../Zadanie1/Date.h"
#include "Amount.h"
//#include "../../../Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"

Product::Product(const char* name, Amount prices, std::string producer, int product_number, Date eatbydate) {
	Name = name;
	Prices = prices;
	Producer = producer;
	ProductNumber = product_number;
	EatByDate = eatbydate;
}
std::string Product::getName() const {
	return Name;
}

std::string Product::getProducer() {
	return Producer;
}

int Product::getProductNumber() {
	return ProductNumber;
}

double Product::getPrice() {
	return Prices.calculatePrice();
}

void Product::setName(std::string name) {
	Name = name;
}

void Product::setProducer(std::string producer) {
	Producer = producer;
}

void Product::setProductNumber(int product_number) {
	ProductNumber = product_number;
}

std::ostream& operator<<(std::ostream& COUT, Product& product)
{
	COUT << "Name of product: " << product.Name << std::endl;
	COUT << "Price of product: " << product.getPrice() << std::endl;
	COUT << "Producer: " << product.Producer << std::endl;
	COUT << "Produkt number: " << product.ProductNumber << std::endl;
	COUT << "Expiry date: " << product.EatByDate.PrintDate() << std::endl;
	COUT << "Amount of product: " << product.Prices.getNumber() << product.Prices.getUnit() << std::endl;
	COUT << "Price for " << product.Prices.getUnit()<< ": " << product.Prices.getPrice() << std::endl;
	return COUT;
}
