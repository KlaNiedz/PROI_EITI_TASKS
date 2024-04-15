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
	double getNumber() const;
	myUnit getUnit();
	void setNumber(double number);
	void setUnit(myUnit unit);
	std::string unitToString() const;
	friend std::ostream& operator<<(std::ostream& os, const Weight& weight);

};

std::ostream& operator<<(std::ostream& os, Weight& weight);

