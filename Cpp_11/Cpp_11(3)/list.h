#pragma once
namespace xiaoye
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;

			reserve(s._capacity); //拷贝构造需要额外再开辟空间进行拷贝数据
			for (auto e : s)
			{
				push_back(e);
			}
		}

		// 移动构造
		string(string&& rs)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(rs); //移动构造只需要"掠夺"右值引用形参的资源即可实现构造
		}

		//拷贝赋值
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" << endl;

			if (this != &s)
			{
				_str[0] = '\n';
				_size = 0;
				reserve(s._capacity); //拷贝赋值需要额外再开辟空间进行拷贝赋值数据
				for (auto e : s)
				{
					push_back(e);
				}
			}
			return *this;
		}

		//移动赋值
		string& operator=(string&& rs)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(rs); //移动赋值只需要"掠夺"右值引用形参的资源即可实现赋值 
			//并且不需要手动先删除旧数据，交换完后出了函数形参rs就会带着旧数据一起被销毁
			return *this;
		}

		void reserve(size_t new_capacity)
		{
			if (new_capacity > _capacity)
			{
				char* tmp = new char[new_capacity + 1];
				if (_str)//_str不为空才能进行delete，否则会报错
				{
					strcpy(tmp, _str);
					delete[]_str;

				}
				_str = tmp;
				_capacity = new_capacity;
			}
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};

	//链表结点
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		////左值引用版本的链表结点构造
		//ListNode(const T& data = T())
		//	:_next(nullptr)
		//	, _prev(nullptr)
		//	, _data(data)
		//{
		//}
		////右值引用版本的链表结点构造
		//ListNode(T&& data)
		//	:_next(nullptr)
		//	, _prev(nullptr)
		//	, _data(forward<T>(data))
		//{
		//}

		//无参构造
		ListNode()
			:_next(nullptr)
			, _prev(nullptr)
			, _data(T())
		{
		}

		//万能引用
		//需要注意的是当实现成万能引用时就必须传入一个参数，否则无法将模板参数X进行实例化
		//而如果这样空链表的初始化就需要额外写一个无参的构造函数了
		template<class X>
		ListNode(X&& data)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(forward<X>(data)) //拷贝构造或者移动构造
			//由于data自身属性是左值，为了成功调用合适的引用版本的构造我们就需要进行完美转发保持属性一致
		{
		}
	};

	//链表迭代器
	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		Node* _node;
		ListIterator(Node* node)
			:_node(node)
		{
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};

	//链表
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		////左值引用版本的尾插
		//void push_back(const T& x)
		//{
		//	insert(end(), x);
		//}

		////右值引用版本的尾插
		//void push_back(T&& x)
		//{
		//	insert(end(),  forward<T>(x));
		//}
		////这个并不是万能引用
		////因为T是list的模板参数，当xiaoye::list<xiaoye::string>实例化后，参数T就已经确定为xiaoye::string了
		////而并没有通过传入的实参类型为左值还是右值而进行二次推导的过程，
		////所以我们不能只写这个右值引用版本，否则左值数据的插入就会找不到左值引用版本的尾插而报错

		//万能引用
		//在类模板list中在实现一个模板参数不同的函数模板，
		//这样也就能保证了只有当我们调用插入函数时才能根据插入数据的类型进行实例化，进而对模板参数X进行类型推导
		//这样也就将引用折叠和完美转发应用到list中了，不管传的是左值还是右值都只需要这一个函数模板即可
		template<class X>
		void push_back(X&& x)
		{
			insert(end(), forward<X>(x));
		}

		////左值引用版本的插入
		//iterator insert(iterator pos, const T& x)
		//{
		//	Node* cur = pos._node;
		//	Node* newnode = new Node(x);
		//	Node* prev = cur->_prev;
		//	// prev newnode cur
		//	prev->_next = newnode;
		//	newnode->_prev = prev;
		//	newnode->_next = cur;
		//	cur->_prev = newnode;
		//	return iterator(newnode);
		//}

		////右值引用版本的插入
		//iterator insert(iterator pos, T && x)
		//{
		//	Node* cur = pos._node;
		//	Node* newnode = new Node(forward<T>(x));
		//	Node* prev = cur->_prev;
		//	// prev newnode cur
		//	prev->_next = newnode;
		//	newnode->_prev = prev;
		//	newnode->_next = cur;
		//	cur->_prev = newnode;
		//	return iterator(newnode);
		//}

		//万能引用
		template<class X>
		iterator insert(iterator pos, X&& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(forward<X>(x));
			//由于x自身属性是左值，创建节点时new一个Node，传入的数据也需要通过完美转发保持右值属性
			Node* prev = cur->_prev;
			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}

	private:
		Node* _head;
	};
}
	