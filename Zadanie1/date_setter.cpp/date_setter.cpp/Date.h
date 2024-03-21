#pragma once
#include <iostream>;
using std::string;

enum class myMonth {
	styczen = 1,
	luty,
	marzec,
	kwiecien,
	maj,
	czerwiec,
	lipiec,
	sierpien,
	wrzesien,
	pazdziernik,
	listopad,
	grudzien,
};


class Date
{
private:
	int Day;
	myMonth Month;
	int Year;
public:
	Date(int day, myMonth month, int year);
	Date(): Day(1), Month(myMonth::styczen), Year(2022){}
	void setDay(int day);
	int getDay();
	void setMonth(myMonth month);
	myMonth getMonth();
	void setYear(int year);
	int getYear();

	string PrintDate();
	//void StringDate();
	bool isValidDate(int day, myMonth month, int year);

	string monthToString(myMonth month);
	string printWordDate();
};

