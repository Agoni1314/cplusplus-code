#define  _CRT_SECURE_NO_WARNINGS
//cpp兼容c
//#include<stdio.h>
//int main()
//{
//	printf("Hello World!\n");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello World!" << endl;
//	return 0;
//}

//#include<stdio.h>
////命名冲突,stdlib库中有rand函数，所以要加域
//#include<stdlib.h>
////域,该域的生命周期是全局变量，不能定义在局部变量中
//namespace std
//{
//	int rand = 10;
//}
//int a = 0;
//int main()
//{
//	printf("%p\n", rand);
//	printf("%d\n", std::rand);
//	int a = 1;
//	printf("%d\n", a);
//	//域作用限定符
//	printf("%d\n", ::a);
//	return 0;
//}

//#include<stdio.h>
//namespace boxing
//{
//	int a = 10;
//	int b = 20;
//}
////只展开某一个
//using boxing::a;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", boxing::b);
//	return 0;
//}

//#include<iostream>
//using namespace std;
////cout是全局库里面的对象，定义在iostream中，而cout有包在std里面
//int main()
//{
//	int a = 1234;
//	int b = -1234;
//	char c = 'q';
//	double e = 2.4;
//	//"<<"是二元操作符，只能有两个操作数
//	//输出
//	std::cout << a << std::endl;
//	cout << b << endl;
//	cout << a << " " << c << endl;
//	cout << a << " " << c << "\n";
//	std::cout << a << " "<<e << " " << endl;
//	double q = 1.23456789;//四舍五入
//	cout << q<<"\n";
//	//输入
//	cin >>a>> b >> c;
//	cout << &a << "\n" << b << "\n" << c;
//	return 0;
//}

//#include<iostream>
//using namespace std;
////全缺省
//void func1(int a=1,int b=2,int c=3)
//{
//	cout << a << " " << b << " " << c<<endl;
//}
////半缺省
//void func2(int a ,int b=400,int c=300)
//{
//	cout << a << " " << b << " " << c<<endl;
//}
//int main()
//{
//	//func1();
//	func1(300);//没有传递实参就使用缺省参数，传递的实参从左往右
//	func2(10,20);//半缺省从右往左给默认值，不能跳跃
//	return 0;
//}

//函数重载
//#include<iostream>
//using namespace std;
//int Add(int a, int b)
//{
//	return a + b;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//void func3()
//{
//	cout << "func3:" << endl;
//}
//void func4(int a)
//{
//	cout << "func4:"<< a << endl;
//}
//
//int main()
//{
//	int ret1=Add(1, 2);
//	double ret2=Add(1.1, 2.2);
//	cout << ret1 << endl;
//	cout << ret2 << endl;
//	func3();
//	func4(100);
//	return 0;
//}

//引用
#include<iostream>
void Swap(int& rk, int& rx)
{
	int tmp = rk;
	rk = rx;
	rx = tmp;
	
}
using namespace std;
int main()
{
	int a = 0;
	//引用：b和c是a的别名
	int& b = a;
	int& c = a;
	int& d = b;
	++d;
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;

	int k = 0;
	int x = 1;
	Swap(k, x);
	cout << k <<" " << x << endl;
	cout << x <<" " << k << endl;
	return 0;
}