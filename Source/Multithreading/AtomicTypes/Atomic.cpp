// A shared variable is modified by multiple threads
// Use an "atomic" variable to prevent a data race
#include <thread>
#include <iostream>
#include <vector>
#include <atomic>
#include <mutex>

std::atomic<int> counter = 0;
//int counter = 0;
//std::mutex mtx;

void task()
{
    for (int i = 0; i < 10000000; ++i)
        ++counter;

    // Much slower
 /*   for (int i = 0; i < 10000000; ++i)
    {
        std::lock_guard<std::mutex> lck(mtx);
        counter++;
    }*/
}

int main()
{
    std::vector<std::thread> tasks;

    std::cout << counter << "Starting \n";

    for (int i = 0; i < 10; ++i)
        tasks.push_back(std::thread(task));

    for (auto& thr : tasks)
        thr.join();

    std::cout << counter << '\n';
}
