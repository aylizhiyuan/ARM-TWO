#include "iostream" //包含c++的头文件
using namespace std;//使用命名空间std标准的命名空间(在这个命令空间里定义了很多标准定义)
//------------------简单的hello 程序-------------------------------
void main1(){
	//cout标准输出 ，<<左移操作符，在C++中，操作符重载
	cout  <<  "hello...." << endl;//endl是回车换行的意思
}
//---------------------计算圆的周长和面积-----------------------------
//1.用结构化的方法求解
void main2(){
	double r, girth, area;
	const double PI = 3.1415;
	cout << "please input radius:\n";
	cin >> r;//输入
	girth = 2 * PI * r;
	area = PI * r * r;
	cout << "radius=" << r << endl;
	cout << "girth=" << girth << endl;
	cout << "area=" << area << endl;
}
//2.用面对对象的方法求解
class Circle
{
	double radius; //成员变量
	public: //类的访问控制
	void Set_Radius(double r) { radius = r; } //成员函数
	double Get_Radius()  { return  radius; } //通过成员函数设置成员变量
	double Get_Girth()     { return  2 * 3.14f * radius; } //通过成员函数获取成员变量
	double Get_Area()     { return  3.14f * radius * radius; }
};
void main3(){
	Circle A, B; //用类定义对象
	A.Set_Radius(6.23); //类的调用
	cout << "A.Radius = " << A.Get_Radius() << endl;
	cout << "A.Girth = " << A.Get_Girth() << endl;
	cout << "A.Area = " << A.Get_Area() << endl;
	B.Set_Radius(10.5);
	cout << "B.radius = " << B.Get_Radius() << endl;
	cout << "B.Girth=" << B.Get_Girth() << endl;
	cout << "B.Area = " << B.Get_Area() << endl;
}
//------------------- c++命名空间-----------------------------
namespace NameSpaceA{
	int a = 0;
}
namespace NameSpaceB {
	int a = 1;
	namespace NameSpaceC{
		struct Teacher {
			char name[10];
			int age;
		};
	}
}
void main4(){
	//引入命名空间，控制变量的作用域,c++标准程序库中的所有标识符都被定义于一个名为std的命名空间，说白了，就是将全局作用域分成了几个不同的部分，不同命名空间中的函数和变量可以同名而不会发生冲突
	using namespace NameSpaceA;
	using namespace NameSpaceB::NameSpaceC;
	printf("a=%d\n", a);
	printf("a=%d\n", NameSpaceB::a);//使用多个命名空间中的同名变量的时候，通常是需要指明哪个命名空间的
	NameSpaceB::NameSpaceC::Teacher t1 = { "aaa", 3 };
	printf("t1.name=%s\n", t1.name);
	printf("t1.age=%d\n", t1.age);
	system("pause");
	return;
}
//-----------------------register函数检测增强----------------
void main5(){
	register int a = 0;//在C中是无法获取到寄存器变量的地址的，C++可以
	printf("&a=%x\n", &a);
	system("pause");
	return;
}
//----------------------struct类型加强-----------------------
struct Student {
	char name[100];
	int age;
};//C++中的struct是一个新类型的定义声明
void main6(){
	Student s1 = { "wang", 1 };
	Student s2 = { "wang2", 2 };
}
//----------------------C++更加强调类型--------------------
//f(i){
//	printf("i=%d\n", i);
//}
//g(){
//	return 5;
//}
void main7(){
	//f(10);
	//printf("g()=%d\n", g(1, 2, 3, 4, 5));
	//getchar();
	//return;
}
//Tips:int f()在C语言中，表示返回值为int，接受任意参数的函数,int f(void)表示返回值为int的无参函数，但是，在C++中，int f()和int f(void)都表示返回值为int的无参函数

//----------------------boolean------------------------------
void main8(){
	//c++在C语言基础上增加了bool类型,占一个字节
	int a;
	bool b = true;
	printf("b = %d, sizeof(b) = %d\n", b, sizeof(b));

	b = 4;
	a = b;
	printf("a = %d, b = %d\n", a, b);

	b = -4;
	a = b;
	printf("a = %d, b = %d\n", a, b);

	a = 10;
	b = a;
	printf("a = %d, b = %d\n", a, b);

	b = 0;
	printf("b = %d\n", b);

	system("pause");
	return;
}
//----------------------三目运算--------------------------------
void main9(){
	int a = 10;
	int b = 20;
	//返回一个最小数 并且给最小数赋值成3
	//三目运算符是一个表达式 ，表达式不可能做左值
	(a < b ? a : b) = 30;
	printf("a = %d, b = %d\n", a, b);
	system("pause");
}
//----------------------const----------------------------------
void main10(){
	//const int a = 10; //代表一个常量
	//int const b = 20;//代表一个常量
	//int c = 30;
	//const int *c = &a; //代表你不能通过*c修改某个内存地址的值
	//int * const d = &c;//代表你无法改变*d的指向
	//const int * const e = &a;//指针和它所指向的内存空间，都不能被修改

	const int test = 10;
	int *p = (int*)&test;
	printf("a====>%d\n", test);
	*p = 11;
	printf("a====>%d\n", test);
}

