#include "ThreadPool.h"
#include <iostream>
#include <mutex>

using namespace std;

mutex coutmutex;

void task() {
	lock_guard<mutex> lg(coutmutex);
	cout << "Thread id: " << this_thread::get_id() << " started" << endl;
	this_thread::sleep_for(100ms);
	cout << "Thread id: " << this_thread::get_id() << " finished" << endl;
}

int main() {
	cout << "Creating a thread pool with " << thread::hardware_concurrency() << " threads" << endl;
	thread_pool pool;

	for (int i = 0; i < 50; ++i)
		pool.submit(task);

	this_thread::sleep_for(5s);
}