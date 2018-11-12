#include  "iostream"
using namespace std;
//------------------------��̬---------------------
//������ඨ�����븸����ԭ����ͬ�ĺ����������б���д�ĺ�����Ȼ��̳и����࣬
//Ĭ������£���������д�ĺ��������ظ����еĺ���
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
	pp->print(); //ͨ��ָ�����
	rp.print();//ͨ�����õ���
	howToPrint(&child);
}
void main1(){
	run();
	return;
}
//Tips:��������β�����ָ�롢���ö���ָ����ĺ���
//����ϣ���ģ��������ָ��ָ����Ǹ����������ø��ຯ�����������ָ��ָ����������������������ж������д����.

//���������C++��ͨ��vitual�ؼ��ֶԶ�̬����֧��
//------------------------��̬��ʵ��-----------------------------
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
	//��дvirtual�ؼ��� �Ǿ�̬���� C++����������HeroFighter����,ȥִ�� ������͵�power���� �ڱ���������׶ξ��Ѿ������˺����ĵ���
	//��̬����: �ٰ�:  //�����е�ʱ��,���ݾ������(���������),ִ�в�ͬ����ĺ��� ,���ֳɶ�̬.
	if (hf->power() > ef->attack()){
		printf("����win\n");
	}
	else{
		printf("���ǹҵ�\n");
	}
}
//��̬��˼��
//�������3�����
//��װ: ͻ��c�����ĸ���....����������������ʱ��,����ʹ�ö�������� �Ͷ���ķ��� 
//�̳�: A B ���븴��
//��̬ : ����ʹ��δ��...


//��̬����Ҫ
//ʵ�ֶ�̬����������
//C���� ��Ӹ�ֵ ��ָ����ڵ��������
//��c���Ե����е����� (1 ������������  2 ��������  3 *p�ڱ����ú�����ȥ��ӵ��޸�ʵ�ε�ֵ)

//ʵ�ֶ�̬����������
//1 Ҫ�м̳� 
//2 Ҫ���麯����д
//3 �ø���ָ��(��������)ָ���������....
void main2(){
	HeroFighter hf;
	AdvHeroFight Advhf;
	EnemyFighter ef;
	AdvAdvHeroFighter advadvhf;
	PlayObj(&hf, &ef);
	PlayObj(&Advhf, &ef);
	PlayObj(&advadvhf, &ef);//�����汾�Ĵ��붼���Ե���,Ч������ͬ
}
//Tips:�ܽ�һ�仰�������ָ��ָ��ͬ��������󣬿��Ե��ò�ͬ�����෽��

//------------------��̬��ԭ��--�麯��--------------------------
class Parent2 {
public:
	Parent2(int a = 0){
		this->a = a;
	}
	virtual void print(){
		cout << "���ǵ�" << endl;
	}
	virtual void print2(){
		cout << "���ǵ�" << endl;
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
		cout << "���Ƕ���" << endl;
	}
private:
	int b;
};
void HowToPlay(Parent2 *base)
{
	base->print(); //�ж�̬����  //2 ���ֽ�  
	//Ч��:��������� ִ�������print���� ���������ִ�и����print���� 
	//C++��������������Ҫ������������� ���Ǹ������
	//���������������ֲ���vptrָ�� , ==>�麯����===>��������ڵ�ַ
	//�ٰ� (����ʱ��ʱ��,c++��������ȥ�ж�)
}
void main(){
	Parent2 p1; //�ڶ����л����һ��vptrָ��
	Child2 c1; //��������Ҳ��һ��vptrָ��
	HowToPlay(&p1);
	HowToPlay(&c1);
	return;
}

//----------------���麯���ͳ�����------------------
class  Figure //������
{
public:
	//�Ķ�һ��ͳһ�Ľ���(�ӿ�),������ʹ��,���������ȥʵ��
	virtual void getArea() = 0; //���麯��
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
		cout << "Բ�ε����: " << 3.14*a*a << endl;;

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
		cout << "�����ε����: " << a*b / 2 << endl;;
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
		cout << "�ı��ε����: " << a*b << endl;;
	}

private:
	int a;
	int b;
};


void objplay(Figure *base)
{
	base->getArea(); //�ᷢ����̬
}


void main511()
{

	//Figure f; //�����಻�ܱ�ʵ����

	Figure *base = NULL; //�����಻�ܱ�ʵ����

	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(50, 60);

	//�����������(����һ��Ԥ�ȶ���õĽӿڱ��)

	objplay(&c1);
	objplay(&t1);
	objplay(&s1);

	//c1.getArea();

	cout << "hello..." << endl;
	system("pause");
	return;
}