#include "Product.h"
#include "../../Zadanie1/Date.h"
#include "Amount.h"
#include "Weight.h"
#include "Price.h"
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

Amount Product::getAmount() const {
	return Prices;
}

std::string Product::getProducer() const {
	return Producer;
}

int Product::getProductNumber() const {
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


bool operator==(const Product& prod,const Product& other)
{
	return ((prod.getName() == other.getName()) && (prod.getAmount().getNumber() == other.getAmount().getNumber())&&(prod.getAmount().getPrice() == other.getAmount().getPrice())
		&&(prod.getAmount().getUnit() == other.getAmount().getUnit()));
}

bool Product::findDuplicate(Product my_product, std::vector<Product> products) {
	auto it = std::find_if(products.begin(), products.end(), [my_product](const Product& p) {
		return p == my_product;
		});
	if (it != products.end()) {
		return true;
	}
	else return false;
	
}


std::ostream& operator<<(std::ostream& COUT, Product& product)
{
	COUT << "Name of product: " << product.Name << std::endl;
	COUT << "Price of product: " << product.getPrice() << std::endl;
	COUT << "Producer: " << product.Producer << std::endl;
	COUT << "Produkt number: " << product.ProductNumber << std::endl;
	COUT << "Expiry date: " << product.EatByDate.PrintDate() << std::endl;
	COUT << "Amount of product: " << product.Prices.getNumber() << product.Prices.getWeight().unitToString() << std::endl;
	COUT << "Price for " << product.Prices.getWeight().unitToString() << ": " << product.Prices.getPrice() << std::endl;
	return COUT;
}
