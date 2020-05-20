#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>         
//#include <gperftools/heap-profiler.h>  todo ����lib�⣬�Լ�tcmalloc
#include <vector>
#include <thread>
#include <string>
#include <sstream>
#include <map>
#include <mutex>
#include "ae_lock.h"


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
	Openid() {};
    Openid(uint32_t id0, uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4, uint32_t id5 )
    {
        id[0] = id0;
        id[1] = id1;
        id[2] = id2;
        id[3] = id3;
        id[4] = id4;
        id[5] = id5;
    }
	bool operator <(const Openid& r) const
	{
		if (id[0] < r.id[0])
		{
			return true;
		}
		else if (id[0] == r.id[0])
		{
			if (id[1] < r.id[1])
			{
				return true;
			}
			else if (id[1] == r.id[1])
			{
				if (id[2] < r.id[2])
				{
					return true;
				}
				else if (id[2] == r.id[2])
				{
					if (id[3] < r.id[3])
					{
						return true;
					}
					else if (id[3] == r.id[3])
					{
						if (id[4] < r.id[4])
						{
							return true;
						}
						else if (id[4] == r.id[4])
						{
							if (id[5] < r.id[5])
							{
								return true;
							}
						}
					}
				}
			}
		}


		return false;
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
	std::cout << "TestRawOpenid count [" << count<<"]"<<"sizeof ["<< sizeof(Openid) <<"]"<< std::endl;
	for (uint32_t i = 0; i < count; i++)
	{
		Openid*  id = new Openid(1, 1, 1, 
			1, 1, 1);
		id->id[2] = 3;
	}



	std::chrono::seconds sec(1000);

	std::this_thread::sleep_for(sec);

}

void TestOpenid(uint32_t count)
{
    //�����ʼ������
	std::cout << "TestOpenid count " << count << std::endl;
	std::cout << "sizeof Openid is " << sizeof(Openid) << std::endl;

    std::unordered_map<Openid, bool> all_keys;

	//�����������
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 0xfffffff);
	//����ָ������������
    {
        auto start = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i < count; i++)
        {
            Openid id(r(), r(), r(), r(), r(), r());

			//all_keys.emplace(r(), true);
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
    {
        auto start = std::chrono::high_resolution_clock::now();

        Openid id(1, 2, 3, 4, 5, 6);
        auto result = all_keys[id];

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "search result "<<result<<"  "
            << id.id[0] << "," << id.id[1] << "," << id.id[2] << "," << id.id[3] << "," << id.id[4] << "," << id.id[5] << "  time " << diff.count() << std::endl;
    }

	//��ѯ��ʱ
    for (uint32_t i = 0; i<10; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();

        Openid id(r(), r(), r(), r(), r(), r());
        bool r = all_keys.find(id) != all_keys.end();

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "search  result " << r << "  "
            << id.id[0] << "," << id.id[1] << "," << id.id[2] << "," << id.id[3] << "," << id.id[4] << "," << id.id[5] << "  time " << diff.count() << std::endl;
    }
	{
		auto start = std::chrono::high_resolution_clock::now();

		Openid id(1,2,3,4,5,6);
		bool r = all_keys.find(id) != all_keys.end();

		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end - start;
		std::cout << "search  result " << r << "  "
			<< id.id[0] << "," << id.id[1] << "," << id.id[2] << "," << id.id[3] << "," << id.id[4] << "," << id.id[5] << "  time " << diff.count() << std::endl;
	}

	std::chrono::seconds sec(1000);

	std::this_thread::sleep_for(sec);
}

void TestStdString(uint32_t count)
{
	std::string  s;
	//s.reserve(256);
	{
		auto start = std::chrono::high_resolution_clock::now();


		for (uint32_t i = 0; i < count; i++)
		{
			s="";
			s.append("12121");
			s.append("dsdsd");
			s.append("jkjkjk");
			s.append("kkjhk");
			s.append("oooo");
			s.append("nmnm");
			s.append("nmnk");
			s.append("nnnn");
			s.append("uuuu");
			s.append("dsddsxdsd");
			s.append("sdsdffgvxfgvxs");
			s.append("sdsdffgvxfgvxs");
			s.append("sdsdffgvxfgvxs");
			s.append("sdsdffgvxfgvxs");
		}
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end - start;
		std::cout <<"["<< std::this_thread::get_id() <<"]"<< s.size() << " append cost " << "  time " << diff.count() << std::endl;

	}

	{
		auto start = std::chrono::high_resolution_clock::now();


		for (uint32_t i = 0; i < count; i++)
		{
			s.clear();
			s+="12121";
			s+="dsdsd";
			s += "jkjkjk";
			s += "kkjhk";
			s += "oooo";
			s += "nmnm";
			s += "nmnk";
			s += "nnnn";
			s += "uuuu";
			s += "dsddsxdsd";
			s += "sdsdffgvxfgvxs";
			s += "sdsdffgvxfgvxs";
			s += "sdsdffgvxfgvxs";
			s += "sdsdffgvxfgvxs";
		}
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end - start;
		std::cout << s.size() << " += cost " << "  time " << diff.count() << std::endl;

	}
}
#include <iostream>
#include <fstream>

