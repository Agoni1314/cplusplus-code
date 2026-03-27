#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace box
{
	template<class T>
	
	class vector
	{
	public:
		typedef T* iterator;
		typedef T* const_iterator;
		const_iterator cbegin()const
		{
			return _start;
		}
		const_iterator cend()const
		{
			return _finish;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		size_t capacity()const
		{
			return  _end_capacity -_start;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n>capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));
				delete[] _start;
				_start = tmp;
				_finish = tmp + old_size;
				_end_capacity = tmp + n;
			}
		}
		void push_back(const T& x)
		{
			if (_end_capacity== _finish)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			++_finish;
		}
		bool empty()
		{
			return _finish - _start;
			
		}
		iterator pop_back()
		{
			assert(!empty());
			return --_finish;
			
			
		}
		iterator insert(iterator pos,const size_t x)
		{
			
			if (_finish == _end_capacity)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = len + _start;//没有这句就会出现迭代器失效
			}
			iterator end = _finish-1;
			while (end>=pos)
			{
				*(end + 1) = *end;
				--end; 
			}
			*pos = x;
			++_finish;
			return pos;
		}
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _end_capacity=nullptr;
	};
	template<class T>
	void print_answer(const vector<T>& v)
	{
		typename  vector<T>::const_iterator it = v.cbegin();
		while (it != v.cend())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		print_answer(v);
		v.insert(v.begin()+2,666 );
		print_answer(v);

	}
}