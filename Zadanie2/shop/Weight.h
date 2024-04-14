#pragma once
#include <iostream>
#include <vector>

enum class myUnit {
	kg,
	g,
	piece,
};

class Weight
{
private:
	double Number;
	myUnit Unit;

public:
	Weight();
	Weight(double number, myUnit unit);
	double getNumber();
	myUnit getUnit();
	void setNumber(double number);
	void setUnit(myUnit unit);
	std::string unitToString();
};
