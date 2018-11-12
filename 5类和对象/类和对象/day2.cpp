#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
//----------------------类的封装------------------
//封装的两层含义：
//1.把数据和函数合成一个整体,对属性和方法进行封装
//2.把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏
int main1(){
	class Circle{
	public: //修饰成员变量和成员函数可以在类的内部和类的外部访问
		double r;
		double s;
	public:
		double getR(){
			a++;
			return r;
		}
		void setR(double val){
			r = val;
		}
	public:
		double getS(){
			s = 3.14f*r*r;
			return s;
		}
	private://修饰成员变量和成员函数只能在类的内部被访问
		int a;
	};
	return 0;
}
//Tips:在 struct定义类时，所有的成员的默认属性是public,在用class定义类时，所有的成员的默认属性是private
//--------------------类的构造和析构函数----------------
//类可以定义与类名相同的特殊成员函数，这种与类名相同的成员函数叫做构造函数，用来处理对象的初始化，C++编译器自动调用
//类可以定义一个特殊的成员函数清理对象，这个特殊的成员函数叫做析构函数
int main2(){
	class Test{
	private:
		int a;
		int b;
	public:
		Test(){
			printf("无参数的构造函数");
		};
		Test(int a){ //有一个参数的构造函数
			printf("\na:%d", a);
		};
		Test(int a, int b){
			printf("\na:%d b:%d", a, b); //有两个参数的构造函数
		};
	};
	//Test t1;//无参数构造函数的调用
	//Test t2(10);  //有参数构造函数的三种调用方式①
	//Test t3(20, 10);//②
	//Test t4 = Test(30);//③
	return 0;
}

//-------------------赋值构造函数的应用场景---------------------
class AA {
public:
	AA(){
		cout << "我是构造函数，自动被调用了" << endl;
	}
	AA(int _a){
		a = _a;
	}
	AA(const AA &obj2){
		cout << "我也是构造函数，我是通过另外一个对象obj2，来初始化我自己" << endl;
		a = obj2.a + 10;
	}
	~AA(){
		cout << "我是析构函数，自动被调用了" << endl;
	}
	void getA(){
		printf("a:%d\n", a);
	}
private:
	int a;
};
void obj1(){
	AA a1;//调用了无参的默认构造函数
	AA a2 = a1;//分别调用了构造函数（a2）和赋值构造函数（a1）
}
void obj2(){
	AA a1(10);//调用了构造函数
	AA a2(a1);//调用了赋值构造函数
	a2.getA();
}
int main3(){
	//obj1();
	//obj2();
	return 0;
}
//Tips:当类中没有定义任何一个构造函数的时候，C++编译器会提供默认无参构造函数和默认拷贝构造函数；

//-----------------------浅拷贝-----------------------
//对象的数据资源是由指针指示的堆时，默认的赋值构造函数仅做指针值复制
//解决办法：不使用编译器提供的浅拷贝
class Name{
public:
	Name(const char *pname){
		size = strlen(pname);
		pName = (char*)malloc(size + 1);
		strcpy(pName, pname);
		//cout << "我是构造函数" << endl;
	}
	//Name obj2 = obj1;
	//解决方案: 手工的编写拷贝构造函数 使用深copy
	Name(Name &obj){
		pName = (char *)malloc(obj.size + 1);
		strcpy(pName, obj.pName);
		size = obj.size;
		//cout << "我是赋值构造函数" << endl;
	}
	~Name(){
		cout << "开始析构" << endl;
		if (pName != NULL){
			free(pName);
			pName = NULL;
			size = 0;
		}
	}
	void operator = (Name &obj3){
		if (pName != NULL){
			free(pName);
			pName = NULL;
			size = 0;
		}
		cout << "测试有没有调用我。。。。" << endl;
		pName = (char *)malloc(obj3.size + 1);
		strcpy(pName, obj3.pName);
		size = obj3.size;
	}
private:
	char *pName;
	int size;
};
//对象的初始化 和 对象之间=号操作是两个不同的概念
void playObj(){
	Name obj1("obj1.....");
	Name obj2 = obj1; //C++编译器提供的 默认的copy构造函数  浅拷贝
	Name obj3("obj3...");
	obj2 = obj3; // C++编译器提供的 等号操作 也属 浅拷贝
}
void main4(){
	playObj();
	system("pause");
}

