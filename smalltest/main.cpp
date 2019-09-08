#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>         // std::chrono::seconds
#include <gperftools/heap-profiler.h>


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
    char t[1024];
};




int main(int argc, char* argv[])
{
    HeapProfilerStart("heap.profile"); // 添加函数之一

    for (size_t i = 0; i < 3000; i++)
    {
        auto * b = new B;

    }
    
    HeapProfilerStop();  // 添加函数之二

    std::chrono::seconds sec(100);
 
    std::this_thread::sleep_for(sec);

	return 0;
}
