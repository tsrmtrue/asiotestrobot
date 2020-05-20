#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>         
#include <vector>
#include <thread>
#include <string>
#include <sstream>
#include <map>
#include <mutex>
#include <atomic>
#include <cassert>
#include <stdio.h>
std::atomic<std::string*> ptr;
int data;

void producer()
{
    std::string* p = new std::string("Hello");
    data = 42;
    ptr.store(p, std::memory_order_release);
}

void consumer()
{
    std::string* p2;
    while (!(p2 = ptr.load(std::memory_order_acquire)))
        ;
    assert(*p2 == "Hello"); // never fires
    assert(data == 42); // never fires
}

std::string computation(int)
{
    return "";
}
void print(std::string)
{

}

std::atomic<int> arr1, arr2, arr3;
int v = 0;
std::string dataarray[1000]; //non-atomic data

// Thread A, compute 3 values
void ThreadA(int v0, int v1, int v2)
{
    arr1.store(v);

    //assert( 0 <= v0, v1, v2 < 1000 );
    dataarray[v0] = computation(v0);
    dataarray[v1] = computation(v1);
    dataarray[v2] = computation(v2);
    std::atomic_thread_fence(std::memory_order_release);
    std::atomic_store_explicit(&arr1, v0, std::memory_order_relaxed);
    std::atomic_store_explicit(&arr2, v1, std::memory_order_relaxed);
    std::atomic_store_explicit(&arr3, v2, std::memory_order_relaxed);
}

// Thread B, prints between 0 and 3 values already computed.
void ThreadB()
{
    int v0 = std::atomic_load_explicit(&arr1, std::memory_order_relaxed);
    int v1 = std::atomic_load_explicit(&arr2, std::memory_order_relaxed);
    int v2 = std::atomic_load_explicit(&arr3, std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    // v0, v1, v2 might turn out to be -1, some or all of them.
    // otherwise it is safe to read the non-atomic data because of the fences:
    if (v0 != -1) { print(dataarray[v0]); }
    if (v1 != -1) { print(dataarray[v1]); }
    if (v2 != -1) { print(dataarray[v2]); }
}


int main(int argc, char* argv[])
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();

	return 0;
}
