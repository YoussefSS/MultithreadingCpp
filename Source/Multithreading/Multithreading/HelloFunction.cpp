#include <iostream>
#include <thread>

// Callable object, thread entry point
void hello() {
    std::cout << "Hello, Thread!";
}

/*
// Application aborts, check notes for lec 14
int main() {
    // Create an std::thread object, pass in the entry point function to the constructor
    std::thread thr(hello);
}
*/

/*
Callig join() so the app no longer aborts
int main() {
    // Create an std::thread object, pass in the entry point function to the constructor
    std::thread thr(hello);

    // Wait for the thread to complete
    // Will prevent std::terminate from being called, which aborts our program
    thr.join();
}
*/