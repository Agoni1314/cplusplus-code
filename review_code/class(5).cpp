#include<iostream>
//class calendar
//{
//public:
//	friend bool operator==(calendar day, calendar day2);
//	void Init(int year, int month, int day)//成员函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//构造函数必须与类名完全同名
//	calendar(int year=1, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		std::cout << _year << "," << _month << "," << _day <<std::endl;
//	}
//	/*bool operator==(calendar day2)
//	{
//		return _year == day2._year 
//			&& _month == day2._month 
//			&& _day == day2._day;
//	}*/
//private:
//	size_t _year;
//	size_t _month;
//	size_t _day;
//	
//};
//bool operator==(calendar day, calendar day2)//写在类外面就要在声明的时候加友元函数
//{
//	return day._year == day2._year 
//		&& day._month == day2._month && 
//		day._day == day2._day;
//}
//int main()
//{
//	calendar day;//实例化
//	day.Init(2026, 12, 12);
//	//day.print();
//	//calendar day2;
//	//day2.print();//默认构造函数
//	calendar day2(2026, 12, 12);
//	 bool result=(day == day2);
//	 std::cout << result << std::endl;
//	return 0;
//}

//typedef int STDataType;
//class stack
//{
//public:
//	stack(int n=1)
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
//	~stack()//手动开辟的空间必须手写析构
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//		std::cout << "~stack" << std::endl;
//	}
//private:
//	STDataType* _a;
//	size_t _top;
//	size_t _capacity;
//};
//class queue
//{
//public:
//	~queue()
//	{
//		std::cout << "~queue" << std::endl;
//	}
//private:
//	stack _push;
//	stack _pop;
//};
//int main()
//{
//	//stack st1;
//	queue qu1;
//	return 0;
//}

//class calendar
//{
//public:
//	calendar(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		std::cout << _year << "," << _month << "," << _day << std::endl;
//	}
//	calendar(const calendar& day)
//	{
//		_year = day._year;
//		_month = day._month;
//		_day = day._day;
//		std::cout << "calendar" << std::endl;
//	}
//private:
//	size_t _year;
//	size_t _month;
//	size_t _day;
//};
//int main()
//{
//	calendar day(2020, 12, 12);
//	day.print();
//	calendar day2;//这里走默认构造
//	day2.print();
//	calendar day3(day);
//	day3.print();
//	calendar day4;
//	day4 = day3;//这里只是赋值，没有走拷贝构造
//	day3.print();
//	
//	return 0;
//}

//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
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
//	Stack(const Stack& st)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//	}
//	~Stack()
//	{
//		std::cout << "~Stack()" << std::endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack st2 = st1;
//	MyQueue mq1;
//	MyQueue mq2 = mq1;
//	return 0;
//}

//typedef int STDataType;
//class stack
//{
//public:
//	stack(int n = 1)
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
//	~stack()//手动开辟的空间必须手写析构
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//		std::cout << "~stack" << std::endl;
//	}
//private:
//	STDataType* _a;
//	size_t _top;
//	size_t _capacity;
//};
////stack func2()
////{
////	stack st;//st会调用一次构造函数
////	std::cout << &st << std::endl;
////	return st;//传值返回会调用一次拷贝构造
////}
//stack& func2()
//{
//	static stack st;
//	std::cout << &st << std::endl;
//	return st;//返回的是st的局部变量，但出函数时就销毁了，所以要加static
//}
//
//int main()
//{
//	stack ret = func2();
//	std::cout << &ret << std::endl;
//	return 0;
//}

class calendar
{
public:
	calendar(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	calendar(const calendar& day)
	{
		_year = day._year;
		_month = day._month;
		_day = day._day;
	}
	calendar& operator=(const calendar& da)
	{
		_year = da._year;
		_month = da._month;
		_day = da._day;
		return *this;
	}
	void print()
	{
		std::cout << _year << "," << _month << "." << _day << std::endl;
	}
private:
	size_t _year;
	size_t _month;
	size_t _day;
};
int main()
{
	calendar day1(2020,12,12);
	day1.print();
	calendar day2(2021,12,1);
	day2.print();
	calendar day3(day2);
	day3.print();
	day3 = day2 = day1;
	day3.print();
	return 0;
}