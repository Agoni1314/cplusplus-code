#pragma once
#include<iostream>
using namespace std;
namespace key
{
	template<class K>
	struct BSTNode
	{
		K _key;
		BSTNode<K>* _left;
		BSTNode<K>* _right;
		BSTNode(const K& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};
	// Binary Search Tree
	template<class K>
	class BSTree
	{
		//typedef BSTNode<K> Node;
		using Node = BSTNode<K>;//效果相同
	public:
		//强制生成构造
		BSTree() = default;
		BSTree(const BSTree& t)
		{
			_root = copy(t._root);
		}
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}
		BSTree& operator=(BSTree tmp)
		{
			swap(_root, tmp._root);
			return *this;
		}
		bool insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
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
					return false;
				}
			}
			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;

		}
		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool erase(const K& key)
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
					//删除
					//左为空
					if (cur->_left == nullptr)
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
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						//右为空
						if (cur == _root)
						{
							_root = cur->_left;
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
						}
						delete cur;
					}
					else
					{
						//左右都不为空
						Node* replaceparent = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replaceparent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;
						if (replaceparent->_left == replace)
							replaceparent->_left = replace->_right;
						else
							replaceparent->_right = replace->_right;
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
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		Node* _root = nullptr;
	};
}
namespace key_value
{
	template<class K,class V>
	struct BSTNode
	{
		K _key;
		V _value;
		BSTNode<K,V>* _left;
		BSTNode<K,V>* _right;
		BSTNode(const K& key, const V& value)
			:_key(key)
			,_value(value)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};
	// Binary Search Tree
	template<class K,class V>
	class BSTree
	{
		//typedef BSTNode<K> Node;
		using Node = BSTNode<K,V>;//效果相同
	public:
		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
		Node* copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* newRoot = new Node(root->_key, root->_value);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);
			return newRoot;
		}

		bool insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,value);
				return true;
			}
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
					return false;
				}
			}
			cur = new Node(key,value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;

		}
		
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
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
		bool erase(const K& key)
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
					//删除
					//左为空
					if (cur->_left == nullptr)
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
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						//右为空
						if (cur == _root)
						{
							_root = cur->_left;
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
						}
						delete cur;
					}
					else
					{
						//左右都不为空
						Node* replaceparent = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replaceparent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;
						if (replaceparent->_left == replace)
							replaceparent->_left = replace->_right;
						else
							replaceparent->_right = replace->_right;
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
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
		Node* _root = nullptr;
	};
}