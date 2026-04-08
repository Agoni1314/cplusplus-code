#pragma once
#include<deque>
namespace bix
{
	//template<class T ,class Container=list<T>>
	template<class T, class Container = deque<T>>
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
		size_t size()const
		{
			return _con.size();
		}
		bool empty()const
		{
			return _con.empry();
		}
	private:
		Container _con;
	};

}