void TestWriteOpenid(uint32_t count)
{
	//�����������
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 0xfffffff);
	//����д��
	{
		auto start = std::chrono::high_resolution_clock::now();

		std::string filename = "openid_singlg_w";
		std::ofstream ostrm(filename, std::ios::binary);
		for (uint32_t i = 0; i < count; i++)
		{
			Openid id(r(), r(), r(), r(), r(), r());
			ostrm.write(reinterpret_cast<char*>(&id), sizeof( Openid)); // 

		}
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end - start;
		std::cout << "write single time " << diff.count() << std::endl;
	}
	//���д��
	{
		auto start = std::chrono::high_resolution_clock::now();

		std::string filename = "openid_100_w";
		std::ofstream ostrm(filename, std::ios::binary);
		for (uint32_t i = 0; i < count/100; i++)
		{
			Openid id[100];
			ostrm.write(reinterpret_cast<char*>(id), sizeof(Openid) *100); // 

		}
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end - start;
		std::cout << "write blcok  time " << diff.count() << std::endl;
	}
}

void TestReadOpenid(uint32_t count)
{
	//������ȡ
	{
		auto start = std::chrono::high_resolution_clock::now();

		std::string filename = "openid_singlg_w";
		std::ifstream istrm( filename.c_str(), std::ios::binary | std::ios::ate );
		size_t i = 0; 
		uint64_t size = 0;
		if (!istrm.is_open()) {
			std::cout << "failed to open " << filename << '\n';
		}
		else
		{
			istrm.seekg(0, std::ios::end); // rewind

			size = istrm.tellg();

			istrm.seekg(0); // rewind

			Openid id;

			for (; i<size/sizeof(Openid); ++i)
			{
				istrm.read(reinterpret_cast<char*>(&id), sizeof(Openid));
			}
		}

		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end - start;
		std::cout << "read single time " << diff.count() <<"read size "<<size<<" readcount "<< i<< std::endl;
	}
	//�����ȡ
	{
		auto start = std::chrono::high_resolution_clock::now();

		std::string filename = "openid_100_w";
		std::ifstream istrm(filename.c_str(), std::ios::binary | std::ios::ate );
		size_t i = 0;
		uint64_t size = 0;

		if (!istrm.is_open()) {
			std::cout << "failed to open " << filename << '\n';
		}
		else
		{
			istrm.seekg(0, std::ios::end); // rewind

			size = istrm.tellg();

			istrm.seekg(0); // rewind

			Openid id[100];
			for (; i < size / sizeof(Openid)/100; ++i)
			{
				istrm.read(reinterpret_cast<char*>(&id), 100*sizeof(Openid));
			}
		}
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end - start;
		std::cout << "read block time " << diff.count() << "read size " << size << " readcount " << i << std::endl;
	}

}

//�����
//
#include "singleton.h"
#include "object_pool.h"
#include "object_pool_manager.h"

bool TestObjectPool()
{
	SINGLETON_CREATE_INIT(ObjectPool::ObjectPoolManager);
	std::vector<TransInfo*> v;
	for (auto i=0;i<100;++i)
	{
		v.emplace_back( NEW_MEMORY(TransInfo));
	}
	std::cout << ObjectPool::ObjectPoolManager::Instance()->Dump();
	for (auto & i : v)
	{
		DELETE_MEMORY(i);
	}
	v.clear();
	std::cout << ObjectPool::ObjectPoolManager::Instance()->Dump();


	SINGLETON_DESTORY_UNINIT(ObjectPool::ObjectPoolManager);
	return true;
}

