#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
namespace box
{
	class string
	{
	public:
		typedef char* iterator;//自己写的string类不支持标准string类的迭代器，要自己实现一个
		typedef const char* const_iterator;//底层是数组才能使用原生指针做迭代器
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		/*string()
			:_str (new char[1]{'\0'})
			,_size(0)
			,_capacity(0)
		{ }*/
		string(const char* str="")
		{
			_size = strlen(str);//不包括\0
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str); 
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		const char* c_str()
		{
			return _str;
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t size() const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n);
		void push_back(char ch);
		string& operator+=(char ch);
		string& operator+=(const char* str);
		void append(const char* str);
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* ch);
		void erase(size_t pos, size_t len=npos );//缺省参数只能在声明的时候给
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const  size_t npos;
	};
	void test1();
	void test2();
}
