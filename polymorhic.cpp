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
class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};
class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	p->func();
	return 0;
}