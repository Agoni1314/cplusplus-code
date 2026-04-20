#pragma once
#include<iostream>
using namespace std;
//namespace key
//{
//	template<class T>
//	class BSNode
//	{
//	public:
//		T _key;
//		BSNode<T>* _left;
//		BSNode<T>* _right;
//		BSNode(const T& key)
//			:_key(key)
//			, _left(nullptr)
//			, _right(nullptr)
//		{
//		}
//	};
//	template<class T>
//	class BSTree
//	{
//		using Node = BSNode<T>;
//	public:
//		BSTree() = default;
//		BSTree(const BSTree& t)
//		{
//			_root = copy(t._root);
//		}
//		~BSTree()
//		{
//			delete _root;
//			_root = nullptr;
//		}
//		bool insert(const T& key)
//		{
//			if (_root == nullptr)
//			{
//				_root = new Node(key);
//				return true;
//			}
//			Node* parent = nullptr;
//			Node* cur = _root;
//			//找空位置
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return false;
//				}
//			}
//			cur = new Node(key);
//			if (parent->_key > key)
//				parent->_left = cur;
//			else
//				parent->_right = cur;
//			return true;
//		}
//		bool Find(const T& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return true;
//				}
//			}
//		}
//		bool erase(const T& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					//左为空
//					if (parent->_left == nullptr)
//					{
//						if (cur == _root)
//						{
//							cur = cur->_right;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_right;
//							}
//							delete cur;
//						}
//					}
//					//右为空
//					else if (parent->_right == _root)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_right;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_left;
//							}
//							delete cur;
//						}
//					}
//					else
//					{
//						//左右都不为空
//						Node* replaceparent = cur;
//						Node* replace = cur->_right;
//						while (replace->_left)
//						{
//							replaceparent = replace;
//							replace->_left;
//						}
//						cur->_left = replace->_left;
//						if (replaceparent->_left == nullptr)
//						{
//							replaceparent->_left = replace->_right;
//						}
//						else
//						{
//							replaceparent->_right = replace->_left;
//						}
//						delete replace;
//					}
//					return true;
//				}
//			}
//			return false;
//		}
//		void InOrder()
//		{
//			_InOrder(_root);
//			cout << endl;
//		}
//	private:
//		void _InOrder(Node* _root)
//		{
//			if (_root == nullptr)
//				return;
//			_InOrder(_root->_left);
//			cout << _root->_key << endl;
//			_InOrder(_root->_right);
//		}
//		Node* _root = nullptr;
//	};
//}

//namespace key_value
//{
//template<class K,class V>
//class BSTNode
//{
//public:
//	K _key;
//	V _value;
//	BSTNode<K,V>* _left;
//	BSTNode<K,V>* _right;
//	BSTNode(const K& key, const V& value)
//		:_key(key)
//		,_value(value)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//	template<class K, class V>
//	class BSTree
//	{
//		using Node = BSTNode<K, V>;
//	public:
//		BSTree() = delete;
//		void Destroy(Node* root)
//		{
//			if (root == nullptr)
//				return;
//			Destroy(root->_left);
//			Destroy(root->_right);
//			delete root;
//		}
//		Node* copy(Node* root)
//		{
//			if (root == nullptr)
//				return nullptr;
//			Node* newRoot = new Node(root->_key, root->_value);
//			newRoot->_left = copy(root->_left);
//			newRoot->_right = copy(root->_right);
//			return newRoot;
//		}
//		bool insert(const K& key, const V& value)
//		{
//			if (_root == nullptr)
//			{
//				_root = new Node(key, value);
//				return true;
//			}
//			Node* parent = nullptr;
//			Node* cur = _root;
//			//找空位置
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return false;
//				}
//			}
//			cur = new Node(key, value);
//			if (parent->_key > key)
//				parent->_left = cur;
//			else
//				parent->_right = cur;
//			return true;
//		}
//		bool Find(const K& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return true;
//				}
//			}
//		}
//		bool erase(const K& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					//删除
//					//左为空
//					if (cur->_left == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_right;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_right;
//							}
//						}
//						delete cur;
//					}
//					else if (cur->_right == nullptr)
//					{
//						//右为空
//						if (cur == _root)
//						{
//							_root = cur->_left;
//						}
//						else
//						{
//							if (parent->_left == cur)
//							{
//								parent->_left = cur->_left;
//							}
//							else
//							{
//								parent->_right = cur->_left;
//							}
//						}
//						delete cur;
//					}
//					else
//					{
//						//左右都不为空
//						Node* replaceparent = cur;
//						Node* replace = cur->_right;
//						while (replace->_left)
//						{
//							replaceparent = replace;
//							replace = replace->_left;
//						}
//						cur->_key = replace->_key;
//						if (replaceparent->_left == replace)
//							replaceparent->_left = replace->_right;
//						else
//							replaceparent->_right = replace->_left;
//						delete replace;
//					}
//					return true;
//				}
//			}
//			return false;
//		}
//		void InOrder()
//		{
//			_InOrder(_root);
//			cout << endl;
//		}
//	private:
//		void _InOrder(Node* _root)
//		{
//			if (_root == nullptr)
//				return;
//			_InOrder(_root->_left);
//			cout << _root->_key << endl;
//			_InOrder(_root->_right);
//		}
//		Node* _root = nullptr;
//	};
//
//};

namespace key_value
{
	template<class K, class V>
	struct BSTNode
	{
		K _key;
		V _value;
		BSTNode<K, V>* _left;
		BSTNode<K, V>* _right;
		BSTNode(const K& key, const V& value)
			:_key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};
	// Binary Search Tree
	template<class K, class V>
	class BSTree
	{
		//typedef BSTNode<K> Node;
		using Node = BSTNode<K, V>;//效果相同
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
				_root = new Node(key, value);
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
			cur = new Node(key, value);
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