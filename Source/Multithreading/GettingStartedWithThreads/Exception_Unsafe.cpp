// What happens to an std::thread object
// when an exception is thrown?
#include <thread>
#include <iostream>

//// Callable object - thread entry point
//void hello()
//{
//	std::cout << "Hello, Thread!\n";
//}
//
//int main()
//{
//	try {
//		// Create an std::thread object
//		std::thread thr(hello);
//
//		// Code that might throw an exception
//		throw std::exception();
//
//		// The program will abort as the exception was thrown before join was called, so the destructor of the thread object will be called
//		thr.join();
//	}
//	catch (std::exception& e) {
//		std::cout << "Exception caught: " << e.what() << '\n';
//	}
//}