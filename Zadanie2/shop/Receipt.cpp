#include "Receipt.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <array>
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
	for (Product element : Products) {
		if (element.getName() == product.getName()) {
			throw DuplicateProductException();
		}
	}
	Products.push_back(product);
	std::cout << "Added: \n" << product << std::endl;
}

std::vector<Product> Receipt::getProducts() {
	return Products;
}

int Receipt::getNumberOfProducts() {
	return Products.size();
}

std::string Receipt::getSpecificProduct(std::string product) {
	for (Product element : Products) {
		if (element.getName() == product) {
			return "There is a product named: " + product;
	
		}
		
	}
}


void Receipt::deleteProduct(std::string product) {
	auto it = std::find_if(Products.begin(), Products.end(), [&product](const Product& p) {
		return p.getName() == product;
		});

	if (it != Products.end()) {
		Products.erase(it);
		std::cout << "Product '" << product << "' deleted successfully." << std::endl;
	}
	else {
		std::cout << "Product '" << product << "' not found." << std::endl;
	}
}

double Receipt::getPriceSum() {
	double sum = 0;
	for (Product element : Products) {
		sum += element.getPrice();

	}
	return sum;
}

