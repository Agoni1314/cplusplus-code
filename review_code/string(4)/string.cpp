#include"string.h"
namespace box
{
	const size_t string::npos = -1;
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
			reserve(_size == _capacity == 0 ? 4 : _capacity * 2);
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
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_size == _capacity == 0 ? 4 : _capacity * 2);
		}
		//方法一
		/*int end = _size;
		while (end>=(int)pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		++_size;*/
		//方法二
		size_t end = _size + 1;
		while (end>pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = ch;
		++_size;

	}
	void string::insert(size_t pos, const char* ch)
	{
		assert(pos <= _size);
		size_t len = strlen(ch);
		if (len + _size >= _capacity)
		{
			reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);
		}
		size_t end = _size + len;
		while (end > pos + len-1)
		{
			_str[end ]= _str[end - len];
			--end;
		}
		for (size_t i = 0;i < len;i++)
		{
			_str[pos+i] = ch[i];
		}
		_size += len;
	}
	void string::erase(size_t pos, size_t len )
	{
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size -= len;
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
	size_t string::find(char ch, size_t pos )
	{
		for (size_t i = pos;i <= _size;i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* ch, size_t pos )
	{
		const char* ret=strstr(_str, ch);
		if (ret == nullptr)
		{
			return npos;
		}
		else
		{
			return ret - _str;
		}

	}
	string string::substr(size_t pos, size_t len)
	{
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		string sub;
		sub.reserve(len);
		for (size_t i = pos;i < _size;i++)
		{
			sub += _str[pos + i];
		}
		return sub;

	}
	void test2()
	{
		/*string s1("hello world!");
		s1 += 's';
		cout << s1.c_str() << endl;*/
		/*string s1("hello world!");
		s1 += "6666666";*/
		//cout << s1.c_str() << endl;
		/*string s1("hello world!");
		s1.insert(0, 'x');
		cout << s1.c_str() << endl;*/
		/*string s2("hello world!");
		s2.insert(5, "****");
		cout << s2.c_str() << endl;*/
		/*string s2("hello world!");
		s2.erase(7, 6);
		cout << s2.c_str() << endl;

		string s3("hello world!");
		s3.erase(7, 2);
		cout << s3.c_str() << endl;

		string s4("hello world!");
		s3.erase(7, 0);
		cout << s4.c_str() << endl;*/

		string s1("test.cpp.zip");
		//cout << s1.find('o', 0) << endl;
		//cout<<s1.find("llo",0)<<endl;
		size_t pos = s1.find('.');
		string ret = s1.substr(pos);
		cout << ret.c_str() << endl;
		string copy(s1);
		cout << copy.c_str() << endl;
	}
}