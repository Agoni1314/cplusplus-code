#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;
#include"string.h"
namespace bit
{
	using box::string;
	void test_string1()
	{
		string s1; //s1是空的对象，用的是空指针
		string s2("hello world");
		/*std::string s1;  //上面不用空指针初始化，给一个\0和下面一样
		std::string s2("hello world");*/
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0;i < s2.size();i++)
		{
			s2[i] += 2;
		}
		cout << s2.c_str() << endl;//底层是运算符重载
		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;
		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			//*it += 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	
}
int main()
{
	//box::test_string2();
	box::test_string3();
	return 0;
}
