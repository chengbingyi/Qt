#include<iostream>
using namespace std;

class Dog
{
		// ��д�ؼ��ֵ�ʱ�򣬾��� private ���Ե�
public:
	string name;
	int age ;
private:
	double weight;
};

int main()
{
	// ��ջ��ʵ��������
	Dog dog1;
	dog1.name = "����" ;
	cout << dog1.name << endl ; 
	dog1.weight = 50.2 ;
	// �Ӷ���ʵ��������Ҫ�� delete ɾ�� 
	Dog *dog2 = new Dog ;  // ʹ�� new �ؼ��� 
	dog2->age = 3 ;
	cout << dog2->age << endl;
	delete dog2 ;
	return 0;
}
