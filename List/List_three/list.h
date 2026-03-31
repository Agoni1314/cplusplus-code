#pragma once
#include<iostream>
using namespace std;
namespace box
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& data=T())
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};
	template<class T>
	struct list_iterator
	{
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
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};
	template <class T>
	class list//链表的类
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T> iterator;
		iterator begin()
		{
			/*iterator it(_head->next);
			return it;*/
			return _head->_next;
		}
		iterator end()
		{
			return _head;
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
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_next = _head;
			_head->_prev = newnode;
			++_size;*/
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
		void erase(iterator pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
		}
		
		size_t size() const
		{
			return _size;
		}
		bool empty() const
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
		list<int> It;
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
		cout << endl;
		list<AA> Ita;
		Ita.push_back(AA());
		Ita.push_back(AA());
		Ita.push_back(AA());
		Ita.push_back(AA());
		list<AA>::iterator ita = Ita.begin();
		while (ita != Ita.end())
		{
			cout << (*ita)._a1 << ": " << (*ita)._a2 << endl;
			++ita;
		}
		cout << endl;
	}
}
