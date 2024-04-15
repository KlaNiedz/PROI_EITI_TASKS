#pragma once
#include <iostream>
#include <string>
#include "Amount.h"
#include "../../Zadanie1/Date.h"

class Product
{
private:
	std::string Name;
	Amount Prices;
	std::string Producer;
	int ProductNumber;
	Date EatByDate;
public:
	Product(std::string name, Amount prices, std::string producer, int product_number, Date eatbydate);
	std::string getName() const;
	Amount getAmount() const;
	std::string getProducer() const;
	Date getDate();
	int getProductNumber() const;
	double getPrice();
	void setName(std::string name);
	void setProducer(std::string producer);
	void setProductNumber(int product_number);
	bool findDuplicate(const Product product, std::vector<Product> products) const;
	friend std::ostream& operator<<(std::ostream& os, Product& product);
};

bool operator==(Product& prod,  Product& other);

std::ostream& operator<<(std::ostream& os, Product& product);

