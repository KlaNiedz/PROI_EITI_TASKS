#include "Receipt.h"
#include <vector>
#include <typeinfo>
#include "../../../Zadanie1/date_setter.cpp/date_setter.cpp/Date.h"
#include "Product.h"




Receipt::Receipt(std::string shop_name, Date date_shop, std::vector<Product>products={}) 
{
	ShopName = shop_name;
	DateShop = date_shop;
	Products = products;
}

void Receipt::setShopName(string shop_name) {
	ShopName = shop_name;
}

string Receipt::getShopName() {
	return ShopName;
}


void Receipt::addProduct(Product product) {
	Products.push_back(product);
}


//bool Receipt::isValidReceipt(std::string nazwa_sklepu, int date, std::vector<std::string>produkty) {
//	
//}