//------------------------引用----------------------------
void main11(){
	//变量名实质上是一段连续内存空间的别名，能不能取好几个别名呢？
	//引用可以看做是一个已定义变量的别名
	//引用的 语法：Type& name = var
	int a = 10; //c编译器分配4个字节内存。。。a内存空间的别名
	int &b = a;  //b就是a的别名。。。
	a = 11; //直接赋值
	{
		int *p = &a;
		*p = 12;
		printf("a %d \n", a);
	}
	b = 14;
	printf("a:%d b:%d", a, b);
	system("pause");

}
//---------------------引用做函数参数--------------------------
struct Teacher {
	char name[64];
	int age;
}; 
void printfT(Teacher *pT){
	cout << pT->age << endl;
}
void printfT2(Teacher &pT){
	cout << pT.age << endl;
	pT.age = 33;
}
void printfT3(Teacher pT){
	cout << pT.age << endl;
	pT.age = 45;
}
void main12(){
	Teacher t1;
	t1.age = 35;
	printfT(&t1);
	printfT2(t1); //pT是t1的别名
	printf("t1.age:%d \n", t1.age); //33
	printfT3(t1);// pT是形参 ,t1 copy一份数据 给pT     //---> pT = t1
	printf("t1.age:%d \n", t1.age); //33
	cout << "hello..." << endl;
	system("pause");
}
//Tips: Type &name 等同于 Type * const name 常指针
int  main121(){
	//当函数返回值为引用时,若返回栈变量，不能成为其他引用的初始值
	//若返回静态变量或全局变量，可以作为其他引用的初始值
	//1.返回值是基础类型，当引用
	//int a;
	//a = 10;
	//return a;//返回的其实是a的一个副本，并不是a本身.可以作为其他引用的初始值

	//int b;
	//b = 20;
	//return &b; //它返回的是一个局部变量的引用，我感觉不行.

	//static int c = 30;
	//c++;
	//return c; //静态变量的引用我感觉是没有问题的.

	//int *p如果是形参的话
	//int *p;
	//*p = 100;
	//return *p; //可以作为引用
	return 0;
}
int main122(){
	//使用变量初始化const引用
	//const Type& name = var;
	//const 引用让变量拥有只读属性
	int a = 10;
	const int &b = a;
	//int *p = (int *)&b;
	//b = 11; //err
	//*p = 11; //只能用指针来改变了
	cout << "b--->" << a << endl;
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b);
	system("pause");
	return 0;
}
void main123(){
	//普通引用
	int a = 10;
	int &b = a;
	//常量引用 ：让变量引用只读属性
	const int &c = a;
	//常量引用初始化 分为两种
	//1 用变量 初始化 常量引用
	{
		int x = 20;
		const int& y = x;
		printf("y:%d \n", y);
	}
	//2 用常量 初始化 常量引用
	{
		//int &m = 10; //引用是内存空间的别名 字面量10没有内存空间 没有方法做引用
		const int &m = 10;
	}
	cout << "hello..." << endl;
	system("pause");
	return;
}

//---------------------内联函数inline--------------------------
inline int myfunc(int a, int b){
	return a < b ? a : b;
}
#define MYFUNC(a, b) ((a) < (b) ? (a) : (b))  
void main13(){
	int a = 1;
	int b = 3;
	//int c = myfunc(++a, b);  //头疼系统
	int c = MYFUNC(++a, b);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	system("pause");
	return;
}
//Tips:内联函数在编译的时候直接将函数体插入函数调用的地方，内联的限制：1.不能存在任何形式的循环语句；2.不能存在过多的条件判断语句；3.函数体不能过于庞大；4.不能对函数进行取地址操作。内联函数由编译器处理，直接将编译后的函数体插入调用的地方，宏代码片段由预处理器处理，进行简单的文本替换，没有任何编译过程。
//---------------------函数-默认参数---------------------------
void myPrint(int x = 3){
	//1.只有参数列表后边部分的参数才可以提供默认参数值
	//2.一旦在一个函数调用中开始使用默认参数值，那么这个参数后的所有参数都必须使用默认参数值
	printf("x:%d", x);
}
void main14(){
	return ;
}
//---------------------函数占位参数-----------------------------
int func(int a, int b, int){
	return a + b;
}
void main15(){
	//func(1, 2);
	printf("func(1, 2, 3) = %d\n", func(1, 2, 3));
}
//---------------------默认参数和占位参数混搭------------------
int func2(int a, int b, int = 0){
	return a + b;
}
void main16(){
	//如果默认参数和占位参数在一起，都能调用起来
	func2(1, 2);
	func2(1, 2, 3);
	system("pause");
}
//---------------------函数重载-----------------------------------
//用同一个函数名定义不同的函数，当函数名和不同的参数搭配时候函数的意义不同
int func(int x)
{
	return x;
}
int func(int a, int b)
{
	return a + b;
}
int func(const char* s)
{
	return strlen(s);
}
int main()
{
	int c = 0;
	c = func(1);
	printf("c = %d\n", c);
	c = func(1, 2);
	printf("c = %d\n", c);
	c = func("12345");
	printf("c = %d\n", c);
	printf("Press enter to continue ...");
	getchar();
	return 0;
}