#pragma once
#include<iostream>
#include<assert.h>
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
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node ->_data;
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
	/*template<class T>
	struct list_const_iterator
	{
		typedef list_node<T> Node;
		typedef list_const_iterator<T> Self;
		Node* _node;
		list_const_iterator(Node* node)
			:_node(node)
		{
		}
		const T& operator*()
		{
			return _node->_data;
		}
		const T* operator->()
		{
			return &_node->_data;
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
	};*/
	template <class T>
	class list//链表的类
	{
		typedef list_node<T> Node;
	public:
		/*typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;*/
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
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
		const_iterator begin()const
		{
			return _head->_next;
		}
		const_iterator end()const
		{
			return _head;
		}
		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list()
		{
			empty_init();
		}
		list(initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}
		list(const list<T>& It)
		{
			empty_init();
			for (auto& e : It)
			{
				push_back(e);
			}
			
		}
		
		list<T>& operator=(list<T> It)
		{
			swap(It);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void swap(list<T>& It)
		{
			std::swap(_head,It._head);
			std::swap(_size, It._size);
		}
		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it=erase(it);
			}
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
		iterator insert(iterator it, const T& x)
		{
			Node* cur = it._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;
			++_size;
			return newnode;
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
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
			return next;
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
	template <class Container>
	void print_Container(const Container& con)
	{
		list<int>::const_iterator it = con.begin();
		while (it != con.end())
		{
			//*it += 10;//const对象用const迭代器只读
			cout << *it << " ";
			++it;
		}
		for (auto e : con)
		{
			cout << e << " ";
			cout << endl;
		}
	}
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
			*it += 10;//普通对象可读可写
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : It)
		{
			cout << e << " ";
		}
		cout << endl;
		print_Container(It);


		list<AA> Ita;
		Ita.push_back(AA());
		Ita.push_back(AA());
		Ita.push_back(AA());
		Ita.push_back(AA());
		list<AA>::iterator ita = Ita.begin();
		while (ita != Ita.end())
		{
			//cout << (*ita)._a1 << ": " << (*ita)._a2 << endl;
			//做特殊处理，本应该是连个箭头，为了可读性，省了一个箭头
			cout << ita->_a1 << ":" << ita->_a2 << endl;
			cout << ita.operator->()->_a1 << ":" << ita.operator->()->_a2 << endl;
			++ita;
		}
		cout << endl;
		print_Container(It);
	}
	void test2()
	{
		list<int> It;
		It.push_back(1);
		It.push_back(2);
		It.push_back(3);
		It.push_back(4);
		list<int>::iterator it = It.begin();
		It.insert(it, 10);
		*it += 100;
		print_Container(It);
		cout << endl;
		it = It.begin();
		while (it != It.end())
		{
			if (*it % 2 == 0)
			{
				it = It.erase(it);
			}
			else
			{
				++it;
			}
		}
		print_Container(It);
	}
	void test3()
	{
		list<int> It;
		It.push_back(1);
		It.push_back(2);
		It.push_back(3);
		It.push_back(4);
		/*list<int> It2(It);
		print_Container(It);
		print_Container(It2);*/
		list<int> It3;
		It3.push_back(1);
		It3.push_back(2);
		It3.push_back(3);
		It3.push_back(4);
		It = It3;
		print_Container(It);
		print_Container(It3);
	}
	void func(const list<int>& It)
	{
		print_Container(It);
	}
	void test4()
	{
		/*std::list<int> s = { 1,2,3,4 };
		print_Container(s);*/
		/*auto s = { 1,2,3 };
		cout << typeid(s).name() << endl;*/
		//直接构造
		list<int> It0({ 1,2,3,4,5 });
		//隐式类型转换
		list<int> It1{ 1,2,3,4,5,6,7,8,9 };
		print_Container(It1);

		func(It0);
		func({ 1,2,3,4,5,6,7,8,9 });
	}
}
