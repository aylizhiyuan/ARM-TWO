#include <iostream>
using namespace std;
// template告诉 C++编译器，我要开始泛型编程了，看到T，不要报错
template <typename T>
void myswap(T &a, T &b){
	T c = 0;
	c = a;
	a = b;
	b = c;
	cout << "hello....我是模板函数 欢迎call我" << endl;
}
void myswap(int a, char c){
	cout << "a:" << a << "c:" << c << endl;
	cout << "我是普通函数，欢迎来访" << endl;
}
void main4(){
	int a = 10;
	char c = 'z';
	myswap(a, c);
	myswap(c, a);//这里调用的就是普通函数
	myswap(a, a);//函数模板函数的调用，严格按照类型进行自动转化
	cout << "hello" << endl;
	return;
}

