//所谓的函数模板，实际上是建立一个通用函数,其函数类型和形参类型不具体制定，用一个虚拟的类型来代表。这个通用的函数就成为函数模板。
//函数模板的定义形式 
//				template <类型形式参数表>
//						类型 函数名(形式参数表){
//									语句序列
//						}
#include <iostream>
using namespace std;
//函数模板的定义部分
template <typename T>
//函数模板的声明部分
void myswap(T &a, T &b){
	T c = 0;
	c = a;
	a = b;
	b = c;
	cout << "hello ...我是模板函数,欢迎call我" << endl;
}
int main1(){
	{
		int x = 10;
		int y = 20;
		myswap<int>(x, y);//函数模板 显示类型 调用
		printf("x:%d,y:%d\n", x, y);
	}
	{
		char a = 'a';
		char b = 'b';
		myswap<char>(a, b);
		printf("x:%c,y:%c\n", a, b);
	}
	return 0;
}
