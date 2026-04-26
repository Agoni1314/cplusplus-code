#pragma once
#include<utility>
using namespace std;
enum Color
{
	RED,
	BLACK
};
template <class K,class V>
class RBTreeNode
{
public:
		pair<K, V> _kv;
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		Color _col;//枚举类型
		RBTreeNode(const pair<K, V>& kv)
		
			:_kv(kv)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			{}
		
};
	template<class K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(kv);
			cur->_col = RED;
			if (parent->_kv.first < kv.first)
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
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
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
				cout << root->_kv.first << ":" << root->_kv.second << endl;
				_InOrder(root->_right);
			}
	};
