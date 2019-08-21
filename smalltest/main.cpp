#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>         // std::chrono::seconds


//测试析构子类析构函数在void * 转换下
class A
{
public:
    A() {};
    virtual ~A() 
    {
        std::cout << "~ A" << std::endl;
    };
};
class B :public A
{
public:
    B() {};
    virtual ~B()
    {
        std::cout << "~ B" << std::endl;
    }
};




int main(int argc, char* argv[])
{
    auto * b = new B;
    void  * v = (void *)b;
    auto * a = static_cast<A*>(v);
    delete a;

	return 0;
}
