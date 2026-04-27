#pragma once
#include"RBTree.h"
namespace boxmap
{
	template<class K, class V >
	class map
	{
		struct MapKeyofT
		{
			const K& operator()(const pair<K,V>& key)
			{
				return key.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::Constiterator Constiterator;
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
		bool insert(const pair<K,V>& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyofT> _t;
	};
}