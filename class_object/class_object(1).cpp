#include<iostream>
class calendar
{
public:
	//void Init(calendar* const this int year, int month, int day)
	void Init(int year, int month, int day)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	//void print(calendar* const this)
	void print()
	{
		//this->可写可不写
		std::cout <<this-> _year << "/" << this->_month << "/" <<this-> _day << std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	calendar day1;
	calendar day2;
	//函数调用形参和实参不能写this指针
	//day1.Init(&day1,2005,3,12);
	day1.Init(2005, 3, 12);
	//day1.print(&d1);
	day1.print();
	//day2.Init(&day2,2005,3,12);
	day2.Init(2009, 9, 19);
	//day2.print(&d2);
	day2.print();
	return 0;
}