#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class calendar
{
public:
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year
			% 400 == 0)))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}
	calendar(int year, int month, int day);
	void print();
	calendar operator+(int day);
	calendar& operator+=(int day);
	calendar operator-(int day);
	calendar& operator-=(int day);

	bool operator<(const calendar& day);
	bool operator<=(const  calendar& day);
	bool operator>(const  calendar& day);
	bool operator>=(const calendar& day);
	bool operator==(const  calendar& day);
	bool operator!=(const  calendar& day);

private:
	int _year;//如果用size_t就会报错，size_t不能出现负数
	int _month;
	int _day;
};