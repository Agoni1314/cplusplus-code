#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//引用折叠
//只要有左值引用参与，结果就是左值引用；只有全是右值引用，结果才是右值引用
typedef int& lref;
typedef int&& rref;

int n = 0;
lref& r1 = n; // r1 的类型是 int&
lref&& r2 = n; // r2 的类型是 int&
rref& r3 = n; // r3 的类型是 int&
rref&& r4 = 1; // r4 的类型是 int&&

// 由于引用折叠限定，f1形参类型为左值引用，导致实例化以后总会是⼀个左值引用
template<class T>
void f1(T& x)
{
}

// 由于引用折叠限定，f2形参类型为右值引用，实例化后可以是左值引用，也可以是右值引用
template<class T>
void f2(T&& x)
{
}

//int main()
//{
	//// 没有折叠->实例化为void f1(int& x)
	//f1<int>(n);
	////f1<int>(0); // 报错

	//// 折叠->实例化为void f1(int& x)
	//f1<int&>(n);
	//// f1<int&>(0); // 报错

	//// 折叠->实例化为void f1(int& x)
	//f1<int&&>(n);
	//// f1<int&&>(0); // 报错

	//// 折叠->实例化为void f1(const int& x)
	//f1<const int&>(n);
	//f1<const int&>(0); //const左值引用可以引用右值

	//// 折叠->实例化为void f1(const int& x)
	//f1<const int&&>(n);
	//f1<const int&&>(0);

	//// 没有折叠->实例化为void f2(int&& x)
	//// f2<int>(n); // 报错
	//f2<int>(move(n));
	//f2<int>(0);

	//// 折叠->实例化为void f2(int& x)
	//f2<int&>(n);
	//// f2<int&>(0); // 报错

	//// 折叠->实例化为void f2(int&& x)
	//// f2<int&&>(n); // 报错
	//f2<int&&>(0);

	//return 0;
//}
template<class T>
void Function(T&& t)
{
	int a = 0;
	T x = a;
	//x++;
	cout << &a << endl;
	cout << &x << endl << endl;
}
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)​
//	Function(10); 
//	int a;
//	//如果实参是左值：编译器会将 T 推导为左值引用类型（即 T = 实参类型 & ）。
//	//如果实参是右值：编译器会将 T 推导为非引用类型（即 T = 实参类型）。
//	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)​
//	Function(a); 
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)​
//	//Function(std::move(a)); 
//	const int b = 8;
//	// a是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int&t)
//	// 所以Function内部会编译报错，x不能++​
//	Function(b); 
//	
//		// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&t)
//		// 所以Function内部会编译报错，x不能++​
//		Function(std::move(b)); 
//		return 0;
//}
#include"list.h"
int main()
{
	xiaoye::list<xiaoye::string> lt;
	cout << "*************************" << endl;
	xiaoye::string s1("111111111111111111111");
	lt.push_back(s1);
	cout << "*************************" << endl;
	lt.push_back(xiaoye::string("22222222222222222222222222222"));
	cout << "*************************" << endl;
	lt.push_back("3333333333333333333333333333");
	cout << "*************************" << endl;
	lt.push_back(move(s1));
	cout << "*************************" << endl;
	return 0;
}

// 
//template<class ...args>
//void print(args&& ...arg)
//{
//	cout << sizeof...(arg)<<endl;
//}
//// 原理1：编译本质这里会结合引用折叠规则实例化出以下四个函数​
//void print();
//void print(int&& arg1);
//void print(int&& arg1, string&& arg2);
//void print(double&& arg1, string&& arg2, double& arg3);
//
//// 原理2：更本质去看没有可变参数模板，我们实现出这样的多个函数模板才能支持​
//// 这里的功能，有了可变参数模板，我们进一步被解放，他是类型泛化基础​
//// 上叠加数量变化，让我们泛型编程更灵活。​
//void print();
//template <class T1>
//void print(T1&& arg1);
//template <class T1, class T2>
//void print(T1&& arg1, T2&& arg2);
//template <class T1, class T2, class T3>
//void print(T1&& arg1, T2&& arg2, T3&& arg3);
//int main()
//{
//	print();
//	print(1);
//	print(1.1, string("111"), 3.5f);
//	return 0;
//}

//void showlist()
//{
//	cout << endl;
//}
//template<class T, class ...args>
//void showlist(T x, args...arg)
//{
//	cout << x << " ";
//	showlist(arg...);
//}
//template<class ...args>
//void print(args...arg)
//{
//	showlist(arg...);
//}
//int main()
//{
//	print( 1, string("111"), 2.4f);
//	return 0;
//}