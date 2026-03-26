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
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();//库里面的做法
				T* tmp = new T[n];
				memcpy(tmp, _start , size() * sizeof(T));
				delete[] _start;
				_start = tmp;
				_finish = tmp + old_size;
				_end_of_stronge = tmp+ n;
			}
		}
		size_t size()
		{
			return  _finish - _start;
		}
		size_t capacity()
		{
			return _end_of_stronge - _start;
		}
		bool empty()
		{
			return _start == _finish;
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_stronge)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
				*_finish = x;
				++_finish;
		}
		void pop_back()
		{
			assert(!empty());
			return --_finish;
		}
		iterator insert(iterator pos, const T& x)
		{
			if (_finish == _end_of_stronge)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _end_of_stronge=nullptr;
	};
	/*void print_vactor(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
	}*/
	template<class T>
	void print_vactor(const vector<T>& v)
	{
		//没有实例化的类模板里面取东西，编译器就不能区分这里的const_iterator
		//是类型还是静态成员变量
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		cout << endl;
		print_vactor(v);
		cout << endl;
		vector < double > vd;
		vd.push_back(1.1);
		vd.push_back(2.2);
		vd.push_back(3.3);
		vd.push_back(4.4);
		vd.push_back(5.5);
		print_vactor(vd);
		cout << endl;
		vector<int> vv;
		vv.push_back(1);
		vv.push_back(2);
		vv.push_back(3);
		vv.push_back(4);
		//vv.push_back(5);
		vv.insert(vv.begin() + 2, 30);
		print_vactor(vv);
		cout << endl;
		int x;
		cin >> x;
		auto p = find(vv.begin(), vv.end(), x);
		if (p != vv.end())
		{
			//insert以后。p就失效了,要访问就要先更新这个失效的迭代器值
			/*vv.insert(p, 40);
			(*p) *= 10;*/
			vv.insert(p, 40);
			(*(p+1)) *= 10;
		}
		print_vactor(vv);
	}
}