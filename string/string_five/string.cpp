#define _CRT_SECURE_NO_WARNINGS 
#include"string.h"
#include<iostream>
#include<assert.h>
#include<string>
namespace box
{
	const size_t string::npos = -1;
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
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
			
		}
	}
	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		++_size;
		_str[_size]='\0';
	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	/*void test_string2()
	{
		
		string s1("hello world");
		s1 += 'x';
		s1 += '*';
		cout << s1.c_str() << endl;
	}*/
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//大于2倍，要多少就开多少，小于2倍按2倍扩
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		//挪动数据
		size_t end = _size;
		while (end >= pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		++_size;
	}
	void insert(size_t pos, const char* ch)
	{

	}
	/*void erase(size_t pos, size_t len = npos)
	{

	}*/
	void test_string2()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += '*';
		cout << s1.c_str() << endl;
		s1 += "hello china";
		cout << s1.c_str() << endl;
		s1.insert(5, '6');
		cout << s1.c_str() << endl;
	}
	
}