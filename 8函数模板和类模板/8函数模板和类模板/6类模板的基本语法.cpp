#include <iostream>
using namespace std;

//模板类
template <class T>
class A {
public:
	A(T a){
		this->a = a;
	}
	void printA(){
		cout << "a:" << a << endl;
	}
protected:
	T a;
};
//模板类派生普通类
//模板类派生时，需要具体化模板类，编译器需要知道父类的数据类型具体是什么样子的
//要知道父类所占内存大小是多少 只有数据类型固定下来，才知道如何分配内存
class B :public A<int>{
public:
	B(int a = 10, int b = 20) :A<int>(a){
		this->b = b;
	}
	void printB(){
		cout << "a:" << a << "b:" << b << endl;
	}
private:
	int b;
};

//从模板类 派生 模板类
template<typename T>
class C :public A<T> {
public:
	C(T c, T a) :A<T>(a){
		this->c = c;
	}
	void printC(){
		cout << "c:" << c << endl;
	}
protected:
	T c;
};
void main6(){
	C<int>c1(1, 2);
	c1.printC();
	return;
}
void main62(){
	B b1(1, 2);
	b1.printB();
	return;
}

//类模板做函数参数
//参数，编译器 要求具体的类 所以要A <int> &a
void UseA(A<int> &a){
	a.printA();
}
void main63(){
	A<int>a1(11), a2(20), a3(30);
	UseA(a1);
	UseA(a2);
	UseA(a3);
	cout << "hello..." << endl;
	return;
}