#include"string.h"
namespace box
{
	
	void test1()
	{
		string s1;//可以在类前面加std::，这样就不会调用我们写的string类，而是用标准dtring类，就会指向合法的空字符串
		string s2("hello world");
		cout << s1.c_str() << endl;//s1是空的_str对象，用空指针初始化_str，char*就会解引用，遇到\0才停下来
		cout << s2.c_str() << endl;
		for (size_t i = 0;i < s2.size();i++)
		{
			s2[i] += 2;
		}
		cout << s2.c_str() << endl;
		for (auto sc : s2)
		{
			cout << sc << " ";
		}
		cout << endl;
		string::iterator s = s2.begin();
		while (s != s2.end())
		{
			cout << *s << " ";
			s++;
		}
		cout << endl;
		for (auto k : s2)//遍历每一个字符
		{
			cout << k << ' ';
		}
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_size == _capacity == 0 ? 2 : _capacity * 2);
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
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (len + _size > _capacity)
		{
			reserve(len+_size>2*_capacity? len + _size: 2 * _capacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void test2()
	{
		/*string s1("hello world!");
		s1 += 's';
		cout << s1.c_str() << endl;*/
		string s1("hello world!");
		s1 += "6666666";
		cout << s1.c_str() << endl;
	}
}