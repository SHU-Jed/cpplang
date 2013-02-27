/*===================面试题1=====================
题目（一）：C++中我们可以用static修饰一个类的成员函数，也可以用const修饰类的成员函数（写在函数的最后表示不能修改成员变量，不是指写在前面表示返回值为常量）。请问：能不能同时用static和const修饰类的成员函数？

分析：答案是不可以。C++编译器在实现const的成员函数的时候为了确保该函数不能修改类的实例的状态，会在函数中添加一个隐式的参数const this*。但当一个成员为static的时候，该函数是没有this指针的。也就是说此时static的用法和static是冲突的。

*/

/*===================面试题2====================
求代码结果
*/

/*
#include <iostream>
using namespace std;

class A
{

};

class B
{
public:
	B(){}
	~B(){}
};

class C
{
	C(){}
	virtual  ~C(){}
};

void main()
{

	cout<<sizeof(A)<<" "<<sizeof(B)<<" "<<sizeof(C)<<endl;//1 1 4
}

*/

/*
#include <iostream>
class A
{
public:
	A()
	{
		Print();
	}
	virtual void Print()
	{
		printf("A is constructed.\n");
	}
};

class B: public A
{
public:
	B()
	{
		Print();
	}

	virtual void Print()
	{
		printf("B is constructed.\n");
	}
};

int main(int argc, char* argv[])
{
	A* pA = new B();
	delete pA;

	return 0;

}*/
//A is constructed. B is constructed.


/*
#include <iostream>

class A
{
private:
	int n1;
	int n2;
public:
	A(): n2(0), n1(n2 + 2)
	{
	}

	void Print()
	{
		std::cout << "n1: " << n1 << ", n2: " << n2 << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	a.Print();

	return 0;
}

答案：输出n1是一个随机的数字，n2为0。在C++中，成员变量的初始化顺序与变量在类型中的申明顺序相同，
而与它们在构造函数的初始化列表中的顺序无关。因此在这道题中，会首先初始化n1，而初始n1的参数n2还没有初始化，
是一个随机值，因此n1就是一个随机值。初始化n2时，根据参数0对其初始化，故n2=0。
*/


/*
#include <iostream>

class A
{
private:
int value;

public:
A(int n)
{
value = n;
}

A(A other)
{
value = other.value;
}

void Print()
{
std::cout << value << std::endl;
}
};

int _tmain(int argc, _TCHAR* argv[])
{
A a = 10;
A b = a;
b.Print();

return 0;
}

答案：编译错误。在复制构造函数中传入的参数是A的一个实例。
由于是传值，把形参拷贝到实参会调用复制构造函数。
因此如果允许复制构造函数传值，那么会形成永无休止的递归并造成栈溢出。
因此C++的标准不允许复制构造函数传值参数，而必须是传引用或者常量引用。在Visual Studio和GCC中，都将编译出错。
*/


#include <iostream>
using namespace std;

class A
{
public:
	A(){
		cout<<"A is constructed.\n";
	}
	 
	~A(){
		cout<<"A is destructed.\n";
	}
};


class B: public A
{
	
public :
		B(){
		cout<<"B is constructed.\n";
	}

	~B(){
		cout<<"B is destructed.\n";
	}
};

int main(){
	A * pA =new B();
	delete pA;
}

/*
答案：输出三行，分别是：A is created. B is created. A is deleted。
用new创建B时，回调用B的构造函数。在调用B的构造函数的时候，会先调用A的构造函数。
因此先输出A is created. B is created.

接下来运行delete语句时，会调用析构函数。
由于pA被声明成类型A的指针，同时基类A的析构函数没有标上virtual，因此只有A的析构函数被调用到，而不会调用B的析构函数。

由于pA实际上是指向一个B的实例的指针，但在析构的时候只调用了基类A的析构函数，却没有调用B的析构函数。
这就是一个问题。如果在类型B中创建了一些资源，比如文件句柄、内存等，在这种情况下都得不到释放，从而导致资源泄漏。
*/