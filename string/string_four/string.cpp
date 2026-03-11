#define _CRT_SECURE_NO_WARNINGS 
#include"string.h"
#include<iostream>
#include<assert.h>
#include<string>
namespace box
{
	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}
}