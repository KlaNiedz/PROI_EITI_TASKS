#include "Receipt.h"
#include <vector>
#include <typeinfo>
#include "../../Zadanie1/Date.h"
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

std::vector<Product> Receipt::getProducts() {
	return Products;
}

int Receipt::getNumberOfProducts() {
	return Products.size();
}
//void Receipt::deleteProduct(Product product) {
//	std::remove(Products.begin(), Products.end(), product.getName());
//}



//bool Receipt::isValidReceipt(std::string nazwa_sklepu, int date, std::vector<std::string>produkty) {
//	
//}
