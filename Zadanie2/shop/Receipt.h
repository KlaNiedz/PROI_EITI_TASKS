#pragma once
#include <iostream>
#include <vector>
#include "../../Zadanie1/Date.h"
#include "Product.h"

class Receipt
{
private:
	std::string ShopName;
	Date DateShop;
	std::vector<Product> Products;
public:
	Receipt(std::string shop_name, Date date_shop, std::vector<Product>products);
	//bool isValidReceipt(std::string nazwa_sklepu, int date, std::vector<std::string>produkty);
	void setShopName(std::string shop_name);
	std::string getShopName();
	void addProduct(Product produkt);
	std::vector<Product> getProducts();
	int getNumberOfProducts();
	std::string getSpecificProduct(std::string product);
	//void deleteProduct(Product produkt);
};
