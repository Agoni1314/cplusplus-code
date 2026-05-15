#include<iostream>
using namespace std;
//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "Student" << endl; }
//};
//void Func(Person* ptr)
//{
//	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//	// 但是跟ptr没关系，而是由ptr指向的对象决定的。
//	ptr->BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person" << endl; }//父类的virtual不能去掉，子类可以
//};
//class Student : public Person {
//public:
//	//virtual void BuyTicket() { cout << "Student" << endl; }
//	 void BuyTicket() { cout << "Student" << endl; }
//};
//void Func(Person& ptr)
//{
//	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//	// 但是跟ptr没关系，而是由ptr指向的对象决定的。
//	ptr.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}


//class Animal
//{
//public:
//	virtual void talk() const
//	{
//	}
//};
//class Dog : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "dog" << std::endl;
//	}
//};
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "cat" << std::endl;
//	}
//};
//void letsHear(const Animal& animal)
//{
//	animal.talk();
//}
//int main()
//{
//	
//	Cat cat;
//	Dog dog;
//	letsHear(cat);
//	letsHear(dog);
//	
//	return 0;
//}

//面试题
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	p->func();
//	return 0;
//}


//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//class B : public A {
//public:
//	virtual~B()
//	{
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}
//protected:
//	int* _p = new int[10];
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//	delete p1;
//	delete p2;
//	return 0;
//}


//class Car {
//public:
//	virtual void Dirve()
//	{
//	}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override 
//	{ 
//		cout << "Benz" << endl;
//	}
//};
//int main()
//{
//
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive()final {}
//	{
//	}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() 
//	{ 
//		cout << "Benz" << endl; 
//	}
//};
//int main()
//{ 
//
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Drive()=0 ;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW" << endl;
//	}
//};
//int main()
//{
//	// 编译报错：error C2259: “Car”: 无法实例化抽象类
//	Car car;
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//	return 0;
//}

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
protected:
	string _name;
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-打折" << endl; }
protected:
	string _id;
};
class Soldier : public Person {
public:
	virtual void BuyTicket() { cout << "买票-优先" << endl; }
protected:
	string _codename;
};
void Func(Person* ptr)
{
	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
	// 但是跟ptr没关系，而是由ptr指向的对象决定的。
	ptr->BuyTicket();
}
int main()
{
	// 其次多态不仅仅发生在派生类对象之间，多个派生类继承基类，重写虚函数后
	// 多态也会发生在多个派生类之间。
	Person ps;
	Student st;
	Soldier sr;
	Func(&ps);
	Func(&st);
	Func(&sr);
	return 0;
}