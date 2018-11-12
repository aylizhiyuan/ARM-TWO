#include <iostream>
using namespace std;
class Complex {
public:
	int a;
	int b;
	Complex(int a = 0, int b = 0){
		this->a = a;
		this->b = b;
	}
	void printCom(){
		cout << a << "+" << b << "i" << endl;
	}
};
//定义了全局函数
Complex myAdd(Complex &c1, Complex &c2){
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
//函数名 升级
Complex operator+(Complex &c1, Complex &c2){
	cout << "12345上山打老虎" << endl;
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
void main1(){
	int a = 0;
	int b = 0;
	int c;
	c = a + b;
	Complex c1(1, 2), c2(3, 4);
	Complex c3;
	c3 = c1 + c2;
	//c1-- ;
	//--c1;

	//C++编译器应该给我们程序员提供一种机制...
	//让自定义数据类型有机会进行运算符操作=====>运算符重载机制

	//总结：运算符重载的本质 是 函数调用

	cout << "hello...." << endl;
	return;
	


}

