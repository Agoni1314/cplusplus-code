#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Goods
{
	string _name; // 名字?
	double _price; // 价格?
	int _evaluate; // 评价?
	// ...
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{
	}
};
struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};
struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};
int main()
{
	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3
	}, { "菠萝", 1.5, 4 } };
	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中?
	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了?
	sort(v.begin(), v.end(), ComparePriceLess());
	sort(v.begin(), v.end(), ComparePriceGreater());
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) 
		{
		return g1._price < g2._price;
		});
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
		return g1._price > g2._price;
		});
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
		return g1._evaluate < g2._evaluate;
		});
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) 
		{
		return g1._evaluate > g2._evaluate;
		});
	return 0;
}