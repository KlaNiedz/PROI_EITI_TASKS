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
std::string Product::getName(){
	return Name;
}
