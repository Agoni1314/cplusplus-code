#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//struct Goods
//{
//	string _name; // 名字?
//	double _price; // 价格?
//	int _evaluate; // 评价?
//	// ...
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{
//	}
//};
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3
//	}, { "菠萝", 1.5, 4 } };
//	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中?
//	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了?
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) 
//		{
//		return g1._price < g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) 
//		{
//		return g1._evaluate > g2._evaluate;
//		});
//	return 0;
//}

//int x = 0;
//// 捕捉列表必须为空，因为全局变量不用捕捉就可以用，没有可被捕捉的变量​
//auto func1 = []()
//	{
//		x++;
//	};
//int main()
//{
//	// 只能用当前lambda局部域和捕捉的对象和全局对象​
//	int a = 0, b = 1, c = 2, d = 3;
//	auto func1 = [a, &b]
//		{
//			// 值捕捉的变量不能修改，引用捕捉的变量可以修改​
//			//a++;
//			b++;
//			int ret = a + b;
//			return ret;
//		};
//	cout << func1() << endl;
//	// 隐式值捕捉​
//	// 用了哪些变量就捕捉哪些变量​
//	auto func2 = [=]
//		{
//			int ret = a + b + c;
//			return ret;
//		};
//	cout << func2() << endl;
//	// 隐式引用捕捉​
//	// 用了哪些变量就捕捉哪些变量​
//	auto func3 = [&]
//		{
//			a++;
//			c++;
//			d++;
//		};
//	func3();
//	cout << a << " " << b << " " << c << " " << d << endl;
//	// 混合捕捉1​
//	auto func4 = [&, a, b]
//		{
//			//a++;
//			//b++;
//			c++;
//			d++;
//			return a + b + c + d;
//		};
//	func4();
//	cout << a << " " << b << " " << c << " " << d << endl;
//	// 混合捕捉1​
//	auto func5 = [=, &a, &b]
//		{
//			a++;
//			b++;
//			/*c++;
//			d++;*/
//			return a + b + c + d;
//		};
//	func5();
//	cout << a << " " << b << " " << c << " " << d << endl;
//	// 局部的静态和全局变量不能捕捉，也不需要捕捉​
//	static int m = 0;
//	auto func6 = []
//		{
//			int ret = x + m;
//			return ret;
//		};
//	// 传值捕捉本质是一种拷贝,并且被const修饰了​
//	// mutable相当于去掉const属性，可以修改了​
//	// 但是修改了不会影响外面被捕捉的值，因为是一种拷贝​
//	auto func7 = [=]()mutable
//		{
//			a++;
//			b++;
//			c++;
//			d++;
//			return a + b + c + d;
//		};
//	cout << func7() << endl;
//	cout << a << " " << b << " " << c << " " << d << endl;
//	return 0;
//}

//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	Plus(int n = 10)
//		:_n(n)
//	{
//	}
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return (a + b) * _n;
//	}
//private:
//		int _n;
//};
//#include<functional>
//int main()
//{
//	// 包装各种可调用对象​
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {return a + b;};
//	function<int(int, int)> f4 = &Plus::plusi;
//	// 包装静态成员函数​
//	// 成员函数要指定类域并且前面加&才能获取地址​
//	function<double(Plus*,double, double)> f5 = &Plus::plusd;
//	// 包装普通成员函数​
//	// 普通成员函数还有一个隐含的this指针参数，所以绑定时传对象或者对象的指针过去都可以
//	function<double(Plus, double, double)> f6 = &Plus::plusd;
//	Plus pd1;
//	function<double(double, double)> f7 = [&pd1](double a, double b) {return pd1.plusd(a, b);};
//	function<double(Plus&&, double, double)> f8 = &Plus::plusd;
//	cout << f1(1, 1) << endl;
//	cout << f2(1, 1) << endl;
//	cout << f3(1, 1) << endl;
//	cout << f4(1, 1) << endl;
//	Plus pd;
//	cout << f5(&pd,1.1, 1.1) << endl;
//	cout << f6(pd, 1.1, 1.1) << endl;
//	cout << f7(1.1, 1.1) << endl;
//	cout << f8(move(pd), 1.1, 1.1) << endl;
//	cout << f8(Plus(), 1.1, 1.1) << endl;
//	return 0;
//}

class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{
	}
	Person(const Person& p) = default;
	Person(Person&& p) = default;//强制生成移动构造后编译器不会生成拷贝构造
	Person(const Person& p)
	:_name(p._name)
	,_age(p._age)
	{}
	Person& operator=(const Person& p)
	{
	if(this != &p)
	{
	_name = p._name;
	_age = p._age;
	}
	return *this;
	}
	~Person()
	   {}
private:
	string _name;
	int _age;
};
int main()
{
	Person s1;
	Person s2 = s1;
	Person s3 = std::move(s1);
	Person s4;
	s4 = std::move(s2);
	return 0;
}