//��ν�ĺ���ģ�壬ʵ�����ǽ���һ��ͨ�ú���,�亯�����ͺ��β����Ͳ������ƶ�����һ��������������������ͨ�õĺ����ͳ�Ϊ����ģ�塣
//����ģ��Ķ�����ʽ 
//				template <������ʽ������>
//						���� ������(��ʽ������){
//									�������
//						}
#include <iostream>
using namespace std;
//����ģ��Ķ��岿��
template <typename T>
//����ģ�����������
void myswap(T &a, T &b){
	T c = 0;
	c = a;
	a = b;
	b = c;
	cout << "hello ...����ģ�庯��,��ӭcall��" << endl;
}
int main1(){
	{
		int x = 10;
		int y = 20;
		myswap<int>(x, y);//����ģ�� ��ʾ���� ����
		printf("x:%d,y:%d\n", x, y);
	}
	{
		char a = 'a';
		char b = 'b';
		myswap<char>(a, b);
		printf("x:%c,y:%c\n", a, b);
	}
	return 0;
}
