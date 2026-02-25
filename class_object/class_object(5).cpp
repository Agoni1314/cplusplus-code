//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	//explicit A(int a = 0)
//	A(int a = 0)
//	{
//		_a1 = a;
//	}
//
//	A(const A& aa)
//	{
//		_a1 = aa._a1;
//	}
//
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{
//	}
//
	/*void Print() {
		cout << _a1 << " " << _a2 << endl;
	}*/
//private:
//	int _a1;
//	int _a2;
//};
//
//class Stack
//{
//public:
//	void Push(const A& aa)
//	{
//		//...
//	}
//private:
//	A _arr[10];
//	int _top;
//};
//
//int main()
//{
//	A aa1(1);
//	aa1.Print();
//
//	// 隐式类型转换
//	// 2构造一个A的临时对象，再用这个临时对象拷贝构造aa2
//	// 编译器遇到连续构造+拷贝构造->优化为直接构造
//	A aa2 = 2;
//	aa2.Print();
//
//	A& raa1 = aa2;
//	const A& raa2 = 2;
//
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	Stack st;
//
//	A aa3(3);
//	st.Push(aa3);
//
//	st.Push(3);
//
//	// C++11
//	A aa5 = { 1, 1 };
//	const A& raa6 = { 2,2 };
//	st.Push(aa5);
//	st.Push({ 2,2 });
//
//	return 0;
//}

//#include<iostream>
//class Time
//{
//public:
//	Time(int hour)//int hour=1
//		:_hour(hour)
//	{
//		std::cout << "Time()" << std::endl;
//	}
//private:
//	int _hour;
//};
//
//class date
//{
//public:
//	date(int& x,int year, int month, int day)//初始化列表
//
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _n(1)
//		, _ret(x)
//		, _t(1)
//	{
//		
//
//	}
//
//	void Print() {
//		std::cout << _year<<"/"<<_month<<"/"<<_day <<std:: endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	//必须在初始化列表中初始化
//	const int _n;
//	int& _ret;
//	Time _t;//没有默认构造的自定义类型也要初始化列表
//};
//int main()
//{
//	int x = 0;
//	date d1(x,2020, 1, 1);
//	d1.Print();
//	//const int n = 1;只能在定义变量的时候初始化，并且不能改变
//	return 0;
//}

#include<iostream>
class date
{
public:
	date(int year, int month, int day)

		:_year(year)//尽可能走初始化列表
		, _month(month)
		

	{

	}

	void Print() {
		std::cout << _year << "/" << _month << "/" << _day << std::endl;
	}
private:
	//声明，缺省值->初始化列表
	int _year=1;
	int _month=1;
	int _day=1;
};
int main()
{
	//对象定义
	date d1(2020, 1, 10);
	d1.Print();
	/*date d2;
	d2.Print();*/
	return 0;
}