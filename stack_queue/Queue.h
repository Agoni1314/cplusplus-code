#pragma once
#pragma once
#include<list>
#include<deque>

namespace box
{
	//用Container适配转换出list
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		const T& front()const
		{
			return _con.front();
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