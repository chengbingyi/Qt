#include<iostream>
using namespace std;
class Dog
{
	public:
		Dog(){
			cout << "���캯����ִ����!" << endl; 
		}		
		~Dog();
};

Dog::~Dog()    // ��������Ҳ���Զ��������� ��Ҳ���Զ���������  :: -- ����������� 
{
	cout << "����������ִ����!" << endl; 
}
int main()
{
	//Dog dog1 ; // ����ʵ���� 
	Dog *dog2 = new Dog ; // ��ջ��ʵ�����¶��� 
	delete dog2;
	return 0;
} 
