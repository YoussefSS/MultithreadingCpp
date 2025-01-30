//// Conflicting operations on STL containers are not safe
//// They must be synchronized
//#include <thread>
//#include <iostream>
//#include <mutex>
//#include <vector>
//
//// Shared vector
//std::vector<int> vec;
//
//// Mutex to protect std::vector's data
//std::mutex mut;
//
///* We have 2 threads pushing elements to the same array, you would think that that's not a problem,
// * but when an array is full, a new one is usually created at a much bigger size in a different location
// * and the old items moved from the old to the new, and that old memory is no longer available to the program.
// * So if we get a thread that releases a block of memory, and another thread that is trying to push to that block of memory, the program crashes 
// */
//
//void func1()
//{
//	// Potentially conflicting access - must be protected
//	//std::lock_guard<std::mutex> lgd(mut);
//	for (int i = 0; i < 100000; ++i)
//		vec.push_back(i);
//}
//
//void func2()
//{
//	// Potentially conflicting access - must be protected
//	//std::lock_guard<std::mutex> lgd(mut);
//	for (int i = 100000; i < 200000; ++i)
//		vec.push_back(i);
//}
//
//int main()
//{
//	std::thread thr1(func1);
//	std::thread thr2(func2);
//
//	thr1.join();
//	thr2.join();
//
//	std::cout << "shptr data: ";
//	for (int i = 0; i < 200000; ++i)
//		std::cout << vec[i] << ", ";
//
//	std::cout << "Finished\n";
//}