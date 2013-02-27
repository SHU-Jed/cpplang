class A
{
public:
   virtual void Fun(int number = 10)
   {
       std::cout << "A::Fun with number " << number;
   }
};
 
class B:public A
{
public:
   virtual void Fun(int number = 20)
   {
       std::cout << "B::Fun with number " << number;
   }
};
 
int main()
{
   B b;
   A &a = b;
   a.Fun();
}

输出B::Fun with number 10。由于a是一个指向B实例的引用，因此在运行的时候会调用B::Fun。
但缺省参数是在编译期决定的。在编译的时候，编译器只知道a是一个类型a的引用，具体指向什么类型在编译期是不能确定的，
因此会按照A::Fun的声明把缺省参数number设为10。

这一题的关键在于理解确定缺省参数的值是在编译的时候，但确定引用、指针的虚函数调用哪个类型的函数是在运行的时候。


char* GetString1()
{
   char p[] = "Hello World";
   return p;
}
 
char* GetString2()
{
   char *p = "Hello World";
   return p;
}
 
 
int _tmain(int argc, _TCHAR* argv[])
{
   printf("GetString1 returns: %s. /n", GetString1());
   printf("GetString2 returns: %s. /n", GetString2());
 
   return 0;
}

输出两行，第一行GetString1 returns: 后面跟的是一串随机的内容，而第二行GetString2 returns: Hello World.
两个函数的区别在于GetString1中是一个数组，而GetString2中是一个指针。

当运行到GetString1时，p是一个数组，会开辟一块内存，并拷贝"Hello World"初始化该数组。
接着返回数组的首地址并退出该函数。由于p是GetString1内的一个局部变量，当运行到这个函数外面的时候，这个数组的内存会被释放掉。
因此在_tmain函数里再去访问这个数组的内容时，结果是随机的。

当运行到GetString2时，p是一个指针，它指向的是字符串常量区的一个常量字符串。
该常量字符串是一个全局的，并不会因为退出函数GetString2而被释放掉。因此在_tmain中仍然根据GetString2返回的地址得到字符串"Hello World"。


int _tmain(int argc, _TCHAR* argv[])
{
   char str1[] = "hello world";
   char str2[] = "hello world";
 
   char* str3 = "hello world";
   char* str4 = "hello world";
 
   if(str1 == str2)
       printf("str1 and str2 are same./n");
   else
       printf("str1 and str2 are not same./n");
 
   if(str3 == str4)
       printf("str3 and str4 are same./n");
   else
       printf("str3 and str4 are not same./n");
 
   return 0;
}

答案：输出两行。第一行是str1 and str2 are not same，第二行是str3 and str4 are same。

str1和str2是两个字符串数组。我们会为它们分配两个长度为12个字节的空间，并把"hello world"的内容分别拷贝到数组中去。
这是两个初始地址不同的数组，因此比较str1和str2的值，会不相同。str3和str4是两个指针，我们无需为它们分配内存以存储字符串的内容，
而只需要把它们指向"hello world“在内存中的地址就可以了。由于"hello world”是常量字符串，它在内存中只有一个拷贝，因此str3和str4指向的是同一个地址。
因此比较str3和str4的值，会是相同的。