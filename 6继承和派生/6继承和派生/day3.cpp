#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
//-------------------继承----------------------
class Parent {
public:
	void print(){
		a = 0;
		b = 0;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
	}
	int b;
private:
	int a;
};
class Child :public Parent{
public:
protected:
private:
	int c;
};
void main1(){
	Child c1;
	//c1.c = 1;
	//c1.a = 2;
	c1.b = 3;
	c1.print();
	cout << "hello...." << endl;
	return;
}

//------------单个类的访问控制--------------------
//public修饰的，在类的内部、外部都可以使用
//protected修饰的，在类的内部使用，在继承的子类中可以使用,其他的地方不能
//private修饰的，只能在类的内部使用，不能在类的外部使用
class Parent1{
public:
	int a; //老爹的名称
protected:
	int b;//老爹的银行密码
private:
	int c;//老爹的情人
};
//保护继承
class Child1 :protected Parent1 {
public:
	void useVar(){
		a = 0;
		b = 0;
		//c = 0; //err
	}
};
void main2(){
	Child1 c3;
	//c3.a = 10;  //err
	//c3.b = 155;//err
	//c3.c = 30;//err
	return;
}
//Tips:protected继承方式，public,protected为protected,private依然是private

//私有继承
class Child2 :private Parent1{
public:
	void userVar(){
		a = 0;
		b = 0;
		//c = 0;//err
	}
};
void main3(){
	Child2 c2;
	//c2.a = 10;//err
	//c2.b = 20;//err
	//c2.c = 30;//err
}
//Tips:所有的私有继承的属性最后都会变为private

//公共继承
class Child3 :public Parent1 {
public:
	void userVar(){
		a = 0;
		b = 0;
		//c = 0; //err
	}
};
void main4(){
	Child3 c;
	c.a = 10;
	//c.b = 20;//err
	//c.c = 30;//err
}
//Tips:依然是它自身的访问控制，没有变化


//----------------------类型兼容性----------------
//在需要基类对象的任何地方，都可以使用公有派生类的对象替代。通过公有继承，派生类得到了基类中除构造函数、析构函数之外的所有成员
//子类对象可以当做父类对象来用
//子类对象可以直接赋值给父类对象
//子类对象可以直接初始化父类对象
//父类指针可以直接指向子类对象
//父类引用可以直接引用子类对象
//总结：子类就是特殊的父类 base *p = &child
class Parent2 {
public:
	void printP(){
		cout << "我是爹..." << endl;
	}
	Parent2(){
		cout << "parent2构造函数" << endl;
	}
	Parent2(const Parent &obj){
		cout << "copy构造函数" << endl;
	}
private:
	int a;
};
class Child4 :public Parent2 {
public:
	void printC(){
		cout << "我是儿子" << endl;
	}
private:
	int c;
};

void howToPrint(Parent2 *base){
	base->printP();// 父类的成员函数
}
void howToPrint2(Parent2 &base){
	base.printP();//父类的成员函数
}
void main5(){
	Parent2 p1;
	p1.printP();
	Child4 c4;
	c4.printC();
	c4.printP();

	//赋值兼容性原则
	//1.基类指针指向子类对象 
	Parent2 *p = NULL;
	//p = &c4;//这里貌似不行

	//2.指针做函数参数
	howToPrint(&p1);
	howToPrint(&c4);

	//3.引用作为函数参数
	howToPrint2(p1);//
	howToPrint2(c4);//

	Parent2 p3 = c4; //可以让子类对象初始化父类对象
}
/*
兼容规则中所指的替代包括以下情况：
子类对象可以当作父类对象使用
子类对象可以直接赋值给父类对象
子类对象可以直接初始化父类对象
父类指针可以直接指向子类对象
父类引用可以直接引用子类对象
*/

//------------------继承中的构造和析构--------------------------
//在子类构造函数构造时，需要调用父类构造函数对其继承得来的成员进行初始化
//在子类对象析构时，需要调用父类析构函数对其继承得来的成员进行清理
class Parent3 {
public:
	Parent3(int a, int b){
		this->a = a;
		this->b = b;
		cout << "父类构造函数..." << endl;
	}
	~Parent3(){
		cout << "析构函数..." << endl;
	}
	void printP(int a, int b){
		this->a = a;
		this->b = b;
		cout << "我是爹..." << endl;
	}
private:
	int a;
	int b;
};
class Child5 :public Parent3 {
public:
	Child5(int a, int b, int c) : Parent3(a, b){
		this->c = c;
		cout << "子类的构造函数" << endl;
	}
	~Child5(){
		cout << "子类的析构" << endl;
	}
	void printC(){
		cout << "我是儿子" << endl;
	}
private:
	int c;
};
void playObj(){
	Child5 cc(2,3,4);
}
void main6(){
	playObj();
	cout << "hello....." << endl;
	return;
}

