#include <iostream>
using namespace std;

//ģ����
template <class T>
class A {
public:
	A(T a){
		this->a = a;
	}
	void printA(){
		cout << "a:" << a << endl;
	}
protected:
	T a;
};
//ģ����������ͨ��
//ģ��������ʱ����Ҫ���廯ģ���࣬��������Ҫ֪��������������;�����ʲô���ӵ�
//Ҫ֪��������ռ�ڴ��С�Ƕ��� ֻ���������͹̶���������֪����η����ڴ�
class B :public A<int>{
public:
	B(int a = 10, int b = 20) :A<int>(a){
		this->b = b;
	}
	void printB(){
		cout << "a:" << a << "b:" << b << endl;
	}
private:
	int b;
};

//��ģ���� ���� ģ����
template<typename T>
class C :public A<T> {
public:
	C(T c, T a) :A<T>(a){
		this->c = c;
	}
	void printC(){
		cout << "c:" << c << endl;
	}
protected:
	T c;
};
void main6(){
	C<int>c1(1, 2);
	c1.printC();
	return;
}
void main62(){
	B b1(1, 2);
	b1.printB();
	return;
}

//��ģ������������
//������������ Ҫ�������� ����ҪA <int> &a
void UseA(A<int> &a){
	a.printA();
}
void main63(){
	A<int>a1(11), a2(20), a3(30);
	UseA(a1);
	UseA(a2);
	UseA(a3);
	cout << "hello..." << endl;
	return;
}