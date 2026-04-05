#pragma once
#include<deque>
namespace box
{
	//用Container适配转换出stack
	//模板参数传类型
	template<class T, class Container=vector<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		const T& top()const
		{
			return _con.back();
		}
		size_t size() const
		{
			return _con.size();
		}
		bool empty()const
		{
			return _con.empty;
		}
	private:
		Container _con;
	};
	/*void func()
	{
		cout << "func()" << endl;
	}*/
}