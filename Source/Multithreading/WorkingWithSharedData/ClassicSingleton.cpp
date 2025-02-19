// Classic Singleton class implementation
#include "ClassicSingleton.h"

// Static member function to obtain the Singleton object
Singleton* Singleton::get_Singleton()
{
    if (single == nullptr)
        single = new Singleton;
    return single;
}

// Test program for classic Singleton
#include <thread>
#include <vector>

Singleton* Singleton::single = nullptr;

//void task()
//{
//	Singleton* single = Singleton::get_Singleton();
//	std::cout << single << std::endl;
//}
//
//int main()
//{
//	std::vector<std::thread> threads;
//
//	for (int i = 0; i < 10; ++i)
//		threads.push_back(std::thread(task));
//
//	for (auto& thr : threads)
//		thr.join();
//}