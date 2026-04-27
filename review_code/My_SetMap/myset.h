#pragma once
#include"RBTree.h"
namespace boxset
{
	template<class K>
	class set
	{
		struct SetKeyofT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, const K, SetKeyofT>::iterator iterator;
		typedef typename RBTree<K, const K, SetKeyofT>::Constiterator Constiterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		Constiterator begin()const
		{
			return _t.begin();
		}
		Constiterator end()const
		{
			return _t.end();
		}
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, const K, SetKeyofT> _t;
	};
}