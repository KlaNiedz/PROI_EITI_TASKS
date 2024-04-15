#pragma once
#include <iostream>
#include <vector>

enum class myCurrency {
	PLN,
	USD,
	EUR,
};

class Price
{
private:
	double Number;
	myCurrency Currency;

public:
	Price() = default;
	Price(double number, myCurrency currency);
	myCurrency getCurrency() const;
	double getNumber() const;
	void setCurrency(myCurrency& currency);
	void setNumber(double number);
	std::string currencyToString() const;
	friend std::ostream& operator<<(std::ostream& os, const Price& price);
	friend std::istream& operator>>(std::istream& is, myCurrency& currency);
	friend std::istream& operator>>(std::istream& is, Price& price);

};

std::ostream& operator<<(std::ostream& os, const Price& price);
std::istream& operator>>(std::istream& is, myCurrency& currency);
std::istream& operator>>(std::istream& is, Price& price);