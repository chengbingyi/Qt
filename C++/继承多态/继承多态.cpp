#include<iostream>
using namespace std;
// ���ǻ��࣬Ҳ�и��� 
class Aniaml
{
	public:
		string name;
		int age;
		void run(){
			cout << "��������: " << age << endl ;
		}
}; 

// ������������࣬Ҳ������ 
class Dog : public Aniaml // ��ļ̳� 
{
};

int main()
{
	Dog dog1;
	dog1.age = 5;
	dog1.run();
	return 0;
}
