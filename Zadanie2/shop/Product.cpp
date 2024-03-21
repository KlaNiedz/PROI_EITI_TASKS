#include "Product.h"
#include "../../Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"
//#include "../../../Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"

Product::Product(const char* name, int amount, std::string producer, int product_number, Date eatbydate) {
	Name = name;
	Amount = amount;
	Producer = producer;
	ProductNumber = product_number;
	EatByDate = eatbydate;
}