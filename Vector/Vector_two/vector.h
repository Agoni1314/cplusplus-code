#pragma once
#include<iostream>
#include<assert.h>
#include<list>
using namespace std;
namespace box
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_stronge = nullptr;
			}
		}
		/*vector()//成员变量就算不写拷贝构造，也会先走初始化列表，初始化列表对于自定义类型会去调默认构造
		{ }*/
		//c++11
		vector() = default;//强制生成默认构造
		vector(const vector<T>& v)
		{
			for (auto& e: v)
			{
				push_back(e);
			}
		}
		//类模板的成员函数，还可以继续是函数模板
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(size_t n,const T& val=T())
		{
			reserve(n);
			for (size_t i = 0;i < n;i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0;i < n;i++)
			{
				push_back(val);
			}
		}
		void clear()
		{
			_finish = _start;
		}
		/*vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				clear();
				reserve(v.size());
				for (auto& e : v)
				{
					push_back(e);
				}
			}
			return *this;
		}*/
		void swap( vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_stronge, v._end_of_stronge);
		}
		//vector<T>& operator=( vector<T> v)
		vector& operator=(vector v)//类里面可以用类名替代类型
		{
			swap(v);
			return *this;
		}
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
				//memcpy(tmp, _start, size() * sizeof(T));
				for (size_t i = 0;i < old_size;i++)
				{
					 tmp[i] = _start[i];
				}
				delete[] _start;
				_start = tmp;
				_finish = tmp + old_size;
				_end_of_stronge = tmp + n;
			}
		}
		size_t size()const
		{
			return  _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_stronge - _start;
		}
		bool empty()const
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
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				it++;
			}
			--_finish;
			return pos;
		}
		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_stronge = nullptr;
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

	//template<class T>
	//void print_vactor(const vector<T>& v)
	//{
	//	//没有实例化的类模板里面取东西，编译器就不能区分这里的const_iterator
	//	//是类型还是静态成员变量
	//	typename vector<T>::const_iterator it = v.begin();
	//	while (it != v.end())
	//	{
	//		cout << *it << " ";
	//		++it;
	//	}
	//}
	template<class Container>
	void print_Container(const Container& v)
	{
		//没有实例化的类模板里面取东西，编译器就不能区分这里的const_iterator
		//是类型还是静态成员变量
		/*typename Container::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}*/
		for (auto it : v)
		{
			cout << it << " ";
			
		}
	}
	void test_vector1()
	{
		vector<string> v;
		v.push_back("111111111");
		v.push_back("111111111");
		v.push_back("111111111");
		v.push_back("111111111");
		print_Container(v);
		v.push_back("111111111");
		print_Container(v);
	}
}


//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);
	//cout << endl;
	//print_vactor(v);
	//cout << endl;
	//vector < double > vd;
	//vd.push_back(1.1);
	//vd.push_back(2.2);
	//vd.push_back(3.3);
	//vd.push_back(4.4);
	//vd.push_back(5.5);
	//print_Container(vd);
	//cout << endl;
	//vector<int> vv;
	//vv.push_back(1);
	//vv.push_back(2);
	//vv.push_back(3);
	//vv.push_back(4);
	////vv.push_back(5);
	//vv.insert(vv.begin() + 2, 30);
	//print_Container(vv);
	//cout << endl;
	//
	//int x;
	//cin >> x;
	//auto p = find(vv.begin(), vv.end(), x);
	//if (p != vv.end())
	//{
	//	//insert以后。p就失效了,要访问就要先更新这个失效的迭代器值
	//	/*vv.insert(p, 40);
	//	(*p) *= 10;*/
	//	vv.insert(p, 40);
	//	(*(p+1)) *= 10;
	//}
	//print_Container(vv);
	//cout << endl;

	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);

	print_Container(v);
	cout << endl;
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it= v.erase(it);
		}
		else
		{
			++it;
		}
	}
	print_Container(v);*/

	/*int i = int();
	int j = int(1);
	int k(2);
	vector<int> v;
	v.resize(10, 1);
	print_Container(v);*/
			/*vector<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			v.push_back(5);
			print_Container(v);
			cout << endl;
			vector<int>v1 = v;
			print_Container(v);
			cout << endl;
			vector<int> v3;
			v3.push_back(6);
			v3.push_back(7);
			v3.push_back(8);
			v3.push_back(9);
			v3.push_back(20);
			v=v3;
			print_Container(v);*/

			//vector<int> v;
					//v.push_back(1);
					//v.push_back(2);
					//v.push_back(3);
					//v.push_back(4);
					//v.push_back(5);
					//vector<int> v2(v.begin(), v.begin() + 3);
					//print_Container(v);
					//print_Container(v2);
					//cout << endl;
					//list<int> it;
					//it.push_back(10);
					//it.push_back(20);
					//it.push_back(30);
					//it.push_back(40);
					//it.push_back(50);
					//vector<int> v3(it.begin(), it.end());
					//print_Container(v3);
					//print_Container(it);
					//cout << endl;

					//vector<string>v4(10, "111111");
					//print_Container(v4);
					//cout << endl;

					//vector<int>v5(10);
					//print_Container(v5);
					//cout << endl;

					///*vector<string>v6(10u, "111111");
					//print_Container(v6);
					//cout << endl;*/

					//vector<string>v6(10, "111111");
					//print_Container(v6);
					//cout << endl;