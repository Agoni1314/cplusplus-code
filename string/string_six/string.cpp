#define _CRT_SECURE_NO_WARNINGS 
#include"string.h"
#include<iostream>
#include<assert.h>
#include<string>
namespace box
{
	const size_t string::npos = -1;

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
		_str[_size] = '\0';
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
		//size_t end = _size;
		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		++_size;
	}
	void string::insert(size_t pos, const char* s)
	{
		assert(pos <= _size);
		size_t len = strlen(s);
		if (_size + len > _capacity)
		{
			//大于2倍，要多少就开多少，小于2倍按2倍扩
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		size_t end = _size + len;
		while (end > pos + len-1)
		{
			_str[end] = s[end-len];
			--end;
		}
		for (size_t i = 0;i < len;i++)
		{
			_str[pos + i] = s[i];
		}
		_size += len;
	}
	void string::erase(size_t pos, size_t len)
	{
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos + len;i <= _size;i++)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
		}
	}
	size_t string::find(char ch, size_t pos = 0)
	{
		for (size_t i = pos;i <_size;i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos = 0)
	{
		const char* ptr = strstr(_str + pos, str);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}
	string string::substr(size_t pos = 0, size_t len = npos)
	{
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		string sub;
		sub.reserve(len);
		for (size_t i = 0;i < len;i++)
		{
			sub += _str[pos + i];
		}
		return sub;
	}
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
		s1.insert(0, '$');
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.insert(5, "***");
		cout << s2.c_str() << endl;

	}
	void test_string3()
	{
		string s1("hello world");
		s1.erase(6, 100);
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.erase(6);
		cout << s2.c_str() << endl;

		string s3("hello world");
		s2.erase(6,3);
		cout << s3.c_str() << endl;
	}
}