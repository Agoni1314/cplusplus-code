#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<assert.h>
using namespace std;
namespace box
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
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		/*string()
		: _str(new char[1]{'\0'})
		, _size(0)
		,_capacity(0)
		{ }*/
		string(const char* str="")//可以改成全缺省，就可以把初始化列表省略
		{
			_size = strlen(str);
			//_capacity不包含"\0"，_size就不加1
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
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
			 char& operator[](size_t pos)//普通对象返回引用
			{
				assert(pos < _size);
				return _str[pos];
			}
			 const char& operator[](size_t pos) const//const对象返回const
			 {
				 assert(pos < _size);
				 return _str[pos];
			 }
			 void reserve(size_t n);
			 void push_back(char ch);
			 void append(const char* str);
			 string& operator+=(char ch);
			 string& operator+=(const char* str);
			 void insert(size_t pos, char ch);
			 void insert(size_t pos,const char* ch);
			 void erase(size_t pos, size_t len=npos);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const  size_t npos;
	};
	
	void test_string2();
	void test_string1();
	/*{
		string s1;
		string s2("hello world");//或者在函数名前面加inline或者static
	}*/
}

