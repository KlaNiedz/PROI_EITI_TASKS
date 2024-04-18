#pragma once
#include <iostream>
#include <vector>

enum class myUnit {   // mo�na wewn�rtrz klasy
	kg,
	g,
	piece,
};
// doda� tu "kg", ... i tu funkcje opruj�ce na myUnit
// stringToUnit(amount_unit) ...

class Weight
{
public : 
private:
	double Number;
	myUnit Unit;

public:
	Weight();
	Weight(double number, myUnit unit);
	double getNumber() const;
	myUnit getUnit() const;
	void setNumber(double number);
	void setUnit(myUnit unit);
	std::string unitToString() const;
	friend std::ostream& operator<<(std::ostream& os, const Weight& weight);

};

std::ostream& operator<<(std::ostream& os, Weight& weight);

