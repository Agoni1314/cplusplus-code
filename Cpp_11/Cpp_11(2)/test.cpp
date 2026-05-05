#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
#include<map>
using namespace std;
//struct Point
//{
//	int _x;
//	int _y;
//};
////int main()
////{
////	//c++98支持
////	Point p = { 1, 2 };
////
////	//c++11支持内置类型
////	int x1 = { 2 };
////	int x2{ 3 };
////	return 0;
////}
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// 自定义类型支持​
//	// 这里本质是用{ 2025, 1, 1}构造一个Date临时对象​
//	// 临时对象再去拷贝构造d1，编译器优化后合二为一变成{ 2025, 1, 1}直接构造初始化
//	Date d1 = { 2025, 1, 1 };
//	// 这里d2引用的是{ 2024, 7, 25 }构造的临时对象​
//	const Date& d2 = { 2024, 7, 25 };
//	Date d3 = { 2025 };//c++11支持
//	Date d4 = 2025;//c++98单参数的构造函数支持隐式类型转换
//	// 可以省略掉=​
//	Point p1{ 1, 2 };
//	int x2{ 2 };
//	Date d6{ 2024, 7, 25 };
//	const Date& d7{ 2024, 7, 25 };
//	// 只有{}初始化，才能省略=​
//	// Date d8 2025;
//	vector<Date> v;
//	v.push_back(d1);
//	v.push_back(Date(2025, 1, 1));
//	v.push_back({2025,1,1});//用{}隐式匹配Data
//	map<string, string> dict;
//	dict.insert({ "avc","sdf" });
//
//	vector<int> it{ 1,2,3,4 };
//	const vector<int>& its{ 1,2,3,4 };
//	// 构造
//	vector<int> v3({ 10,20,30,1,1,1,1,1,1,1,1,1 });
//
//	initializer_list<int> il1 = { 10, 20, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//	// initializer_list + {}pair初始化隐式类型转换
//	map<string, string> dict = { { "xxx", "yyyy" }, { "sort", "zzzz" } };
//	return 0;
//}

//int main()
//{
//	// 左值：可以取地址​
//	// 以下的p、b、c、*p、s、s[0]就是常见的左值​
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("111111");
//	s[0] = 'x';
//	cout << &c << endl;
//	cout << (void*)&s[0] << endl;
//	// 右值：不能取地址​
//	double x = 1.1, y = 2.2;
//	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值​
//	10;
//	x + y;
//	fmin(x, y);
//	string("11111");
//	/*cout << &10 << endl;
//	cout << &(x+y) << endl;
//	cout << &(fmin(x, y)) << endl;
//	cout << &string("11111") << endl;*/
//
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("111111");
//	s[0] = 'x';
//	double x = 1.1, y = 2.2;
//	// 左值引用给左值取别名​
//	int& r1 = b;
//	int*& r2 = p;
//	int& r3 = *p;
//	string& r4 = s;
//	char& r5 = s[0];
//	// 右值引用给右值取别名​
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	string&& rr4 = string("11111");
//	// 左值引用不能直接引用右值，但是const左值引用可以引用右值​
//	const int& rx1 = 10;
//	const double& rx2 = x + y;
//	const double& rx3 = fmin(x, y);
//	const string& rx4 = string("11111");
//	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)​
//	int&& rrx1 = move(b);
//	int*&& rrx2 = move(p);
//	int&& rrx3 = move(*p);
//	string&& rrx4 = move(s);
//	string&& rrx5 = (string&&)s;
//	// b、r1、rr1都是变量表达式，都是左值​
//	cout << &b << endl;
//	cout << &r1 << endl;
//	cout << &rr1 << endl;
//	// rr1的属性是左值，所以不能再被右值引用绑定，除非move一下​
//	int& r6 = r1;
//	// int&& rrx6 = rr1;
//	int&& rrx6 = move(rr1);
//	return 0;
//}

//void f(int& x)
//{
//	std::cout << "左值引用重载 f(" << x << ")\n";
//}
//void f(const int& x)
//{
//	std::cout << "到 const 的左值引用重载 f(" << x << ")\n";
//}
//void f(int&& x)
//{
//	std::cout << "右值引用重载 f(" << x << ")\n";
//}
//int main()
//{
//	int i = 1;
//	const int ci = 2;
//	f(i); // 调用 f(int&)​
//	f(ci); // 调用 f(const int&)​
//	f(3); // 调用 f(int&&)，如果没有 f(int&&) 重载则会调用 f(const int&)​
//	f(std::move(i)); // 调用 f(int&&)​
//	// 右值引用变量在用于表达式时是左值​
//	int&& x = 1;
//	f(x); // 调用 f(int& x)​
//	f(std::move(x)); // 调用 f(int&& x)​
//	return 0;
//}

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;
			reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}

		void swap(string& ss)
		{
			::swap(_str, ss._str);
			::swap(_size, ss._size);
			::swap(_capacity, ss._capacity);
		}

		 //移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			// 转移掠夺你的资源
			swap(s);
		}

		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" <<
				endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;
				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}
			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			//cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity *
					2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}
		
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
}
//int main()
//{
//	bit::string s1("xxxxx");
//	// 拷贝构造
//	bit::string s2 = s1;
//	// 构造 + 移动构造，优化后直接构造
//	bit::string s3 = bit::string("yyyyy"); //string没有实例化就是匿名对象，走移动构造
//	// 移动构造
//	bit::string s4 = move(s1);
//		
//
//	//bit::string s9("1111111111111");
//	//bit::string s5 = s9;
//	//bit::string s6 = bit::string("22222");
//	////s1的资源被s7拿走
//	//bit::string s7 = move(s1);
//	return 0;
//}


namespace box
{
	string addStrings(string num1, string num2)
	{
		string str;
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		int next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
			int ret = val1 + val2 + next;
			next = ret / 10;
			ret = ret % 10;
			str += ('0' + ret);
		}
		if (next == 1)
			str += '1';
		reverse(str.begin(), str.end());
		cout << "******************************" << endl;
		return str;
	}
}


int main()
{
	//移动构造
	string ret1 = box::addStrings("11111", "2222");//用str临时对象（右值）作为返回值会走移动构造
	cout << ret1.c_str() << endl;
	cout << &ret1 << endl;

	//移动赋值
	string ret2;//先默认构造
	ret2 = box::addStrings("11111", "2222");//通过str生成一个匿名临时对象赋值给ret2
	cout << ret2.c_str() << endl;
	cout << &ret2 << endl;
	return 0;
}

	
