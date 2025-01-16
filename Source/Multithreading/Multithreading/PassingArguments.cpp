#include <string>
#include <thread>
#include <iostream>

// Example of passing an argument to a thread function

// Callable object - thread entry point
//void hello(std::string str) {
//	std::cout << str << '\n';
//}

//int main() {
//	// hello() takes a string argument
//	std::thread thr(hello, "Hello, Thread!");
//
//	thr.join();
//}

// ============================================================================================ /

// Example of passing arguments to a thread function by move
#include <iostream>
#include <thread>


// Thread entry point
// Requires an rvalue argument
void func(std::string&& str) {
	std::cout << "Ownership of \"" << str << "\" transferred to thread" << '\n';
}

//int main() {
//	std::string str = "moveable";
//	std::cout << "Starting thread" << '\n';
//
//	// Wrap str in a call to std::move()
//	std::thread thr(func, std::move(str));
//	thr.join();
//
//	// Verify that str has been modified
//	std::cout << "Do I still have any data?" << ' ';
//	std::cout << (str.empty() ? "No" : "Yes") << ".\n";
//}

// ============================================================================================ /

// Example of passing arguments to a thread function by reference

// Thread entry point
void hello(std::string& s) {
	s = "xyz";
}

//int main() {
//	std::string str = "abc";
//
//	// Wrap argument in a call to std::ref()
//	std::thread thr(hello, std::ref(str));
//	thr.join();
//
//	// Verify that it has been modified
//	std::cout << "str is now " << str << '\n';
//}

// ============================================================================================ /

// Example of using a member function as a thread's entry point

// Class whose member function
// will be used as the thread's entry point
class greeter {
public:
	void hello() {
		std::cout << "Hello, Member Function Thread!\n";
	}
};

//int main() {
//	// Create an object of the class
//	greeter greet;
//
//	// Create an std::thread object
//	// Pass a pointer to the member function
//	// and a pointer to the object to call it on
//	std::thread thr(&greeter::hello, &greet);
//
//	thr.join();
//}

// ============================================================================================ /

// Example of using a lambda expression as a thread's entry point
// The lambda takes arguments
//
//int main() {
//	// Use a lambda expression as the thread's entry point
//	std::thread thr(
//		// The first argument is the lambda expression 
//		[](int i1, int i2) {
//			std::cout << "The sum of " << i1 << " and " << i2 << " is "
//				<< i1 + i2 << '\n';
//		},
//
//		// The remaining arguments are passed to the lambda expression
//			2, 3
//			);
//
//	thr.join();
//}