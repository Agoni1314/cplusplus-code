#include"string.h"
namespace box
{
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
		size_t ret = s1.find('c');
		string ret2 = s1.substr(ret, 10);
		cout << ret2.c_str() << endl;
		string copy(s1);
		cout << copy.c_str() << endl;
		string s2;
		s2 = s1;
		cout << s2.c_str() << endl;
	}
	void test3()
	{
		string s1("hello world");
		string s2("hello world");
		cout << (s1 < s2) << endl;
		cout << ("hello" < s1) << endl;//单参数构造函数支持隐式类型转换，因为string支持用const字符串去构造，会隐式转化为string
		cout << (s2 > "hello world") << endl;
		//cout << ("hello world" > "hello world") << endl;//必须要有一个类类型
		cout << s1 << s2 << endl;
		s1.clear();
		cin >> s1;
		cout << s1 << endl;

	}

}
int main()
{
	box::test3();
	return 0;
}