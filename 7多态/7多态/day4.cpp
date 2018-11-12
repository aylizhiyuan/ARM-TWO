#include  "iostream"
using namespace std;
//------------------------多态---------------------
//如果子类定义了与父类中原型相同的函数，父类中被重写的函数依然会继承给子类，
//默认情况下，子类中重写的函数将隐藏父类中的函数
class Parent1 {
public:
	void print(){
		cout << "Parent:print() do...." << endl;
	}
};
class Child1 :public Parent1 {
public:
	void print(){
		cout << "child:print() do...." << endl;
	}
};
void howToPrint(Parent1 *p){
	p->print();
}
void run(){
	Child1 child;
	Parent1 *pp = &child;
	Parent1 &rp = child;
	pp->print(); //通过指针调用
	rp.print();//通过引用调用
	howToPrint(&child);
}
void main1(){
	run();
	return;
}
//Tips:无论你如何操作，指针、引用都会指向父类的函数
//我们希望的，如果父类指针指向的是父类对象则调用父类函数，如果父类指针指向的是子类对象则调用子类中定义的重写函数.

//解决方案：C++中通过vitual关键字对多态进行支持
//------------------------多态的实例-----------------------------
class HeroFighter {
public:
	virtual int power(){
		return 10;
	}
};
class EnemyFighter {
public:
	int attack(){
		return 15;
	}
};
class AdvHeroFight :public HeroFighter{
public:
	virtual int power(){
		return 20;
	}
};
class AdvAdvHeroFighter :public HeroFighter {
public:
	virtual int power(){
		return 30;
	}
};
void PlayObj(HeroFighter *hf, EnemyFighter *ef){
	//不写virtual关键字 是静态联编 C++编译器根据HeroFighter类型,去执行 这个类型的power函数 在编译器编译阶段就已经决定了函数的调用
	//动态联编: 迟绑定:  //在运行的时候,根据具体对象(具体的类型),执行不同对象的函数 ,表现成多态.
	if (hf->power() > ef->attack()){
		printf("主角win\n");
	}
	else{
		printf("主角挂掉\n");
	}
}
//多态的思想
//面向对象3大概念
//封装: 突破c函数的概念....用类做函数参数的时候,可以使用对象的属性 和对象的方法 
//继承: A B 代码复用
//多态 : 可以使用未来...


//多态很重要
//实现多态的三个条件
//C语言 间接赋值 是指针存在的最大意义
//是c语言的特有的现象 (1 定义两个变量  2 建立关联  3 *p在被调用函数中去间接的修改实参的值)

//实现多态的三个条件
//1 要有继承 
//2 要有虚函数重写
//3 用父类指针(父类引用)指向子类对象....
void main2(){
	HeroFighter hf;
	AdvHeroFight Advhf;
	EnemyFighter ef;
	AdvAdvHeroFighter advadvhf;
	PlayObj(&hf, &ef);
	PlayObj(&Advhf, &ef);
	PlayObj(&advadvhf, &ef);//三个版本的代码都可以调用,效果还不同
}
//Tips:总结一句话：父类的指针指向不同的子类对象，可以调用不同的子类方法

//------------------多态的原理--虚函数--------------------------
class Parent2 {
public:
	Parent2(int a = 0){
		this->a = a;
	}
	virtual void print(){
		cout << "我是爹" << endl;
	}
	virtual void print2(){
		cout << "我是爹" << endl;
	}
private:
	int a;
};
class Child2 :public Parent2 {
public:
	Child2(int a = 0, int b = 0) :Parent2(a){
		this->b = b;
	}
	virtual void print(){
		cout << "我是儿子" << endl;
	}
private:
	int b;
};
void HowToPlay(Parent2 *base)
{
	base->print(); //有多态发生  //2 动手脚  
	//效果:传来子类对 执行子类的print函数 传来父类对执行父类的print函数 
	//C++编译器根本不需要区分是子类对象 还是父类对象
	//父类对象和子类对象分步有vptr指针 , ==>虚函数表===>函数的入口地址
	//迟绑定 (运行时的时候,c++编译器才去判断)
}
void main(){
	Parent2 p1; //在对象中会添加一个vptr指针
	Child2 c1; //子类里面也有一个vptr指针
	HowToPlay(&p1);
	HowToPlay(&c1);
	return;
}

//----------------纯虚函数和抽象类------------------
class  Figure //抽象类
{
public:
	//阅读一个统一的界面(接口),让子类使用,让子类必须去实现
	virtual void getArea() = 0; //纯虚函数
protected:
private:
};

class Circle : public Figure
{
public:
	Circle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "圆形的面积: " << 3.14*a*a << endl;;

	}

private:
	int a;
	int b;
};

class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "三角形的面积: " << a*b / 2 << endl;;
	}

private:
	int a;
	int b;
};


class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "四边形的面积: " << a*b << endl;;
	}

private:
	int a;
	int b;
};


void objplay(Figure *base)
{
	base->getArea(); //会发生多态
}


void main511()
{

	//Figure f; //抽象类不能被实例化

	Figure *base = NULL; //抽象类不能被实例化

	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(50, 60);

	//面向抽象类编程(面向一套预先定义好的接口编程)

	objplay(&c1);
	objplay(&t1);
	objplay(&s1);

	//c1.getArea();

	cout << "hello..." << endl;
	system("pause");
	return;
}