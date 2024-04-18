#include "Weight.h"

Weight::Weight() : Number(0.0), Unit(myUnit::kg) {}
Weight::Weight(double number, myUnit unit) :Number(number), Unit(unit) {};

double Weight::getNumber() const{
	return Number;
}

myUnit Weight::getUnit() const
{
	return Unit;
}

void Weight::setNumber(double number) {
	Number = number;
}

void Weight::setUnit(myUnit unit) {
	Unit = unit;
}

 std::string Weight::unitToString() const {
	switch (Unit) {
	case myUnit::kg:
		return "kg";
	case myUnit::g:
		return "g";
	case myUnit::piece:
		return "piece";
	default:
		return "Unknown";
	}
}

 std::ostream& operator<<(std::ostream& os, const Weight& weight)
 {
	 os << weight.getNumber() << weight.unitToString() << std::endl;
	 return os;
 }
