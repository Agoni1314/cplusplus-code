//#include<iostream>
//int name = 12;
//namespace zhangsan
//{
	/*int age = 20;
	int height = 180;
	int weight = 100;*/
//}
//namespace lisi
//{
	//int age = 22;
	//int height = 150;
	//int weight = 90;
//}
//int main()
//{
//	//int a = ::name;
//	//std::cout << a <<std:: endl;//要么声明std
//	//std::cout << zhangsan::age << std::endl;
//	/*using namespace lisi;
//	std::cout << age << std::endl << height << std::endl << weight << std::endl;*/
//	std::cout <<"zhansgan age:" << zhangsan::age << std::endl;
//	std::cout << "zhangsan height:" << zhangsan::height << std::endl;
//	std::cout << "zhangsan weight:" << zhangsan::weight << std::endl;
//	std::cout << "lisi age:" << lisi::age << std::endl;
//	std::cout << "lisi height:" << lisi::height << std::endl;
//	std::cout << "lisi weight:" << lisi::weight << std::endl;
//	int totle = zhangsan::height + lisi::height;
//	std::cout <<"height totle:" << totle << std::endl;
//	return 0;
//}

//namespace嵌套
//#include<iostream>
//namespace message
//{
//	namespace zhangsan
//	{
//		int age = 20;
//		int height = 180;
//		int weight = 100;
//		namespace sorce
//		{
//			double chinese = 76.3;
//			double math = 89.2;
//			double english = 75.8;
//		}
//	}
//	namespace lisi
//	{
//		int age = 22;
//		int height = 150;
//		int weight = 90;
//		namespace sorce
//		{
//			double chinese = 91.3;
//			double math = 73.2;
//			double english = 61.8;
//		}
//	}
//}
//int main()
//{
//	using namespace std;
//	/*std::cout <<message::zhangsan::age << std::endl;
//	std::cout << message::lisi::age << std::endl;
//	int totle = message::zhangsan::height + message::lisi::height;
//	std::cout << totle << std::endl;*/
//	std::cout << message::zhangsan::sorce::chinese << std::endl;
//	std::cout << message::lisi::sorce::chinese << std::endl;
//	double totle = message::zhangsan::sorce::chinese + message::lisi::sorce::chinese;
//	cout << totle << endl;
//	return 0;
//}

//#include<iostream>
//int main()
//{
//	using namespace std;
//	//int age =0;
//	//cin >> age;//cin会自动识别空格，遇到空格就结束
//	//cout <<"\n" << age;
//	/*int a, b, c;
//	cin >> a;
//	cin>> b >> c;*/
//	//int totle = a + b + c;
//	//cout << totle << endl;
//	//cout <<a<<endl<< b << " " << c << endl;
//	/*int f, s, g;
//	cin >> f >> s >> g;
//	cout << f <<" " << endl << s << endl << g << endl;*/
//	return 0;
//}

#include<iostream>
void func1(int a = 10, int b = 20,int c=30)
{
	std::cout << a << std::endl<<b<<std::endl<<c<<std::endl;
}
void func2(int e, int b = 20, int c = 30)
{
	std::cout << e << std::endl << b << std::endl << c << std::endl;
}
int main()
{
	func1();
	func1(100);
	func1(200, 300);
	func1(400, 500, 600);
	//func2();
	func2(100);
	func2(200, 300);
	func2(400, 500, 600);
	return 0;
}