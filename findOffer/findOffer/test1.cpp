/*===================������1=====================
��Ŀ��һ����C++�����ǿ�����static����һ����ĳ�Ա������Ҳ������const������ĳ�Ա������д�ں���������ʾ�����޸ĳ�Ա����������ָд��ǰ���ʾ����ֵΪ�����������ʣ��ܲ���ͬʱ��static��const������ĳ�Ա������

���������ǲ����ԡ�C++��������ʵ��const�ĳ�Ա������ʱ��Ϊ��ȷ���ú��������޸����ʵ����״̬�����ں��������һ����ʽ�Ĳ���const this*������һ����ԱΪstatic��ʱ�򣬸ú�����û��thisָ��ġ�Ҳ����˵��ʱstatic���÷���static�ǳ�ͻ�ġ�

*/

/*===================������2====================
�������
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

�𰸣����n1��һ����������֣�n2Ϊ0����C++�У���Ա�����ĳ�ʼ��˳��������������е�����˳����ͬ��
���������ڹ��캯���ĳ�ʼ���б��е�˳���޹ء������������У������ȳ�ʼ��n1������ʼn1�Ĳ���n2��û�г�ʼ����
��һ�����ֵ�����n1����һ�����ֵ����ʼ��n2ʱ�����ݲ���0�����ʼ������n2=0��
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

�𰸣���������ڸ��ƹ��캯���д���Ĳ�����A��һ��ʵ����
�����Ǵ�ֵ�����βο�����ʵ�λ���ø��ƹ��캯����
�����������ƹ��캯����ֵ����ô���γ�������ֹ�ĵݹ鲢���ջ�����
���C++�ı�׼�������ƹ��캯����ֵ�������������Ǵ����û��߳������á���Visual Studio��GCC�У������������
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
�𰸣�������У��ֱ��ǣ�A is created. B is created. A is deleted��
��new����Bʱ���ص���B�Ĺ��캯�����ڵ���B�Ĺ��캯����ʱ�򣬻��ȵ���A�Ĺ��캯����
��������A is created. B is created.

����������delete���ʱ�����������������
����pA������������A��ָ�룬ͬʱ����A����������û�б���virtual�����ֻ��A���������������õ������������B������������

����pAʵ������ָ��һ��B��ʵ����ָ�룬����������ʱ��ֻ�����˻���A������������ȴû�е���B������������
�����һ�����⡣���������B�д�����һЩ��Դ�������ļ�������ڴ�ȣ�����������¶��ò����ͷţ��Ӷ�������Դй©��
*/