#include<iostream>
using namespace std;

class Dog
{
		// 不写关键字的时候，就是 private 属性的
public:
	string name;
	int age ;
private:
	double weight;
};

int main()
{
	// 从栈中实例化对象
	Dog dog1;
	dog1.name = "旺财" ;
	cout << dog1.name << endl ; 
	dog1.weight = 50.2 ;
	// 从堆中实例化对象，要用 delete 删除 
	Dog *dog2 = new Dog ;  // 使用 new 关键字 
	dog2->age = 3 ;
	cout << dog2->age << endl;
	delete dog2 ;
	return 0;
}
