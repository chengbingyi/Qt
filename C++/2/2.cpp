#include<iostream>
using namespace std;

class Dog
{
		// ��д�ؼ��ֵ�ʱ�򣬾��� private ���Ե�
public:
	string name;
	int age ;
	void run(){
		cout << "������" << endl;
	}
protected:
	double weight;
};

int main()
{
	// ��ջ��ʵ��������
	Dog dog1;
	dog1.name = "����" ;
	cout << dog1.name << endl ; 
	dog1.run();
	// �Ӷ���ʵ��������Ҫ�� delete ɾ�� 
	Dog *dog2 = new Dog ;  // ʹ�� new �ؼ��� 
	dog2->age = 3 ;
	cout << dog2->age << endl;
	delete dog2 ;
	return 0;
}
