#pragma once
#include <iostream>
#include <vector>

class Paragon
{
private:
	std::string NazwaSklepu;
	int Date;
	std::vector<std::string> Produkty;
public:
	Paragon(std::string nazwa_sklepu, int date, std::vector<std::string>produkty);
	bool isValidReceipt(std::string nazwa_sklepu, int date, std::vector<std::string>produkty);
};

