#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>         // std::chrono::seconds
#include <gperftools/heap-profiler.h>


//����������������������void * ת����
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
    HeapProfilerStart("heap.profile"); // ��Ӻ���֮һ

    for (size_t i = 0; i < 1000000; i++)
    {
        auto * b = new B;

    }
    
    HeapProfilerStop();  // ��Ӻ���֮��

	return 0;
}
