#pragma once
namespace box
{
	template<class T, class Container=vector<T> >
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
		//void pop()
		//{
		//	_con.pop_front();//按需实例化,vector里面没有pop_front
		//}
		 const T& top()const
		{
			 return _con.back();
		}
		 size_t size()
		 {
			 return _con.size();
		 }
		 bool empty()const
		 {
			 return _con.empty();
		 }
	private:
		Container _con;
	};
}