#include<iostream>
using namespace std;
class Dog
{
	public:
		Dog(){
			cout << "构造函数被执行了!" << endl; 
		}		
		~Dog();
};

Dog::~Dog()    // 析构函数也可以定义在外面 ，也可以定义在里面  :: -- 作用域运算符 
{
	cout << "析构函数被执行了!" << endl; 
}
int main()
{
	//Dog dog1 ; // 对象实例化 
	Dog *dog2 = new Dog ; // 从栈中实例化新对象 
	delete dog2;
	return 0;
} 
