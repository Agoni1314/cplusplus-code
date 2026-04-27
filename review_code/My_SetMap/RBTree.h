#pragma once
#include<utility>
using namespace std;
enum Color
{
	RED,
	BLACK
};
template <class T>
class RBTreeNode
{
public:
		T _data;
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		Color _col;//枚举类型
		RBTreeNode(const T& data)
		
			:_data(data)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			{}
		
};
	template<class T, class Ref, class Ptr>
	struct RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef RBTreeIterator<T,Ref,Ptr> Self;
		Node* _node;
		Node* _root;
		RBTreeIterator(Node* node,Node* root)
		:_node(node)
		,_root(root)
		{ }
		Self operator++()
		{
			if (_node->_right)
			{
				Node* min = _node->_right;
				while (min->_left)
				{
					min = min->_left;
				}
				_node = min;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent&&cur == parent->_right)
				{
					cur = parent;
					parent = cur->_parent;
				}
				_node = parent; 
			}
			return *this;
		}
		Self& operator--()
		{
			if (_node == nullptr) // end()
			{
				// --end()，特殊处理，走到中序最后一个结点，整棵树的最右结点​
				Node* rightMost = _root;
				while (rightMost && rightMost->_right)
				{
					rightMost = rightMost->_right;
				}
				_node = rightMost;
			}
			else if (_node->_left)
			{
				// 左子树不为空，中序左子树最后一个​
				Node* rightMost = _node->_left;
				while (rightMost->_right)
				{
					rightMost = rightMost->_right;
				}
				_node = rightMost;
			}
			else
			{
				// 孩子是父亲右的那个祖先​
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && cur == parent->_left)
				{
					cur = parent;
					parent = cur->_parent;
				}
				_node = parent;
			}
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
		bool operator!= (const Self& s) const
		{
			return _node != s._node;
		}
		bool operator== (const Self& s) const
		{
			return _node == s._node;
		}
	};

	
	template<class K, class T,class KeyofT>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		typedef RBTreeIterator<T, T&, T*> iterator;
		typedef RBTreeIterator<T, const T&, const T*> Constiterator;
		iterator begin()
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}
			return iterator(cur,_root);
		}
		iterator end()
		{
			return iterator(nullptr,_root);
		}
		Constiterator begin()const
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}
			return Constiterator(cur, _root);
		}
		Constiterator end()const
		{
			return Constiterator(nullptr, _root);
		}
		bool Insert(const T& data)
		{
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = BLACK;
				return true;
			}
			KeyofT kot;
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (kot(cur->_data) < kot(data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(cur->_data) > kot(data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(data);
			cur->_col = RED;
			if (kot(parent->_data) < kot(data))
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			// 链接父亲
			cur->_parent = parent;
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				//      g
				//	p       u
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					if (uncle && uncle->_col == RED)
					{
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						//     g
						//   p    u
						// c
						if (cur == parent->_left)
						{
							RotateR(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//      g
							//	p       u
							//	  c
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
				else
				{
					//      g
					//	 u     p
					Node* uncle = grandfather->_left;
					if (uncle && uncle->_col == RED)
					{
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						cur = grandfather;
						parent =cur->_parent;
					}
					else
					{
						//      g
						//	 u     p
						//            c
						if (cur == parent->_right)
						{
							RotateL(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//      g
							//	u      p
							//		 c
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
			}
			_root->_col = BLACK;
		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			Node* pParent = parent->_parent;

			subL->_right = parent;
			parent->_parent = subL;

			if (parent == _root)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (pParent->_left == parent)
				{
					pParent->_left = subL;
				}
				else
				{
					pParent->_right = subL;
				}

				subL->_parent = pParent;
			}
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			Node* parentParent = parent->_parent;
			subR->_left = parent;
			parent->_parent = subR;
			if (parentParent == nullptr)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (parent == parentParent->_left)
				{
					parentParent->_left = subR;
				}
				else
				{
					parentParent->_right = subR;
				}
				subR->_parent = parentParent;
			}
		}
		Node* Find(const K& key)
		{
			Node* cur = _root;
				while (cur)
				{
					if (cur->_kv.first < key)
					{
						cur = cur->_right;
					}
					else if (cur->_kv.first > key)
					{
						cur = cur->_left;
					}
					else
					{
						return cur;
					}
				}
			return nullptr;
		}
		
		private:
			Node* _root = nullptr;
			void _InOrder(Node* root)
			{
				if (root == nullptr)
				{
					return;
				}

				_InOrder(root->_left);
				//cout << root->_kv.first << ":" << root->_kv.second << endl;
				_InOrder(root->_right);
			}	
	};