void TestThreadMutex(uint32_t count)
{
	//�������
	std::mutex g_i_mutex;
	uint32_t index = 0;

	std::thread* thread_1 = new std::thread([&g_i_mutex, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				std::lock_guard<std::mutex> lock(g_i_mutex);
				//�����߼�Ϊ�������
				{
					std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
				}
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);
	std::thread* thread_2 = new std::thread([&g_i_mutex, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				std::lock_guard<std::mutex> lock(g_i_mutex);
				//�����߼�Ϊ�������
				{
					std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
				}
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);
	std::thread* thread_3 = new std::thread([&g_i_mutex, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				std::lock_guard<std::mutex> lock(g_i_mutex);
				//�����߼�Ϊ�������
				{
					std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
				}
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);
	thread_1->join();
	thread_2->join();
	thread_3->join();


}

void TestThreadNoLock(uint32_t count)
{
	bool lock=true;
	uint32_t index = 0;
	std::thread* thread_2 = new std::thread([&lock, &index, count]()
	{
		uint32_t local = index;
		try
		{
			uint32_t i = 0;
			for (; i < count; ++i)
			{
				if (!lock)
				{
					std::map<size_t, size_t> m_;
					for (size_t j = 0; j < 100; j++)
					{
						m_[j] = j;
					}

					if (local + 1 != index)
					{
						std::cout << "local + 1 != index  index [" << index << "]" <<"local["<<local <<"]"<< "[" << std::this_thread::get_id() << "]" << std::endl;

					}
					local = index;


					lock = true;
				}
				else
				{
					i--;
				}
			}
			std::cout << "thread 2 finish ;[" << i << "]" << std::endl;

		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);	std::thread* thread_1 = new std::thread([&lock, &index, count]()
	{
		try
		{
			uint32_t i = 0;
			for (; i < count; ++i)
			{
				if (lock)
				{
					index++;
					lock = false;
				}
				else
				{
					i--;
				}
			}
			std::cout << "thread 1 finish ;[" << i<<"]" << std::endl;
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);

	thread_1->join();
	thread_2->join();

}

void TestThreadLockFree(uint32_t count)
{
	EasySpinLock lock;
	uint32_t index = 0;
	std::thread* thread_1 = new std::thread([&lock, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				lock.Lock();
				std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
				lock.UnLock();
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);
	std::thread* thread_2 = new std::thread([&lock, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				lock.Lock();
				std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
				lock.UnLock();
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);
	std::thread* thread_3 = new std::thread([&lock, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				lock.Lock();
				std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
				lock.UnLock();
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);



	thread_1->join();
	thread_2->join();
	thread_3->join();

}


void TestThreadLockFreeTry(uint32_t count)
{
	EasySpinLock lock;
	uint32_t index=0;
	std::thread* thread_1 = new std::thread([&lock, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				if (lock.TryLock())
				{
					std::cout << "index [" << index++ << "]" << "[" <<   std::this_thread::get_id() << "]" << std::endl;
					lock.UnLock();
				}
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);
	std::thread* thread_2 = new std::thread([&lock, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				if (lock.TryLock())
				{
					std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
					lock.UnLock();
				}
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);
	std::thread* thread_3 = new std::thread([&lock, &index, count]()
	{
		try
		{
			for (uint32_t i = 0; i < count; ++i)
			{
				if (lock.TryLock())
				{
					std::cout << "index [" << index++ << "]" << "[" << std::this_thread::get_id() << "]" << std::endl;
					lock.UnLock();
				}
			}
		}
		catch (std::exception& e)
		{
			std::printf("Exception: %s\n", e.what());
		}
	}
	);



	thread_1->join();
	thread_2->join();
	thread_3->join();
}


#include "timer_wheel_manager.h"
bool TestTimerWheel(uint32_t c)
{
	SINGLETON_CREATE_INIT(ObjectPool::ObjectPoolManager);

    TimerWheelManager::CreateInstance();
    TimerWheelManager::Instance()->Init();

	//����
	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < 10000; i++)
	{
		auto cb = [i]()
		{
			//std::cout << "timer run i is [" << i << "]" << std::endl;
		};
		TimerWheelManager::Instance()->AddTimer(i, 3, cb);
	}
	//TimerWheelManager::Instance()->DebugDump();

	for (size_t i = 0; i < 10000 * 10000; i++)
	{
		TimerWheelManager::Instance()->Update(0);
		//TimerWheelManager::Instance()->DebugDump();
		TimerWheelManager::Instance()->DebugRandomTryKill();
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end - start;
	std::cout << std::endl << "total used time " << diff.count() <<" seconds total count "<< TimerWheelManager::Instance()->GetTotalcount()<< std::endl;

	TimerWheelManager::Instance()->Uninit();
	TimerWheelManager::DestroyInstance();
	SINGLETON_DESTORY_UNINIT(ObjectPool::ObjectPoolManager);
	return  true;

}

void TestNewTcmalloc(uint32_t c)
{
    uint64_t count = 0;
    //for (size_t i = 0; i < 0xfffff; i++)
    {
        //std::vector<B> v;
        //for (size_t i = 0; i < 300000; i++)
        //{
        //    v.emplace_back();

        //}


        //Openid* pter[0x10000];
        for (size_t j = 0; j < 15000; ++j)
        {
            count++;
            std::cout << "this new count "<<count<<std::endl;
            char * t  = new char[0x100000];
            t[1] = 1;
        }
        //for (size_t j = 0; j < 0x1ff; ++j)
        //{
        //    delete pter[j] ;
        //}
        std::chrono::seconds sec(10000);

        std::this_thread::sleep_for(sec);
    }
}

class AA
{
public:
	AA() {};
	virtual ~AA() 
	{
		std::cout << "~ AA" << std::endl;
	}
};


class BB:public AA
{

};

class CC : public BB
{

};

void TestVirtual()
{
	{
		std::cout << "new delete"<<std::endl;
		CC* c = new CC();
		delete c;
	}

	{
		std::cout << "malloc free " << std::endl;
		void* temp = malloc(sizeof(CC));
		CC* c = new(temp)CC();
		c->~CC();
		free((void *)c);
	}

}

// ���������
size_t Randomsize()
{
    //���鳤���ݶ�100����
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<uint32_t> dis(0, 100);
    static std::function<uint32_t()> dice = std::bind(dis, generator);
    return dice();
}

uint32_t Randomuint32()
{
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<uint32_t > dis(0, 0xff);
    static std::function<uint32_t()> dice = std::bind(dis, generator);
    return (uint32_t)((dice() << 24) + (dice() << 16) + (dice() << 8) + dice());
}

int32_t Randomint32()
{
    return (int32_t)Randomuint32();
}

uint64_t Randomuint64()
{
    return ((uint64_t)Randomuint32() << 32) + Randomuint32();
}
int64_t Randomint64()
{
    return (int64_t)Randomuint64();
}

bool Randombool()
{
    return (Randomuint32() % 2) == 0 ? false : true;
}
float Randomfloat()
{
    return (float)Randomint32() / 10000;
}
double Randomdouble()
{
    return (double)Randomint64() / 10000;
}

int32_t Randomsint32()
{
    return Randomint32();
}

std::string Randomstring()
{
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<uint32_t > dis(1, 0xff);
    static std::function<uint32_t()> dice = std::bind(dis, generator);

    uint32_t len = dice();
    std::string s = "";
    for (uint32_t i = 0; i < len; ++i)
    {
        s.push_back(dice());
    }
    return s;
}

void* Randombytes()
{
    //����0��ѡ��
    static int32_t temp[16];
    for (uint32_t i = 0; i < 16; ++i)
    {
        temp[i] = Randomint32();
    }
    return (void *)temp;
}

size_t GetRandomByteCount()
{
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<uint32_t> dis(1, 64);
    static std::function<uint32_t()> dice = std::bind(dis, generator);
    return dice();
}


void TestRandom()
{
    std::cout << "���� Randomsize" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomsize() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randomuint32" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomuint32() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randomint32" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomint32() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randomuint64" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomuint64() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randomint64" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomint64() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randombool" << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << Randombool() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randomfloat" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomfloat() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randomdouble" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomdouble() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randomstring" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randomstring() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� Randombytes" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << Randombytes() <<std::endl;
    }
    std::cout << std::endl;

    std::cout << "���� GetRandomByteCount" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << GetRandomByteCount() <<std::endl;
    }
    std::cout << std::endl;

}

int main(int argc, char* argv[])
{
	//TestObjectPool();
	//TestStdString();

	//����
	uint32_t count = 10;
	if (argc > 1)
	{
		count = atoi(argv[1]);
	}

	//TestWriteOpenid(count);
	//TestThreadNoLock(count);

    //HeapProfilerStart("heap.profile"); // ��Ӻ���֮һ
    //TestNewTcmalloc(count);
    //HeapProfilerStop();  // ��Ӻ���֮��

	//TestTimerWheel(count);
	//TestVirtual();

    TestRandom();


    //std::chrono::seconds sec(100);
 
    //std::this_thread::sleep_for(sec);



	return 0;
}
