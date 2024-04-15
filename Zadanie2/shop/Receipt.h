#pragma once
#include <iostream>
#include <vector>
#include "../../Zadanie1/Date.h"
#include "Product.h"

class DuplicateProductException : public std::exception {
public:
	const char* what() const noexcept override {
		return "You can't duplicate products!";
	}
};

class Receipt
{
private:
	std::string ShopName;
	Date DateShop;
	std::vector<Product> Products;
public:
	Receipt(std::string shop_name, Date date_shop, std::vector<Product>products);
	void setShopName(std::string shop_name);
	std::string getShopName();
	void addProduct(Product produkt);
	std::vector<Product> getProducts();
	int getNumberOfProducts();
	std::string getSpecificProduct(std::string product);
	void deleteProduct(std::string product);
	double getPriceSum();
};
