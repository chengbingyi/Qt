#include<iostream>
using namespace std;
// 这是基类，也叫父类 
class Aniaml
{
	public:
		string name;
		int age;
		void run(){
			cout << "狗的年龄: " << age << endl ;
		}
}; 

// 这个类是派生类，也叫子类 
class Dog : public Aniaml // 类的继承 
{
};

int main()
{
	Dog dog1;
	dog1.age = 5;
	dog1.run();
	return 0;
}
