#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>         // std::chrono::seconds
//#include <gperftools/heap-profiler.h>
#include <vector>

#include <string>
#include <sstream>
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

struct TransInfo
{
    uint32_t robot_id{ 0 };
    uint32_t protocol_id{ 0 };
    std::string trans_name;
    int32_t trans_result{ 0 };
    int32_t cost_ms{ 0 };
    int64_t timestamps{ 0 };//second
    int64_t timestampus{ 0 };//micro second
    TransInfo()
    {
        static int32_t i = 0;
        i++;
        std::cout << "TransInfo  "<< i << std::endl;
    }
};

void TestClassDerive()
{
    auto * b = new B;
    void  * v = (void *)b;
    auto * a = static_cast<A*>(v);
    delete a;
}

void TestEmplaceBack(std::list<TransInfo> & list_tr)
{
    TransInfo f1;
    f1.protocol_id = 32;
    f1.trans_name = "first";
    list_tr.emplace_back(f1);

    f1.protocol_id = 333;

}


class TestDestruct
{
public:
    TestDestruct()
    {

    }
    ~TestDestruct()
    {
        std::cout << "ss " << s << std::endl;
    }

    std::string s;
};

struct Openid
{
    uint32_t id[6]{ 0 };

    bool operator==(const Openid &t)const {
        return this->id[0] == t.id[0]
            && this->id[1] == t.id[1]
            && this->id[2] == t.id[2]
            && this->id[3] == t.id[3]
            && this->id[4] == t.id[4]
            && this->id[5] == t.id[5];
    };
    Openid(uint32_t id0, uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4, uint32_t id5 )
    {
        id[0] = id0;
        id[1] = id1;
        id[2] = id2;
        id[3] = id3;
        id[4] = id4;
        id[5] = id5;
    }
};
namespace std
{
    template<> struct hash<Openid>
    {
        typedef Openid argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& s) const noexcept
        {
            result_type const h0(std::hash<uint32_t>{}(s.id[0]));
            result_type const h1(std::hash<uint32_t>{}(s.id[1]));
            result_type const h2(std::hash<uint32_t>{}(s.id[2]));
            result_type const h3(std::hash<uint32_t>{}(s.id[3]));
            result_type const h4(std::hash<uint32_t>{}(s.id[4]));
            result_type const h5(std::hash<uint32_t>{}(s.id[5]));
            return h0 ^ (h1<<1) ^ h2 ^ (h3 << 2) ^ h4 ^ (h5 << 2); // or use boost::hash_combine (see Discussion)
        }
    };
}

#include <unordered_map>
#include <random>
#include <chrono>


void TestRawOpenid(uint32_t count)
{
	auto t = sizeof(Openid);
	std::cout << "TestRawOpenid count " << count<< std::endl;
	for (uint32_t i = 0; i < count; i++)
	{
		Openid*  id = new Openid(1, 1, 1, 
			1, 1, 1);
	}



	std::chrono::seconds sec(1000);

	std::this_thread::sleep_for(sec);

}

void TestOpenid(uint32_t count)
{
    //随机初始化数量
	auto t = sizeof(Openid);
	std::cout << "TestOpenid count " << count << std::endl;

    std::unordered_map<Openid, bool> all_keys;

    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 0xfffffff);

    {
        auto start = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i < count; i++)
        {
            Openid id(r(), r(), r(), r(), r(), r());

            all_keys[id] = true;
        }
        {
            Openid id(1, 2, 3, 4, 5, 6);

            all_keys[id] = true;


        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "create time " << diff.count() << std::endl;
    }
    //查询计时
    {
        auto start = std::chrono::high_resolution_clock::now();

        Openid id(1, 2, 3, 4, 5, 6);
        auto result = all_keys[id];

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "search result "<<result<<"  "
            << id.id[0] << "," << id.id[1] << "," << id.id[2] << "," << id.id[3] << "," << id.id[4] << "," << id.id[5] << "  time " << diff.count() << std::endl;
    }
    for (uint32_t i = 0; i<10; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();

        Openid id(r(), r(), r(), r(), r(), r());
         all_keys[id] = true;

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "add  result " << true << "  "
            << id.id[0] << "," << id.id[1] << "," << id.id[2] << "," << id.id[3] << "," << id.id[4] << "," << id.id[5] << "  time " << diff.count() << std::endl;
    }

	std::chrono::seconds sec(1000);

	std::this_thread::sleep_for(sec);


}



int main(int argc, char* argv[])
{
	auto count = 10;
	if (argc > 1)
	{
		count = atoi(argv[1]);
	}
	
	TestOpenid(count);
    //HeapProfilerStart("heap.profile"); // 添加函数之一

    //std::vector<B> v;
    //for (size_t i = 0; i < 300000; i++)
    //{
    //    v.emplace_back();

    //}
    //
    //HeapProfilerStop();  // 添加函数之二

    //std::chrono::seconds sec(100);
 
    //std::this_thread::sleep_for(sec);

	return 0;
}