//-------------继承与组合混搭情况下，构造与析构调用原则------------
class Object {
public:
	Object(int a, int b){
		this->a = a;
		this->b = b;
		cout << "object构造函数执行" << "a" << a << "b" << b << endl;
	}
	~Object(){
		cout << "object析构函数\n";
	}
protected:
	int a;
	int b;
};
class Parent4 :public Object {
public:
	Parent4(char *p) :Object(1, 2){
		this->p = p;
		cout << "父类构造函数..." << p << endl;
	}
	~Parent4(){
		cout << "析构函数..." << p << endl;
	}
	void printP(int a, int b){
		cout << "我是爹...." << endl;
	}
protected:
	char *p;
};
class child6 : public Parent4{
public:
	child6(char *p) :Parent4(p), obj1(3, 4), obj2(5, 6){
		this->myp = p;
		cout << "子类的构造函数" << myp << endl;
	}
	~child6(){
		cout << "子类的析构" << myp << endl;
	}
	void printC(){
		cout << "我是儿子" << endl;
	}
protected:
	char *myp;
	Object obj1;
	Object obj2;
};
void objplay(){
	child6 c1("继承测试");
}
void main7(){
	objplay();
	cout << "hello....." << endl;
	return;
}
//Tips:先构造父类，再构造成员变量，最后在构造自己；先析构自己，再析构成员变量，最后析构父类,原则：先构造的后释放

//----------------继承中的同名成员变量处理方法-------------------------
//当子类成员变量与父类成员变量同名时，子类依然从父类继承同名成员，在子类中通过作用域分辨符::进行同名成员区分，在派生类中使用基类的同名成员，显式的使用类名限定符
class A {
public:
	int a;
	int b;
public:
	void get(){
		cout << "b " << b << endl;
	}
	void print(){
		cout << "AAAAA" << endl;
	}
};
class B :public A {
public:
	int b;
	int c;
public :
	void get_child(){
		cout << "b" << b << endl;
	}
	void print(){
		cout << "BBBB" << endl;
	}
};
void main8(){
	B b1;
	b1.print();
	b1.A::print();//打印被隐藏的基类中的print方法
	b1.B::print(); //默认情况
	//成员变量也是同样的情况
}

//--------------------派生类中的static关键字--------------------
//基类定义的静态成员，将被所有的派生类共享,根据静态成员自身的访问特性和派生类的继承方式，在类层次体系中具有不同的访问性质. 派生类中访问静态成员，使用类名::成员
class C {
public:
	C(){
		cout << "C的构造函数" << endl;
	}
public:
	static int a;
	int b;
public:
	void get(){
		cout << "b" << b << endl;
	}
	void print(){
		cout << "CCCCC" << endl;
	}
};
int C::a = 100; //给静态成员赋值

class D :private C {
public:
	int b;
	int c;
public:
	void get_child(){
		cout << "b=" << b << endl;
		cout << a << endl;
	}
	void print(){
		cout << "DDDDD" << endl;
	}
};
void main9(){
	//C ccc;
	//ccc.print();
	D ddd;
	ddd.get_child();
}

//-----------------------多继承---------------------------
class Base1{
public:
	Base1(int b1)
	{
		this->b1 = b1;
	}
	void printB1()
	{
		cout << "b1:" << b1 << endl;
	}
protected:
private:
	int  b1;
};

class Base2{
public:
	Base2(int b2)
	{
		this->b2 = b2;
	}
	void printB2()
	{
		cout << "b2:" << b2 << endl;
	}
protected:
private:
	int  b2;
};

class E : public Base1, public Base2
{
public:
	E(int e1, int e2, int f) : Base1(e1), Base2(e2)
	{
		this->c = c;
	}
	void printC()
	{
		cout << "c:" << c << endl;
	}
protected:
private:
	int c;
};

void main10(){
	E e1(1, 2, 3);
	e1.printC();
	e1.printB1();
	e1.printB2();
	cout << "hello..." << endl;
	return;
}

//---------------------------虚继承---------------------------
//如果一个派生类从多个基类派生，而这些基类又有一个共同的基类，则在对该基类中声明的名字进行访问的时候，会有二义性
// class B{public:int b}
// class B1:public B{private:int b1;}
// class B2:public B{private:int b2;}
// class C:pubilc B1,public B2 {public:int f();private:int d;}
// c.B1::b c.B2::b ,但是c.B::b 从哪儿继承？

//要使这个公共基类在派生类中只产生一个子对象，必须对这个基类声明为虚继承，使这个基类成为虚基类 ,使用关键词virtual
class F{
public:
	F()
	{
		cout << "F构造函数执行\n";
	}
	int f;
protected:
private:
};

class F1 : virtual public F //12
{
public:
	int f1;
};

class F2 : public F //8
{
public:
	int f2;
};

class G : public F1, public F2
{
public:
	int g;
};
void main(){
	cout << sizeof(F) << endl; //4
	cout << sizeof(F1) << endl; //12 //加上virtual以后 , C++编译器会在给变量偷偷增加属性
	cout << sizeof(F2) << endl;  //8
	//cout<<sizeof(f)<<endl;
	system("pause");
}
void main1101(){
	G  g1;
	g1.f1 = 100;
	g1.f2 = 200;
	g1.g= 300;
	//g1.f = 500; //继承的二义性 和 虚继承解决方案
	//g1.F1::f = 500;
	//g1.F2::f = 500;
	cout << "hello..." << endl;
	system("pause");
	return;
}












