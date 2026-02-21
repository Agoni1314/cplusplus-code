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
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	/*tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month,tmp._day))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month,tmp._day);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}*/
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	/*tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		--tmp._month;
		if (tmp._month <1)
		{
			--tmp._year;
			tmp._month = 12;
		}
	}*/
	return tmp;
}

