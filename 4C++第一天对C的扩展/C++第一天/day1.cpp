#include "iostream" //����c++��ͷ�ļ�
using namespace std;//ʹ�������ռ�std��׼�������ռ�(���������ռ��ﶨ���˺ܶ��׼����)
//------------------�򵥵�hello ����-------------------------------
void main1(){
	//cout��׼��� ��<<���Ʋ���������C++�У�����������
	cout  <<  "hello...." << endl;//endl�ǻس����е���˼
}
//---------------------����Բ���ܳ������-----------------------------
//1.�ýṹ���ķ������
void main2(){
	double r, girth, area;
	const double PI = 3.1415;
	cout << "please input radius:\n";
	cin >> r;//����
	girth = 2 * PI * r;
	area = PI * r * r;
	cout << "radius=" << r << endl;
	cout << "girth=" << girth << endl;
	cout << "area=" << area << endl;
}
//2.����Զ���ķ������
class Circle
{
	double radius; //��Ա����
	public: //��ķ��ʿ���
	void Set_Radius(double r) { radius = r; } //��Ա����
	double Get_Radius()  { return  radius; } //ͨ����Ա�������ó�Ա����
	double Get_Girth()     { return  2 * 3.14f * radius; } //ͨ����Ա������ȡ��Ա����
	double Get_Area()     { return  3.14f * radius * radius; }
};
void main3(){
	Circle A, B; //���ඨ�����
	A.Set_Radius(6.23); //��ĵ���
	cout << "A.Radius = " << A.Get_Radius() << endl;
	cout << "A.Girth = " << A.Get_Girth() << endl;
	cout << "A.Area = " << A.Get_Area() << endl;
	B.Set_Radius(10.5);
	cout << "B.radius = " << B.Get_Radius() << endl;
	cout << "B.Girth=" << B.Get_Girth() << endl;
	cout << "B.Area = " << B.Get_Area() << endl;
}
//------------------- c++�����ռ�-----------------------------
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
	//���������ռ䣬���Ʊ�����������,c++��׼������е����б�ʶ������������һ����Ϊstd�������ռ䣬˵���ˣ����ǽ�ȫ��������ֳ��˼�����ͬ�Ĳ��֣���ͬ�����ռ��еĺ����ͱ�������ͬ�������ᷢ����ͻ
	using namespace NameSpaceA;
	using namespace NameSpaceB::NameSpaceC;
	printf("a=%d\n", a);
	printf("a=%d\n", NameSpaceB::a);//ʹ�ö�������ռ��е�ͬ��������ʱ��ͨ������Ҫָ���ĸ������ռ��
	NameSpaceB::NameSpaceC::Teacher t1 = { "aaa", 3 };
	printf("t1.name=%s\n", t1.name);
	printf("t1.age=%d\n", t1.age);
	system("pause");
	return;
}
//-----------------------register���������ǿ----------------
void main5(){
	register int a = 0;//��C�����޷���ȡ���Ĵ��������ĵ�ַ�ģ�C++����
	printf("&a=%x\n", &a);
	system("pause");
	return;
}
//----------------------struct���ͼ�ǿ-----------------------
struct Student {
	char name[100];
	int age;
};//C++�е�struct��һ�������͵Ķ�������
void main6(){
	Student s1 = { "wang", 1 };
	Student s2 = { "wang2", 2 };
}
//----------------------C++����ǿ������--------------------
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
//Tips:int f()��C�����У���ʾ����ֵΪint��������������ĺ���,int f(void)��ʾ����ֵΪint���޲κ��������ǣ���C++�У�int f()��int f(void)����ʾ����ֵΪint���޲κ���

