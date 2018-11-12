/*
函数模板不允许自动类型转化
普通函数能够进行自动类型转化
*/

/*
1函数模板可以像普通函数一样被重载
2编译器优先考虑普通函数
3如何函数模板可以产生一个更好的匹配，那么选择模板
4可以通过空模板实参列表的语法限定编译器只通过模板匹配
*/
#include "iostream"
using namespace std;
//普通函数
int Max(int a, int b){
	cout << "int Max(int a, int b)" << endl;
	return a > b ? a : b;
}
//两个参数的函数模板
template<typename T>
T Max(T a, T b){
	cout << "T Max(T a T b)" << endl;
	return a > b ? a : b;
}
//三个参数的函数模板
template<typename T>
T Max(T a, T b, T c){
	cout << "T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);
}
void main5(){
	int a = 1;
	int b = 2;
	cout << Max(a, b) << endl; //优先选择普通函数
	cout << Max<>(a, b) << endl;//若显示使用函数模板，使用<>
	cout << Max(3.0, 4.0) << endl;//如果函数模板产生更好的匹配，使用函数模板
	cout << Max(5.0, 6.0, 7.0) << endl;//重载
	cout << Max('a', 100) << endl;//调用普通函数，可以进行隐式转化
	return;
}
/*

函数模板机制结论
编译器并不是把函数模板处理成能够处理任意类的函数
编译器从函数模板通过具体类型产生不同的函数
编译器会对函数模板进行两次编译
在声明的地方对模板代码本身进行编译；在调用的地方对参数替换后的代码进行编译。
*/


