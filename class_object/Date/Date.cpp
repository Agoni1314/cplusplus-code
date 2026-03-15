#include"Date.h"
calendar::calendar(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void calendar::print()
{
	cout << _year << "," << _month << "," << _day << endl;
}
//bool calendar::operator==(const calendar& day)
//{
//	return _year == day._year &&
//		_month == day._month &&
//		_day == day._day;
//}
calendar& calendar::operator+=(int day)
{
	assert(day > 0);
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
calendar calendar::operator+(int day)
{
	calendar tmp = *this;
	tmp += day;
	/*tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}*/
	return tmp;
 }
// 
calendar& calendar::operator-=(int day)
{
	if (day < 0) return *this += -day;
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
	_day += GetMonthDay(_year, _month);
	}
	return *this;
}
calendar calendar::operator-(int day)
{
	calendar tmp = *this;
	tmp -= day;
	return tmp;
}
bool calendar::operator<(const calendar& day)
{
	if (_year < day._year)
	{
		return true;
	}
	else if (_year == day._year)
	{
		if (_month > day._month)
		{
			return true;
		}
		else if (_month = day._month)
		{
			if (_day > day._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool calendar::operator<=(const  calendar& day)
{
	return *this < day || *this == day;
}
bool calendar::operator>(const  calendar& day)
{
	return !(*this <= day);
}
bool calendar::operator>=(const calendar& day)
{
	return *this > day || *this == day;
}
bool calendar::operator==(const  calendar& day)
{
	return _year == day._year &&
		_month == day._month &&
		_day == day._day;
}
bool calendar::operator!=(const  calendar& day)
{
	return (*this == day);
}