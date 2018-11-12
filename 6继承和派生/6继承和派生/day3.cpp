#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
//-------------------�̳�----------------------
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

//------------������ķ��ʿ���--------------------
//public���εģ�������ڲ����ⲿ������ʹ��
//protected���εģ�������ڲ�ʹ�ã��ڼ̳е������п���ʹ��,�����ĵط�����
//private���εģ�ֻ��������ڲ�ʹ�ã�����������ⲿʹ��
class Parent1{
public:
	int a; //�ϵ�������
protected:
	int b;//�ϵ�����������
private:
	int c;//�ϵ�������
};
//�����̳�
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
//Tips:protected�̳з�ʽ��public,protectedΪprotected,private��Ȼ��private

//˽�м̳�
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
//Tips:���е�˽�м̳е�������󶼻��Ϊprivate

//�����̳�
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
//Tips:��Ȼ��������ķ��ʿ��ƣ�û�б仯


//----------------------���ͼ�����----------------
//����Ҫ���������κεط���������ʹ�ù���������Ķ��������ͨ�����м̳У�������õ��˻����г����캯������������֮������г�Ա
//���������Ե��������������
//����������ֱ�Ӹ�ֵ���������
//����������ֱ�ӳ�ʼ���������
//����ָ�����ֱ��ָ���������
//�������ÿ���ֱ�������������
//�ܽ᣺�����������ĸ��� base *p = &child
class Parent2 {
public:
	void printP(){
		cout << "���ǵ�..." << endl;
	}
	Parent2(){
		cout << "parent2���캯��" << endl;
	}
	Parent2(const Parent &obj){
		cout << "copy���캯��" << endl;
	}
private:
	int a;
};
class Child4 :public Parent2 {
public:
	void printC(){
		cout << "���Ƕ���" << endl;
	}
private:
	int c;
};

void howToPrint(Parent2 *base){
	base->printP();// ����ĳ�Ա����
}
void howToPrint2(Parent2 &base){
	base.printP();//����ĳ�Ա����
}
void main5(){
	Parent2 p1;
	p1.printP();
	Child4 c4;
	c4.printC();
	c4.printP();

	//��ֵ������ԭ��
	//1.����ָ��ָ��������� 
	Parent2 *p = NULL;
	//p = &c4;//����ò�Ʋ���

	//2.ָ������������
	howToPrint(&p1);
	howToPrint(&c4);

	//3.������Ϊ��������
	howToPrint2(p1);//
	howToPrint2(c4);//

	Parent2 p3 = c4; //��������������ʼ���������
}
/*
���ݹ�������ָ������������������
���������Ե����������ʹ��
����������ֱ�Ӹ�ֵ���������
����������ֱ�ӳ�ʼ���������
����ָ�����ֱ��ָ���������
�������ÿ���ֱ�������������
*/

//------------------�̳��еĹ��������--------------------------
//�����๹�캯������ʱ����Ҫ���ø��๹�캯������̳е����ĳ�Ա���г�ʼ��
//�������������ʱ����Ҫ���ø���������������̳е����ĳ�Ա��������
class Parent3 {
public:
	Parent3(int a, int b){
		this->a = a;
		this->b = b;
		cout << "���๹�캯��..." << endl;
	}
	~Parent3(){
		cout << "��������..." << endl;
	}
	void printP(int a, int b){
		this->a = a;
		this->b = b;
		cout << "���ǵ�..." << endl;
	}
private:
	int a;
	int b;
};
class Child5 :public Parent3 {
public:
	Child5(int a, int b, int c) : Parent3(a, b){
		this->c = c;
		cout << "����Ĺ��캯��" << endl;
	}
	~Child5(){
		cout << "���������" << endl;
	}
	void printC(){
		cout << "���Ƕ���" << endl;
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

//-------------�̳�����ϻ������£���������������ԭ��------------
class Object {
public:
	Object(int a, int b){
		this->a = a;
		this->b = b;
		cout << "object���캯��ִ��" << "a" << a << "b" << b << endl;
	}
	~Object(){
		cout << "object��������\n";
	}
protected:
	int a;
	int b;
};
class Parent4 :public Object {
public:
	Parent4(char *p) :Object(1, 2){
		this->p = p;
		cout << "���๹�캯��..." << p << endl;
	}
	~Parent4(){
		cout << "��������..." << p << endl;
	}
	void printP(int a, int b){
		cout << "���ǵ�...." << endl;
	}
protected:
	char *p;
};
class child6 : public Parent4{
public:
	child6(char *p) :Parent4(p), obj1(3, 4), obj2(5, 6){
		this->myp = p;
		cout << "����Ĺ��캯��" << myp << endl;
	}
	~child6(){
		cout << "���������" << myp << endl;
	}
	void printC(){
		cout << "���Ƕ���" << endl;
	}
protected:
	char *myp;
	Object obj1;
	Object obj2;
};
void objplay(){
	child6 c1("�̳в���");
}
void main7(){
	objplay();
	cout << "hello....." << endl;
	return;
}
//Tips:�ȹ��츸�࣬�ٹ����Ա����������ڹ����Լ����������Լ�����������Ա�����������������,ԭ���ȹ���ĺ��ͷ�

//----------------�̳��е�ͬ����Ա����������-------------------------
//�������Ա�����븸���Ա����ͬ��ʱ��������Ȼ�Ӹ���̳�ͬ����Ա����������ͨ��������ֱ��::����ͬ����Ա���֣�����������ʹ�û����ͬ����Ա����ʽ��ʹ�������޶���
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
	b1.A::print();//��ӡ�����صĻ����е�print����
	b1.B::print(); //Ĭ�����
	//��Ա����Ҳ��ͬ�������
}

//--------------------�������е�static�ؼ���--------------------
//���ඨ��ľ�̬��Ա���������е������๲��,���ݾ�̬��Ա����ķ������Ժ�������ļ̳з�ʽ����������ϵ�о��в�ͬ�ķ�������. �������з��ʾ�̬��Ա��ʹ������::��Ա
class C {
public:
	C(){
		cout << "C�Ĺ��캯��" << endl;
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
int C::a = 100; //����̬��Ա��ֵ

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

//-----------------------��̳�---------------------------
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

//---------------------------��̳�---------------------------
//���һ��������Ӷ����������������Щ��������һ����ͬ�Ļ��࣬���ڶԸû��������������ֽ��з��ʵ�ʱ�򣬻��ж�����
// class B{public:int b}
// class B1:public B{private:int b1;}
// class B2:public B{private:int b2;}
// class C:pubilc B1,public B2 {public:int f();private:int d;}
// c.B1::b c.B2::b ,����c.B::b ���Ķ��̳У�

//Ҫʹ���������������������ֻ����һ���Ӷ��󣬱���������������Ϊ��̳У�ʹ��������Ϊ����� ,ʹ�ùؼ���virtual
class F{
public:
	F()
	{
		cout << "F���캯��ִ��\n";
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
	cout << sizeof(F1) << endl; //12 //����virtual�Ժ� , C++���������ڸ�����͵͵��������
	cout << sizeof(F2) << endl;  //8
	//cout<<sizeof(f)<<endl;
	system("pause");
}
void main1101(){
	G  g1;
	g1.f1 = 100;
	g1.f2 = 200;
	g1.g= 300;
	//g1.f = 500; //�̳еĶ����� �� ��̳н������
	//g1.F1::f = 500;
	//g1.F2::f = 500;
	cout << "hello..." << endl;
	system("pause");
	return;
}












