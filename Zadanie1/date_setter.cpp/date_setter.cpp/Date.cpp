#include "Date.h"
#include <string>
#include "../../../Zadanie2/shop/UnitTest1/pch.h"

Date::Date(int day, myMonth month, int year) {
	if (isValidDate(day, month, year)) {
		Day = day;
		Month = month;
		Year = year;
	}
	else {
		std::cout << "Invalid date" << std::endl;
	}
}

//Date::Date() : Day(1), Month(myMonth::styczen), Year(2022) {}

void Date::setDay(int day) {
	if (!isValidDate(day, Month, Year)) {
		std::cout << "Invalid date" << std::endl; 
	}
	else {
		Day = day;
	};
}
int Date::getDay() {
	return Day;
}
void Date::setMonth(myMonth month) {
	Month = month;
}

myMonth Date::getMonth() {
	return Month;
}
void Date::setYear(int year) {
	Year = year;
}
int Date::getYear() {
	return Year;
}
string Date::PrintDate() {
	return std::to_string(Day) + "/" + std::to_string(static_cast<int>(Month)) + "/" + std::to_string(Year);

}

bool Date::isValidDate(int day, myMonth month, int year) {
	for (int i = 1; i < 13; i= i+2) {
	if (static_cast<int>(month) == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day > 29) {
				return false;
			}
			else if (day > 28) {
				return false;
			}
		}
	}
	else if (static_cast<int>(month) == 1 || static_cast<int>(month) == 3 || static_cast<int>(month) == 5 || static_cast<int>(month) == 7 || static_cast<int>(month) == 8 || static_cast<int>(month) == 10 || static_cast<int>(month) == 12) {
		if (day > 31) {
			return false;
		}
	}
	else if ((day < 1 || day >30 || static_cast<int>(month) < 0 || static_cast<int>(month) > 12 || year < 0)) {
		return false;
	}
		return true;
	}
}

string Date::monthToString(myMonth month){
	switch (month)
	{
	case myMonth::styczen:
		return "stycznia";
	case myMonth::luty:
		return "lutego";
	case myMonth::marzec:
		return "marca";
	case myMonth::kwiecien:
		return "kwietnia";
	case myMonth::maj:
		return "maja";
	case myMonth::czerwiec:
		return "czerwca";
	case myMonth::lipiec:
		return "lipca";
	case myMonth::sierpien:
		return "sierpnia";
	case myMonth::wrzesien:
		return "wrzesnia";
	case myMonth::pazdziernik:
		return "pazdziernika";
	case myMonth::listopad:
		return "listopada";
	case myMonth::grudzien:
		return "grudnia";

	}
}

string Date::printWordDate() {
	return std::to_string(Day) + " " + monthToString(Month) + " " + std::to_string(Year);
}