//----------------------boolean------------------------------
void main8(){
	//c++��C���Ի�����������bool����,ռһ���ֽ�
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
//----------------------��Ŀ����--------------------------------
void main9(){
	int a = 10;
	int b = 20;
	//����һ����С�� ���Ҹ���С����ֵ��3
	//��Ŀ�������һ�����ʽ �����ʽ����������ֵ
	(a < b ? a : b) = 30;
	printf("a = %d, b = %d\n", a, b);
	system("pause");
}
//----------------------const----------------------------------
void main10(){
	//const int a = 10; //����һ������
	//int const b = 20;//����һ������
	//int c = 30;
	//const int *c = &a; //�����㲻��ͨ��*c�޸�ĳ���ڴ��ַ��ֵ
	//int * const d = &c;//�������޷��ı�*d��ָ��
	//const int * const e = &a;//ָ�������ָ����ڴ�ռ䣬�����ܱ��޸�

	const int test = 10;
	int *p = (int*)&test;
	printf("a====>%d\n", test);
	*p = 11;
	printf("a====>%d\n", test);
}

//------------------------����----------------------------
void main11(){
	//������ʵ������һ�������ڴ�ռ�ı������ܲ���ȡ�ü��������أ�
	//���ÿ��Կ�����һ���Ѷ�������ı���
	//���õ� �﷨��Type& name = var
	int a = 10; //c����������4���ֽ��ڴ档����a�ڴ�ռ�ı���
	int &b = a;  //b����a�ı���������
	a = 11; //ֱ�Ӹ�ֵ
	{
		int *p = &a;
		*p = 12;
		printf("a %d \n", a);
	}
	b = 14;
	printf("a:%d b:%d", a, b);
	system("pause");

}
//---------------------��������������--------------------------
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
	printfT2(t1); //pT��t1�ı���
	printf("t1.age:%d \n", t1.age); //33
	printfT3(t1);// pT���β� ,t1 copyһ������ ��pT     //---> pT = t1
	printf("t1.age:%d \n", t1.age); //33
	cout << "hello..." << endl;
	system("pause");
}
//Tips: Type &name ��ͬ�� Type * const name ��ָ��
int  main121(){
	//����������ֵΪ����ʱ,������ջ���������ܳ�Ϊ�������õĳ�ʼֵ
	//�����ؾ�̬������ȫ�ֱ�����������Ϊ�������õĳ�ʼֵ
	//1.����ֵ�ǻ������ͣ�������
	//int a;
	//a = 10;
	//return a;//���ص���ʵ��a��һ��������������a����.������Ϊ�������õĳ�ʼֵ

	//int b;
	//b = 20;
	//return &b; //�����ص���һ���ֲ����������ã��Ҹо�����.

	//static int c = 30;
	//c++;
	//return c; //��̬�����������Ҹо���û�������.

	//int *p������βεĻ�
	//int *p;
	//*p = 100;
	//return *p; //������Ϊ����
	return 0;
}
int main122(){
	//ʹ�ñ�����ʼ��const����
	//const Type& name = var;
	//const �����ñ���ӵ��ֻ������
	int a = 10;
	const int &b = a;
	//int *p = (int *)&b;
	//b = 11; //err
	//*p = 11; //ֻ����ָ�����ı���
	cout << "b--->" << a << endl;
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b);
	system("pause");
	return 0;
}
void main123(){
	//��ͨ����
	int a = 10;
	int &b = a;
	//�������� ���ñ�������ֻ������
	const int &c = a;
	//�������ó�ʼ�� ��Ϊ����
	//1 �ñ��� ��ʼ�� ��������
	{
		int x = 20;
		const int& y = x;
		printf("y:%d \n", y);
	}
	//2 �ó��� ��ʼ�� ��������
	{
		//int &m = 10; //�������ڴ�ռ�ı��� ������10û���ڴ�ռ� û�з���������
		const int &m = 10;
	}
	cout << "hello..." << endl;
	system("pause");
	return;
}

//---------------------��������inline--------------------------
inline int myfunc(int a, int b){
	return a < b ? a : b;
}
#define MYFUNC(a, b) ((a) < (b) ? (a) : (b))  
void main13(){
	int a = 1;
	int b = 3;
	//int c = myfunc(++a, b);  //ͷ��ϵͳ
	int c = MYFUNC(++a, b);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	system("pause");
	return;
}
//Tips:���������ڱ����ʱ��ֱ�ӽ���������뺯�����õĵط������������ƣ�1.���ܴ����κ���ʽ��ѭ����䣻2.���ܴ��ڹ���������ж���䣻3.�����岻�ܹ����Ӵ�4.���ܶԺ�������ȡ��ַ���������������ɱ���������ֱ�ӽ������ĺ����������õĵط��������Ƭ����Ԥ�������������м򵥵��ı��滻��û���κα�����̡�
//---------------------����-Ĭ�ϲ���---------------------------
void myPrint(int x = 3){
	//1.ֻ�в����б��߲��ֵĲ����ſ����ṩĬ�ϲ���ֵ
	//2.һ����һ�����������п�ʼʹ��Ĭ�ϲ���ֵ����ô�������������в���������ʹ��Ĭ�ϲ���ֵ
	printf("x:%d", x);
}
void main14(){
	return ;
}
//---------------------����ռλ����-----------------------------
int func(int a, int b, int){
	return a + b;
}
void main15(){
	//func(1, 2);
	printf("func(1, 2, 3) = %d\n", func(1, 2, 3));
}
//---------------------Ĭ�ϲ�����ռλ�������------------------
int func2(int a, int b, int = 0){
	return a + b;
}
void main16(){
	//���Ĭ�ϲ�����ռλ������һ�𣬶��ܵ�������
	func2(1, 2);
	func2(1, 2, 3);
	system("pause");
}
//---------------------��������-----------------------------------
//��ͬһ�����������岻ͬ�ĺ��������������Ͳ�ͬ�Ĳ�������ʱ���������岻ͬ
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