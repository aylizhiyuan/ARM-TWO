#include <iostream>
using namespace std;
// template���� C++����������Ҫ��ʼ���ͱ���ˣ�����T����Ҫ����
template <typename T>
void myswap(T &a, T &b){
	T c = 0;
	c = a;
	a = b;
	b = c;
	cout << "hello....����ģ�庯�� ��ӭcall��" << endl;
}
void myswap(int a, char c){
	cout << "a:" << a << "c:" << c << endl;
	cout << "������ͨ��������ӭ����" << endl;
}
void main4(){
	int a = 10;
	char c = 'z';
	myswap(a, c);
	myswap(c, a);//������õľ�����ͨ����
	myswap(a, a);//����ģ�庯���ĵ��ã��ϸ������ͽ����Զ�ת��
	cout << "hello" << endl;
	return;
}

