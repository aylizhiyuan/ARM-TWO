#include <iostream>
using namespace std;
class Complex {
public:
	int a;
	int b;
	Complex(int a = 0, int b = 0){
		this->a = a;
		this->b = b;
	}
	void printCom(){
		cout << a << "+" << b << "i" << endl;
	}
};
//������ȫ�ֺ���
Complex myAdd(Complex &c1, Complex &c2){
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
//������ ����
Complex operator+(Complex &c1, Complex &c2){
	cout << "12345��ɽ���ϻ�" << endl;
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
void main1(){
	int a = 0;
	int b = 0;
	int c;
	c = a + b;
	Complex c1(1, 2), c2(3, 4);
	Complex c3;
	c3 = c1 + c2;
	//c1-- ;
	//--c1;

	//C++������Ӧ�ø����ǳ���Ա�ṩһ�ֻ���...
	//���Զ������������л���������������=====>��������ػ���

	//�ܽ᣺��������صı��� �� ��������

	cout << "hello...." << endl;
	return;
	


}

