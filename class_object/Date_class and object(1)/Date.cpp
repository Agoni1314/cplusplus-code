#include"Date.h"
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void Date::print()
{
	cout << _year << "/" << _month << "/" << _day<<"\n";
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month,tmp._day))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month,tmp._day);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;
}

