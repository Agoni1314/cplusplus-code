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
	if (day < 0)
	{
		return *this -= (-day);
	}
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
bool Date::operator<(const Date & d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year==d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}
	return false;
}
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d)
{
	return !(*this <= d) ;
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;

}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
//d1++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
//++d1
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
int  Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}