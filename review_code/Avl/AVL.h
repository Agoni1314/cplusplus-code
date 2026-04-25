#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	AVLTreeNode(const pair<K, V>& kv)//每一个节点里面都是键值对
		:_kv(kv)
		,_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_bf(0)
	{ }
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V>& ky)
	{
		if (_root == nullptr)
		{
			_root = new Node(ky);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < ky.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > ky.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(ky);
		if (parent->_kv.first < ky.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				 if (parent->_bf == -2 && cur->_bf == -1)
				{
					 RotatR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					 RotatL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					 RptatLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					 RotatRL(parent);
				}
				else
				 {
					 assert(false);
				 }
				 break;
			}
			/*else
			{
				assert(false);
			}*/
		}
		return true;

	}
	void RotatL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		Node* pParent = parent->_parent;
		if(subRL)
			subRL->_parent = parent;
		
		subR->_left = parent;
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			 if (pParent->_left == parent)
			{
				pParent->_left = subR;
			}
			else
			{
				pParent->_right = subR;
			}
		}
		subR->_bf =0;
		parent->_bf = 0;
	}
	void RotatR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		Node* pParent = parent->_parent;
		if (subLR)
			subLR->_parent = parent;
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
		}
		subL->_bf = 0;
		parent->_bf = 0;
	}
	void RptatLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotatL(parent->_left);
		RotatR(parent);
		if (bf == -1)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		if (bf == 1)
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		if (bf == 0)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
	}
	void RotatRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotatR(parent->_right);
		RotatL(parent);
		if (bf == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			parent->_bf = 0;
		}
		if (bf == 1)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = -1;
		}
		if (bf == 0)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
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