//---------------------------多个对象的构造和析构------------------
//1 构造函数的初始化列表  解决: 在B类中 组合了一个 A类对象 (A类设计了构造函数)
//根据构造函数的调用规则 设计A的构造函数, 必须要用;没有机会初始化A
//新的语法  Constructor::Contructor() : m1(v1), m2(v1,v2), m3(v3)
class ABC {
public:
	ABC(int a, int b, int c){
		this->a = a;
		this->b = b;
		this->c = c;
		printf("a:%d,b:%d,c:%d\n", a, b, c);
		printf("ABC construct..\n");
	}
	~ABC(){
		printf("a:%d,b:%d,c:%d\n", a, b, c);
		printf("~ABC()...\n");
	}
private:
	int a;
	int b;
	int c;
};
class myD{
public:
	myD():abc1(1, 2, 3), abc2(4, 5, 6), m(100){
		cout << "MyD()" << endl;
	}
	~myD(){
		cout << "myD()" << endl;
	}
private:
	ABC abc1;//C++编译器不知道如何构造abc1
	ABC abc2;
	const int m;//需要初始化的时候就赋值
};
int run(){
	myD myd;
	return 0;
}
int main5(){
	run();
	return 0;
}

//---------------综合练习--------------------
class ABCD{
public:
	ABCD(int a, int b, int c){
		this->a = a;
		this->b = b;
		this->c = c;
		printf("ABCD() construct, a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
	}
	~ABCD(){
		printf("~ABCD() construct,a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
	}
	int getA(){
		return this->a;
	}
protected:
private:
	int a;
	int b;
	int c;
};
class MyE
{
public:
	MyE() :abcd1(1, 2, 3), abcd2(4, 5, 6), m(100)
	{
		cout << "MyD()" << endl;
	}
	~MyE()
	{
		cout << "~MyD()" << endl;
	}
	MyE(const MyE & obj) :abcd1(7, 8, 9), abcd2(10, 11, 12), m(100)
	{
		printf("MyD(const MyD & obj)\n");
	}
protected:
	//private:
public:
	ABCD abcd1; //c++编译器不知道如何构造abc1
	ABCD abcd2;
	const int m;

};
int doThing(MyE mye1)
{
	printf("doThing() mye1.abc1.a:%d \n", mye1.abcd1.getA());
	return 0;
}
int run2()
{
	MyE myE;
	doThing(myE);
	return 0;
}
int run3(){
	printf("run3 start..\n");
	//ABCD(400, 500, 600); //临时对象的生命周期  
	ABCD abcd = ABCD(100, 200, 300);
	//若直接调用构造函数呢？
	//想调用构造函数对abc对象进行再复制，可以吗？
	//在构造函数里面调用另外一个构造函数，会有什么结果？
	printf("run3 end\n");
	return 0;
}
int main6(){
	//run2();
	run3();
	system("pause");
	return 0;
}
//Tips:当类中有成员变量是其他类的对象时，首先调用成员变量的构造函数，调用顺序与声明顺序相同，之后调用自身类的构造函数，析构函数的调用顺序与对应的构造函数调用顺序相反

//-----------------------------对象的动态创建和释放------------------
//new的使用形式：指针变量 = new 类型(常量) 指针变量 = new 类型[表达式]
//作用从堆中分配一块"类型"大小的存储空间，返回首地址
//delete的使用形式：delete 指针变量 delete[] 指针变量
void main7(){
	//分配基础类型
	int *p2 = new int;
	*p2 = 20;
	free(p2);
	int *p3 = new int(30);
	delete p3;
	int *pArray = new int[10];
	pArray[1] = 2;
	delete [] pArray; //数组不要把[]忘记
	//分配对象
	class Test{
	public:
		Test(int _a){
			a = _a;
			cout << "构造函数执行" << endl;
		}
		~Test(){
			cout << "析构函数执行" << endl;
		}
	protected:
	private:
		int a;
	};
	Test *pT2 = new Test(10);
	delete pT2;
}

//--------------静态成员变量成员函数------------------------
//属于类的变量，归所有的对象拥有.
//关键字static可以说明一个类的成员，它并不是对象的成员
class BB{
public:
	void printC(){
		cout << "c:" << c << endl;
	}
	void AddC(){
		c = c + 1;
	}
	static void getC(){ //静态成员函数 
		cout << "c:" << c << endl;
		//请在静态成员函数中,能调用 普通成员属性  或者 普通成员函数吗?
		//cout << "a:" << a << endl; //error C2597: 对非静态成员“BB::a”的非法引用
	}
protected:
private:
	int a;
	int b;
	static int c; //静态成员变量
};

//静态函数中 不能使用 普通成员变量 普通成员函数 ..
int BB::c = 10;
void main8(){
	BB b1, b2, b3;
	b1.printC(); //10
	b2.AddC(); //11
	b3.printC(); //11

	//静态成员函数的调用方法
	b3.getC(); //用对象.
	BB::getC();//类::

	cout << "hello..." << endl;
	system("pause");
	return;
}

//------------------this指针------------------
//C++类对象中的成员变量和成员函数是分开存储的,成员变量存储在对象中，静态的成员变量存储在全局数据区中，成员函数存储于代码段中。

//int getK() const {return k},代码是如何区别具体哪个对象的K的值的？

//普通成员函数都隐式的包含一个指向当前对象的this指针
//静态成员函数不包含指向具体对象的指针
class Test1{
public:
	Test1(int a, int b){  //----> Test(Test *this,int a,int b)
		this->a = a;
		this->b = b;
	}
	void printT(){
		cout << "a:" << a << endl;
		cout << "b:" << this->b << endl;
	}
private:
	int a;
	int b;
};
void main9(){
	Test1 t1(1, 2);
	t1.printT();// ===> printT(&t1),这个理解非常的关键
	cout << "hello..." << endl;
	system("pause");
	return;
}

//-------------------------友元函数---------------------
class A1{
public:
	A1(){
		a1 = 100;
		a2 = 200;
	}
	int getA1(){
		return this->a1;
	}
	//声明一个友元函数
	friend void setA1(A1 *p, int a1); //这个函数是这个类的好朋友
protected:
private:
	int a1;
	int a2;
};

void setA1(A1 *p, int a1)
{
	p->a1 = a1;
}
void main10(){
	A1 mya1;
	cout << mya1.getA1() << endl;
	setA1(&mya1, 300); //通过友元函数 修改A类的私有属性
	cout << mya1.getA1() << endl;
	system("pause");
}

//--------------友元类----------------------
class A {
	friend class B; //B是A的友元
public:
	void Display(){
		cout << x << endl;
	}
private:
	int x;
};
class B {
public:
	void Set(int i){
		Aobject.x = i;
	}
	void Display(){
		Aobject.Display();
	}
private:
	A Aobject; //B中有个A，A是B的子属性
};
void main11(){
	B Bobject;
	Bobject.Set(100);
	Bobject.Display();
}

//----------------全局函数和成员函数-------------
class Test{
public:
	int a;
	int b;
public:
	~Test(){
		cout << "a:" << a << " b: " << b;
		cout << "析构函数自动被调用" << endl;
	}
public:
	void printT(){
		cout << "a:" << a << " b: " << b << endl;
	}
public:
	//t3 = t1.TestAdd(t2);
	Test TestAdd(Test &t2){
		Test tmp(this->a + t2.a, this->b + t2.b);
		return tmp;
	}
	//t1.TestAdd2(t2);
	//返回一个引用 相当于返回自身 
	//返回t1这个元素 this就是&t1
	Test& TestAdd2(Test &t2){
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;
		return *this; //把 *(&t1) 又回到了 t1元素
	}
public:
	Test(int a = 0, int b = 0){
		this->a = a;
		this->b = b;
	}
};
//把成员函数 转成 全局函数 多了一个参数
void printT(Test *pT){
	cout << "a:" << pT->a << " b: " << pT->b << endl;
}

//全局函数的方法 
//全局函数 转成 成员函数  少了一个参数 
Test TestAdd(Test &t1, Test &t2){
	Test tmp;
	return tmp;
}

void main12(){
	Test t1(1, 2);
	Test t2(3, 4);
	//t1 = t1 + t2;
	t1.TestAdd2(t2);
	t1.printT();
}
void main13(){
	Test t1(1, 2);
	Test t2(3, 4);
	Test t3;
	//全局函数方法
	t3 = TestAdd(t1, t2);
	//成员函数方法
	{
		//先把测试案例写出来
		Test t4 = t1.TestAdd(t2); //匿名对象直接转化成t4
		t4.printT();
		Test t5;
		t5 = t1.TestAdd(t2); //匿名对象 复制 给t5
		t5.printT();
	}
	cout << "hello..." << endl;
	system("pause");
	return;
}
