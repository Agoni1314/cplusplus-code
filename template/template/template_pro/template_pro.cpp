#include<iostream>
#include<string>
#include<array>
#include<vector>

using namespace std;
#include"template_pro.h"

//#define N 5//这样定义的话两个栈都是5
//class stack
//{
//private:
//	int arr[N];
//	int top;
//};
//int main()
//{
//	stack s1;
//	stack s2;
//	return 0;
//}

//template<class T,size_t N=10>
//template<size_t N=10>
//template<size_t N,bool flag=false >//布尔值也是整形
template<size_t N>
class stack
{

private:
	int _arr[N];
	int _top;
};
//int main()
//{
//	/*stack st1;//c++20以后才支持这样写
//	stack st2;*/
//	/*stack<> st1;
//	stack<> st2;*/
//	stack<5> st3;
//	stack<10> st4;
//	return 0;
//}

//template<double N >//c++20以后才支持非整形
//class stack
//{
//
//private:
//	int _arr[N];
//	int _top;
//};
//int main()
//{
//	stack<5> st3;
//	stack<10> st4;
//	return 0;
//}

//int main()
//{
//	array<int, 10>a1;
//	//会检查越界
//	a1[9] = 3;
//
//	//堆
//	vector<int> v(10, 2);
//	cout << sizeof(v) << endl;
//	cout << sizeof(a1) << endl;
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
////恶心在这里
//template<class T>
//bool Less(const T& left,const T& right)//补全
//{
//	return left < right;
//}
//
//template <>//写一个特化，解决比较地址的问题，但有时很恶心，或者可以直接写一个函数
////bool Less<Date*>( const Date*& left, const Date*& right)//那这里也应该补全,但也不是对的,const在*前面就是修饰指针本身
////{
////	return *left < *right;
////}
//bool Less<Date*>( Date* const& left,  Date*const& right)
//{
//	return *left < *right;
//}
////bool Less<const Date*>(const Date* const& left,const Date* const& right)
////{
////	return *left < *right;
////}



//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//bool Less(const Date* left,const Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误,比较的是地址的大小
//	const Date* p3 = &d1;
//	const Date* p4 = &d2;
//	cout << Less(p3, p4) << endl;
//	return 0;
//}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
//偏特化
template<class T1>
class Data<T1, double>//只要第二个参数表是double类型
{
public:
	Data() { cout << "Data<T1, double>" << endl; }
private:
	int _d1;
	char _d2;
};
//偏特化，传的类型是指针
template <typename T1, typename T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};
template <typename T1, typename T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
};
template <typename T1, typename T2>
class Data<T1*, T2&>
{
public:
	Data() { cout << "Data<T1*, T2&>" << endl; }
};

//int main()
//{
//	Data<int, int>d1;
//	Data<int, char>d2;
//	Data<float, double>s3;
//	Data<char, double>d4;
//	Data<char, char>s5;
//
//	Data<char*, char*>d6;
//	Data<int*, char*>d7;
//
//	Data<char&, char&>d8;
//	Data<int&, char&>d9;
//
//	Data<char*, char&>d10;
//	Data<int*, char&>d11;
//	return 0;
//}

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	//func(1,2);
}