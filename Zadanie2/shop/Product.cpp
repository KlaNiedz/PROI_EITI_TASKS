#include "Product.h"
#include "../../Zadanie1/Date.h"
#include "Amount.h"
#include "Weight.h"
#include "Price.h"
//#include "../../../Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"

Product::Product(std::string name, Amount prices, std::string producer, int product_number, Date eatbydate) {
	Name = name;
	Prices = prices;
	Producer = producer;
	ProductNumber = product_number;
	EatByDate = eatbydate;
}
std::string Product::getName() const {
	return Name;
}

Amount Product::getAmount() const {
	return Prices;
}

std::string Product::getProducer()  const{
	return Producer;
}

int Product::getProductNumber()  const{
	return ProductNumber;
}

double Product::getPrice() {
	return Prices.calculatePrice();
}

Date Product::getDate() {
	return EatByDate;
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


bool operator==(const Product& prod, const Product& other)
{
	return ((prod.getName() == other.getName()) && (prod.getAmount().getNumber() == other.getAmount().getNumber())&&(prod.getAmount().getPrice() == other.getAmount().getPrice())
		&&(prod.getAmount().getUnit() == other.getAmount().getUnit()));
}

bool Product::findDuplicate(const Product my_product, std::vector<Product> products) const {
	auto it = std::find_if(products.begin(), products.end(), [my_product](const Product& p) {
		return p == my_product;
		});
	if (it != products.end()) {
		return true;
	}
	else return false;
	
}



std::ostream& operator<<(std::ostream& os, Product& product)
{
	os << "Name of product: " << product.Name << std::endl;
	os << "Summary price: " << product.getPrice() << std::endl;
	os << "Producer: " << product.Producer << std::endl;
	os << "Produkt number: " << product.ProductNumber << std::endl;
	os << "Expiry date: " << product.EatByDate.PrintDate() << std::endl;
	os << "Amount of product: " << product.Prices.getNumber() << product.Prices.getWeight().unitToString() << std::endl;
	os << "Price for " << product.Prices.getWeight().unitToString() << ": " << product.Prices.getPriceClass() << std::endl;
	return os;
}
