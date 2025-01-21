// Singleton class implementation (Meyers Singleton)
// Uses C++11's guarantees about initializing static variables
#include "ThreadSafeSingleton.h"

// Function to obtain the Singleton object
Singleton& get_Singleton()
{
	// Initialized by the first thread that executes this code
	static Singleton single;
	return single;
}

// Test program for Meyers Singleton
#include <thread>
#include <vector>

void task()
{
	Singleton& single = get_Singleton();
	std::cout << &single << std::endl;
}

int main()
{
	std::vector<std::thread> threads;

	for (int i = 0; i < 10; ++i)
		threads.push_back(std::thread(task));

	for (auto& thr : threads)
		thr.join();
}