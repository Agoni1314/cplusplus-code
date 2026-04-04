#pragma once
#include<iostream>
#include<cassert>
using namespace std;
namespace box
{
	template <class T>
	struct list_node
	{
		T _data;
		list_node<T>* _prev;
		list_node<T>* _next;
		list_node(const T& data = T())//给默认值
			:_data(data)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};
	template <class T>
	class list_iterator
	{	
	public:
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{}
		T& operator*()
		{
			return _node->_data;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator !=(const Self& s)
		{
			return _node != s._node;
		}
	};
	template <class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T> iterator;
		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		void swap(list<T>& id)
		{
			std::swap(_head, id._head);
			std::swap(_size, id._size);
		}
		list<T>& operator=( list<T> d)
		{
			swap(d);
			return *this;
		}
		list(const list<T>& d)
		{
			empty_init();
			for(auto sc:d)
				push_back(sc);
		}
		const iterator begin()const
		{
			return _head->_next;
		}
		const iterator end()const
		{
			return _head;
		}
		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
				++it;
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void insert(iterator it, const T& x)
		{
			Node* cur = it._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;
			++_size;
		}
		
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* next = pos._node->_next;
			Node* prev = pos._node->_prev;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
			return next;
		}
		size_t size()const
		{
			return _size;
		}
		bool empty()const
		{
			return _size == 0;
		}
	private:
		Node* _head;
		size_t _size;
	};
	struct AA
	{
		int _a1 = 1;
		int _a2 = 1;
	};
	 void test1()
	{
		/*list<int> It;
		It.push_back(1);
		It.push_back(2);
		It.push_back(3);
		It.push_back(4);
		list<int>::iterator it = It.begin();
		while (it != It.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;*/
		/*list<AA> its;
		its . push_back(AA());
		its.push_back(AA());
		its.push_back(AA());
		its.push_back(AA());
		list<AA>::iterator sc = its.begin();
		while (sc != its.end())
		{
			cout << (*sc)._a1 << ":" << (*sc)._a2 << endl;
			++sc;
		}
		cout << endl;*/
	 } 
	 void test2()
	 {
		 list<int> it;
		 it.push_back(1);
		 it.push_back(2);
		 it.push_back(3);
		 it.push_back(4);
		 list<int>::iterator sc = it.begin();
		 it.insert(sc, 66);
		 //sc= it.begin();//需要重新获取头指针
		 //while ( sc!= it.end())
		 //{
			// cout <<*sc << " ";
			// ++sc;
		 //}
		 for (auto sc : it)
		 {
			 cout << sc << " ";
		 } 
		 cout << endl;
	 }
	 void test3()
	 {
		 list<int> it;
		 it.push_back(1);
		 it.push_back(2);
		 it.push_back(3);
		 it.push_back(4);
		 it.push_back(3);
		 list<int>::iterator sc = it.begin();
		 while (sc != it.end())
		 {
			 if (*sc % 2 == 0)
			 {
				 sc = it.erase(sc);
				
			 }
			 else
			 {
				 cout << *sc << " ";
				 ++sc;
			 }
		 } 
	 }
	 void test4()
	 {
		 list<int> it;
		 it.push_back(1);
		 it.push_back(2);
		 it.push_back(3);
		 it.push_back(4);
		 it.push_back(3);
		 list<int> it2;
		 it2 = it;
		 for (auto sc : it2)
		 {
			 cout << sc << " ";
		 }
	 }
};