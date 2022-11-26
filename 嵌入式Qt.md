# 嵌入式 Qt 开发
## 纲要
一、C++ 基础
### 一、`C++`  基础
#### 1.1 简介
- 与C语言一样，C++也是在贝尔实验室里诞生的。
- **C语言是一种面向过程的编程语言，C++是一种面向对象的编程语言**
#### 1.2 部分语法
- 在 C++ 里，我们使用以 `cin` 和 `cout `代替了`scanf `和 `printf`
- 在传统的 C 语言里，变量初始化时必须在程序的前面定义在前面，而 C++则是可以随用随定义。x 可以是任意数据类型，甚至可以写成一个表达式，这比 C 语言需要指定数据类型方便多了。
- `endl` 指的是换行符，与 C 语言的`\n`效果一样。
> C++ 标准

#### 1.3 类和对象
- C++中类是一种构造类型，与C语言中结构体相似，但进行了一些扩展，类的成员不仅仅可以是变量，还可以是函数；通过类定义出来的变量也有特定的称呼，叫做 "对象"
- 类是创建对象的模板，一个类可以创建多个对象，每个对象都是类类型的一个变量；创建对象的过程也叫类的实例化。
```C++
// 类的定义
class 类名  // 类名首字母要大写
{
public:
	公有的数据;
protected:
	保护的数据;
private:
	私有的数据;
};    // 不能忘记 ';'
```
>​        C++通过 `public` 、`protected`、`private` 三个关键字来控制成员变量和成员函数的访问权限，它们分别表示公有的、受保护的、私有的，被称为成员访问限定符。所谓访问权限，就是你能不能使用该类中的成员。

- 从类中实例化对象分两种方法，一种是从栈中实例化对象，一种是从堆中实例化对象。

  代码：
```C++
#include<iostream>
using namespace std;

class Dog
{
		// 不写关键字的时候，就是 private 属性的
public:
	string name;
	int age ;
};

int main()
{
	// 从栈中实例化对象
	Dog dog1;
	dog1.name = "旺财" ;
	cout << dog1.name << endl ; 
	// 从堆中实例化对象，要用 delete 删除，由于程序一直运行，这个指针一直占着内存，会造成内存泄漏
	Dog *dog2 = new Dog ;  // 使用 new 关键字 
	dog2->age = 3 ;
	cout << dog2->age << endl;
	delete dog2 ;
	return 0;
}
```
> 输出结果：
>> 旺财
>> 3

其中：
```C++
#include<iostream>
using namespace std;

class Dog
{
		// 不写关键字的时候，就是 private 属性的
public:
	string name;
	int age ;
private:  // 私有的，不能被后面实例化
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
```
输出结果：
> [Error] 'double Dog::weight' is private
>> 同理 `protected` 也不能在对象实例化时使用。

- 解读：类的成员不仅仅可以是变量，还可以是函数
```C++
#include<iostream>
using namespace std;

class Dog
{
		// 不写关键字的时候，就是 private 属性的
public:
	string name;
	int age ;
	void run(){
		cout << "狗会跑" << endl;
	}
protected:
	double weight;
};

int main()
{
	// 从栈中实例化对象
	Dog dog1;
	dog1.name = "旺财" ;
	cout << dog1.name << endl ; 
	dog1.run();
	// 从堆中实例化对象，要用 delete 删除 
	Dog *dog2 = new Dog ;  // 使用 new 关键字 
	dog2->age = 3 ;
	cout << dog2->age << endl;
	delete dog2 ;
	return 0;
}
```
输出结果：
>旺财
>狗会跑
>3

#### 1.4 构造函数与析构函数
##### 1.4.1 构造函数
- 定义了一个名称和类名相同，没有返回值的函数，这个函数称为构造函数。构造函数的特殊之处在于，它会在类实例化的时候被调用。
```C++
#include<iostream>
using namespace std;
class Dog
{
	public:
		Dog();
}；
```
##### 1.4.2 析构函数
- <font color=#8797FFF>对象实例化的时候，会调用构造函数，而对象销毁的时候，就会调用析构函数。</font>
```C++
#include<iostream>
using namespace std;
class Dog
{
	public:
		~Dog();
}；
```
- 实例：
```C++
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
	Dog dog1 ; // 对象实例化 
	return 0;
} 
```
执行结果：
> 构造函数被执行了!
> 析构函数被执行了!

- 析构函数与构造函数的体现
```C++
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
	return 0;
} 
```
执行结果：
> 构造函数被执行了!
>> 说明新的对象 dog2 没有被销毁

- 注意：
	- <font color=#FF0000>当类实例化对象的时候</font>，如果没有定义构造函数，则编译器会合成一个默认的构造函数；<font color=#FF0000>当有了对象后</font>，如果没有定义析构函数，则编译器会合成一个默认的析构函数。
#### 1.5 继承、多态
- 什么是基类和派生类：
	- 创建新类时，并不需要创建全新的数据和成员函数，我们可以指明这个新类继承现有类的成员。此时，现有的类称为 "基类" ，继承实现的新类称为 "派生类"。
```c++
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
```

- 公有继承（public）：当一个类派生继承公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
	- 公有继承时基类中各成员属性保持不变，基类中 private 成员被隐藏。派生类的成员只能访问基类中的 public / protected 成员，而不能访问 private 成员；派生类的对象只能访问基类中的 public 成员 。
- 保护继承（protected）： 当一个类派生继承保护基类时，基类的公有和保护成员将成为派生类的保护成员。
	- 保护继承时
- 私有继承（private）：当一个类派生继承私有基类时，基类的公有和保护成员将成为派生类的私有成员。



























