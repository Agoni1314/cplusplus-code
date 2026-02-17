//#include<iostream>
//class calendar
//{
//public:
//	//void Init(calendar* const this int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	//void print(calendar* const this)
//	void print()
//	{
//		//this->可写可不写
//		std::cout <<this-> _year << "/" << this->_month << "/" <<this-> _day << std::endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	calendar day1;
//	calendar day2;
//	//函数调用形参和实参不能写this指针
//	//day1.Init(&day1,2005,3,12);
//	day1.Init(2005, 3, 12);
//	//day1.print(&d1);
//	day1.print();
//	//day2.Init(&day2,2005,3,12);
//	day2.Init(2009, 9, 19);
//	//day2.print(&d2);
//	day2.print();
//	return 0;
//}

//#include<iostream>
//class calendar
//{
//public:
//	//无参构造函数
//	/*calendar()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}*/
//	//有参构造函数
//	/*calendar(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//全缺省构造函数
//	/*calendar(int year=1, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	void print()
//	{
//		std::cout << _year << "/" << _month << "/" << _day<<"\n";
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	calendar day1;//无参不能加括号，会和函数声明分不开
//	day1.print();
//	//calendar day2(2026);
//	//day2.print();
//	/*calendar day3(2026, 4, 12);
//	day3.print();*/
//	return 0;
//}

//#include<iostream>
//using namespace std;
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n=4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_capacity =_top = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的构造函数调用了Stack的构造，完成了两个成员的初始化
//	//编译器默认生成MyQueue的析构函数调用了Stack的析构，释放的Stack内部的资源
//	// 显示写析构，也会自动调用Stack的析构
//~MyQueue()
//{}
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	MyQueue mq;
//	//Stack st1;//后定义的先析构
//	//Stack st2;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class calendar
//{
//public:
//	calendar(int year=1, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		std::cout << _year << "/" << _month << "/" << _day << "\n";
//	}
//	/*int GetYear()
//	{
//		return _year;
//	}*/
//	bool operator==(calendar da2)
//	{
//		return _year == da2._year
//			&& _month == da2._month
//			&& _day == da2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////bool operator<(calendar da1, calendar da2)
////{
////
////}
////bool operator==(calendar da1, calendar da2)//可以写在类的公有
////{
////	return da1._year == da2._year && da1._month == da2._month && da1._day == da2._day;
////}
//int main()
//{
//	calendar da1(2003,12,2);
//	calendar da2(2012,12,2);
//	//operator==(da1, da2);//显式
//	//operator==(da1, da2);
//	//da1 == da2;//隐式
//	da1.operator==(da2);
//	da1 == da2;
//	return 0;
//}

//#include<iostream>
//class calendar
//{
//public:
//	calendar(int year=1, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	/*calendar(const calendar& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	void print()
//	{
//		std::cout << _year << "/" << _month << "/" << _day<<"\n";
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void func1(calendar d)
//{
//	std::cout << &d << std::endl;
//	d.print();
//}
//int main()
//{
//	calendar day1(2023,12,3);
//	day1.print();
//	//传值传参要调用拷贝构造
//	func1(day1);
//	calendar day2(day1);
//	day2.print();
//	
//	return 0;
//}

#include<iostream>
using namespace std;
typedef int STDataType;
class Stack
{
public:
	Stack(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = n;
		_top = 0;
	}
	Stack(const Stack& st)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		memcpy(_a, st._a, sizeof(STDataType) * st._top);
		_top = st._top;
		_capacity = st._capacity;
	}
	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;
	}
	~Stack()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};
// 两个Stack实现队列
class MyQueue
{
public:
private:
	Stack pushst;
	Stack popst;
};
int main()
{
	Stack st1;
	st1.Push(1);
	st1.Push(2);
	// Stack不显示实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
	Stack st2 = st1;
	MyQueue mq1;
	// MyQueue自动生成的拷贝构造，会自动调用Stack拷贝构造完成pushst/popst
	// 的拷贝，只要Stack拷贝构造自己实现了深拷贝，他就没问题
	MyQueue mq2 = mq1;
	return 0;
}
