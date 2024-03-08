#pragma once
#include <iostream>

// using std::string;  << nie ¿ywaæ w plikach nag³ówkowych

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
	void setDay(int day);
	int getDay() const;
	void setMonth(myMonth month);
	myMonth getMonth() const;
	void setYear(int year);
	int getYear();

	std::string PrintDate();
	//void StringDate();
	bool isValidDate(int day, myMonth month, int year);

	std::string monthToString(myMonth month);
	std::string printWordDate();
};

