#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
//----------------------��ķ�װ------------------
//��װ�����㺬�壺
//1.�����ݺͺ����ϳ�һ������,�����Ժͷ������з�װ
//2.�ѿ͹������װ�ɳ�����࣬��������԰��Լ������ݺͷ���ֻ�ÿ��ŵ�����߶���������Բ����ŵĽ�����Ϣ����
int main1(){
	class Circle{
	public: //���γ�Ա�����ͳ�Ա��������������ڲ�������ⲿ����
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
	private://���γ�Ա�����ͳ�Ա����ֻ��������ڲ�������
		int a;
	};
	return 0;
}
//Tips:�� struct������ʱ�����еĳ�Ա��Ĭ��������public,����class������ʱ�����еĳ�Ա��Ĭ��������private
//--------------------��Ĺ������������----------------
//����Զ�����������ͬ�������Ա������������������ͬ�ĳ�Ա�����������캯���������������ĳ�ʼ����C++�������Զ�����
//����Զ���һ������ĳ�Ա������������������ĳ�Ա����������������
int main2(){
	class Test{
	private:
		int a;
		int b;
	public:
		Test(){
			printf("�޲����Ĺ��캯��");
		};
		Test(int a){ //��һ�������Ĺ��캯��
			printf("\na:%d", a);
		};
		Test(int a, int b){
			printf("\na:%d b:%d", a, b); //�����������Ĺ��캯��
		};
	};
	//Test t1;//�޲������캯���ĵ���
	//Test t2(10);  //�в������캯�������ֵ��÷�ʽ��
	//Test t3(20, 10);//��
	//Test t4 = Test(30);//��
	return 0;
}

//-------------------��ֵ���캯����Ӧ�ó���---------------------
class AA {
public:
	AA(){
		cout << "���ǹ��캯�����Զ���������" << endl;
	}
	AA(int _a){
		a = _a;
	}
	AA(const AA &obj2){
		cout << "��Ҳ�ǹ��캯��������ͨ������һ������obj2������ʼ�����Լ�" << endl;
		a = obj2.a + 10;
	}
	~AA(){
		cout << "���������������Զ���������" << endl;
	}
	void getA(){
		printf("a:%d\n", a);
	}
private:
	int a;
};
void obj1(){
	AA a1;//�������޲ε�Ĭ�Ϲ��캯��
	AA a2 = a1;//�ֱ�����˹��캯����a2���͸�ֵ���캯����a1��
}
void obj2(){
	AA a1(10);//�����˹��캯��
	AA a2(a1);//�����˸�ֵ���캯��
	a2.getA();
}
int main3(){
	//obj1();
	//obj2();
	return 0;
}
//Tips:������û�ж����κ�һ�����캯����ʱ��C++���������ṩĬ���޲ι��캯����Ĭ�Ͽ������캯����

//-----------------------ǳ����-----------------------
//�����������Դ����ָ��ָʾ�Ķ�ʱ��Ĭ�ϵĸ�ֵ���캯������ָ��ֵ����
//����취����ʹ�ñ������ṩ��ǳ����
class Name{
public:
	Name(const char *pname){
		size = strlen(pname);
		pName = (char*)malloc(size + 1);
		strcpy(pName, pname);
		//cout << "���ǹ��캯��" << endl;
	}
	//Name obj2 = obj1;
	//�������: �ֹ��ı�д�������캯�� ʹ����copy
	Name(Name &obj){
		pName = (char *)malloc(obj.size + 1);
		strcpy(pName, obj.pName);
		size = obj.size;
		//cout << "���Ǹ�ֵ���캯��" << endl;
	}
	~Name(){
		cout << "��ʼ����" << endl;
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
		cout << "������û�е����ҡ�������" << endl;
		pName = (char *)malloc(obj3.size + 1);
		strcpy(pName, obj3.pName);
		size = obj3.size;
	}
private:
	char *pName;
	int size;
};
//����ĳ�ʼ�� �� ����֮��=�Ų�����������ͬ�ĸ���
void playObj(){
	Name obj1("obj1.....");
	Name obj2 = obj1; //C++�������ṩ�� Ĭ�ϵ�copy���캯��  ǳ����
	Name obj3("obj3...");
	obj2 = obj3; // C++�������ṩ�� �ȺŲ��� Ҳ�� ǳ����
}
void main4(){
	playObj();
	system("pause");
}

//---------------------------�������Ĺ��������------------------
//1 ���캯���ĳ�ʼ���б�  ���: ��B���� �����һ�� A����� (A������˹��캯��)
//���ݹ��캯���ĵ��ù��� ���A�Ĺ��캯��, ����Ҫ��;û�л����ʼ��A
//�µ��﷨  Constructor::Contructor() : m1(v1), m2(v1,v2), m3(v3)
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
	ABC abc1;//C++��������֪����ι���abc1
	ABC abc2;
	const int m;//��Ҫ��ʼ����ʱ��͸�ֵ
};
int run(){
	myD myd;
	return 0;
}
int main5(){
	run();
	return 0;
}

