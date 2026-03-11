#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<assert.h>
using namespace std;
namespace box
{
	class string
	{
	public:
		string()
		: _str(nullptr)
		, _size(0)
		,_capacity(0)
		{ }
		string(const char* str)
		{
			_size = strlen(str);
			//_capacity不包含"\0"，_size就不加1
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		const char* c_str()
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void test_string1();
	/*{
		string s1;
		string s2("hello world");//或者在函数名前面加inline或者static
	}*/
}

