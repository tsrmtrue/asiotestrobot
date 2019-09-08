#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>         // std::chrono::seconds
#include <gperftools/profiler.h>


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
    ProfilerStart("/tmp/test"); // ��Ӻ���֮һ

    auto * b = new B;
    void  * v = (void *)b;
    auto * a = static_cast<A*>(v);
    delete a;
    ProfilerStop();  // ��Ӻ���֮��

	return 0;
}