//---------------�ۺ���ϰ--------------------
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
	ABCD abcd1; //c++��������֪����ι���abc1
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
	//ABCD(400, 500, 600); //��ʱ�������������  
	ABCD abcd = ABCD(100, 200, 300);
	//��ֱ�ӵ��ù��캯���أ�
	//����ù��캯����abc��������ٸ��ƣ�������
	//�ڹ��캯�������������һ�����캯��������ʲô�����
	printf("run3 end\n");
	return 0;
}
int main6(){
	//run2();
	run3();
	system("pause");
	return 0;
}
//Tips:�������г�Ա������������Ķ���ʱ�����ȵ��ó�Ա�����Ĺ��캯��������˳��������˳����ͬ��֮�����������Ĺ��캯�������������ĵ���˳�����Ӧ�Ĺ��캯������˳���෴

//-----------------------------����Ķ�̬�������ͷ�------------------
//new��ʹ����ʽ��ָ����� = new ����(����) ָ����� = new ����[���ʽ]
//���ôӶ��з���һ��"����"��С�Ĵ洢�ռ䣬�����׵�ַ
//delete��ʹ����ʽ��delete ָ����� delete[] ָ�����
void main7(){
	//�����������
	int *p2 = new int;
	*p2 = 20;
	free(p2);
	int *p3 = new int(30);
	delete p3;
	int *pArray = new int[10];
	pArray[1] = 2;
	delete [] pArray; //���鲻Ҫ��[]����
	//�������
	class Test{
	public:
		Test(int _a){
			a = _a;
			cout << "���캯��ִ��" << endl;
		}
		~Test(){
			cout << "��������ִ��" << endl;
		}
	protected:
	private:
		int a;
	};
	Test *pT2 = new Test(10);
	delete pT2;
}

//--------------��̬��Ա������Ա����------------------------
//������ı����������еĶ���ӵ��.
//�ؼ���static����˵��һ����ĳ�Ա���������Ƕ���ĳ�Ա
class BB{
public:
	void printC(){
		cout << "c:" << c << endl;
	}
	void AddC(){
		c = c + 1;
	}
	static void getC(){ //��̬��Ա���� 
		cout << "c:" << c << endl;
		//���ھ�̬��Ա������,�ܵ��� ��ͨ��Ա����  ���� ��ͨ��Ա������?
		//cout << "a:" << a << endl; //error C2597: �ԷǾ�̬��Ա��BB::a���ķǷ�����
	}
protected:
private:
	int a;
	int b;
	static int c; //��̬��Ա����
};

//��̬������ ����ʹ�� ��ͨ��Ա���� ��ͨ��Ա���� ..
int BB::c = 10;
void main8(){
	BB b1, b2, b3;
	b1.printC(); //10
	b2.AddC(); //11
	b3.printC(); //11

	//��̬��Ա�����ĵ��÷���
	b3.getC(); //�ö���.
	BB::getC();//��::

	cout << "hello..." << endl;
	system("pause");
	return;
}

//------------------thisָ��------------------
//C++������еĳ�Ա�����ͳ�Ա�����Ƿֿ��洢��,��Ա�����洢�ڶ����У���̬�ĳ�Ա�����洢��ȫ���������У���Ա�����洢�ڴ�����С�

//int getK() const {return k},�����������������ĸ������K��ֵ�ģ�

//��ͨ��Ա��������ʽ�İ���һ��ָ��ǰ�����thisָ��
//��̬��Ա����������ָ���������ָ��
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
	t1.printT();// ===> printT(&t1),������ǳ��Ĺؼ�
	cout << "hello..." << endl;
	system("pause");
	return;
}

//-------------------------��Ԫ����---------------------
class A1{
public:
	A1(){
		a1 = 100;
		a2 = 200;
	}
	int getA1(){
		return this->a1;
	}
	//����һ����Ԫ����
	friend void setA1(A1 *p, int a1); //��������������ĺ�����
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
	setA1(&mya1, 300); //ͨ����Ԫ���� �޸�A���˽������
	cout << mya1.getA1() << endl;
	system("pause");
}

//--------------��Ԫ��----------------------
class A {
	friend class B; //B��A����Ԫ
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
	A Aobject; //B���и�A��A��B��������
};
void main11(){
	B Bobject;
	Bobject.Set(100);
	Bobject.Display();
}

//----------------ȫ�ֺ����ͳ�Ա����-------------
class Test{
public:
	int a;
	int b;
public:
	~Test(){
		cout << "a:" << a << " b: " << b;
		cout << "���������Զ�������" << endl;
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
	//����һ������ �൱�ڷ������� 
	//����t1���Ԫ�� this����&t1
	Test& TestAdd2(Test &t2){
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;
		return *this; //�� *(&t1) �ֻص��� t1Ԫ��
	}
public:
	Test(int a = 0, int b = 0){
		this->a = a;
		this->b = b;
	}
};
//�ѳ�Ա���� ת�� ȫ�ֺ��� ����һ������
void printT(Test *pT){
	cout << "a:" << pT->a << " b: " << pT->b << endl;
}

//ȫ�ֺ����ķ��� 
//ȫ�ֺ��� ת�� ��Ա����  ����һ������ 
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
	//ȫ�ֺ�������
	t3 = TestAdd(t1, t2);
	//��Ա��������
	{
		//�ȰѲ��԰���д����
		Test t4 = t1.TestAdd(t2); //��������ֱ��ת����t4
		t4.printT();
		Test t5;
		t5 = t1.TestAdd(t2); //�������� ���� ��t5
		t5.printT();
	}
	cout << "hello..." << endl;
	system("pause");
	return;
}
