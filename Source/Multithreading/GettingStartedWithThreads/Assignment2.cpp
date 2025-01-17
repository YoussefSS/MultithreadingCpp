/*
 *Write a function that increments a global int variable 100,000 times in a for loop.
 *Write a program that starts concurrent threads which use this as their task function. When all the threads have completed execution, print out the final value of the counter.
 *Increase the number of threads until you see anomalous results.
*/

#include <iostream>
#include <thread>

int globalInt = 0;

void Increment100000Times()
{
	for(int i = 0; i<100000; i++)
	{
		globalInt++;
	}
}

int main()
{
	std::thread t1(Increment100000Times);
	std::thread t2(Increment100000Times);
	std::thread t3(Increment100000Times);

	t1.join();
	t2.join();
	t3.join();

	std::cout << "Int value = " << globalInt;
}