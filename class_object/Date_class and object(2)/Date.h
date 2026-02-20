#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1);
	void print();

	//默认是inline
	int GetMonthDay(int year, int month, int day)
	{
		assert(month > 0 && month < 13);
		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year
			% 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	//bool operator!=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	
private:
	int _year;
	int _month;
	int _day;
};

