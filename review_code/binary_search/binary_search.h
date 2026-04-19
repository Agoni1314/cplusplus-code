#pragma once
#include<iostream>
using namespace std;
template<class T>
class BSNode
{
public:
	T _key;
	BSNode<T>* _left;
	BSNode<T>* _right;
	BSNode(const T& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
		{}
};
template<class T>
class BSTree
{
	using Node = BSNode<T>;
public:
	bool insert(const T& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//找空位置
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key > key)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}
	bool Find(const T& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
	}
	bool erase(const T& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//左为空
				if (parent->_left == nullptr)
				{
					if (cur == _root)
					{
						cur = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
						delete cur;
					}
				}
				//右为空
				else if (parent->_right == _root)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
					}
				}
				else
				{
					//左右都不为空
					Node* replaceparent = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						replaceparent = replace;
						replace->_left;
					}
					cur->_left = replace->_left;
					if (replaceparent->_left==nullptr)
					{
						replaceparent->_left = replace->_right;
					}
					else
					{
						replaceparent->_right = replace->_left;
					}
					delete replace;
				}
				return true;
			}
		}
		return false;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
			return;
		_InOrder(_root->_left);
		cout << _root->_key << endl;
		_InOrder(_root->_right);
	}
	Node* _root = nullptr;
};
