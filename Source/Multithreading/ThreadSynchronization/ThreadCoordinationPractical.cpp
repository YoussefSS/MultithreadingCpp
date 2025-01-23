// Simulation of a program which performs a download
//
// One thread featches the data
// Another thread displays a progress bar
// A third thread processes the data when the download is complete
//
// Implemented using bools to communicate between the threads
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>

using namespace std::literals;

// Shared variable for the data being fetched
std::string sdata;

// Flags for thread communication
bool update_progress = false;
bool completed = false;

// Mutexes to protect the shared variables
std::mutex data_mutex; // for sdata
std::mutex completed_mutex; // for the completed flag
// We could have another mutex for the update_progress flag, but the fact is whenever we access it we are accessing sdata as well, so we use 1 mutex for both

// Data fetching thread - simulates fetching data and appending it
void fetch_data()
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "Fetcher thread waiting for data..." << std::endl;
		std::this_thread::sleep_for(2s);

		// Update sdata, then notify the progress bar thread
		std::lock_guard<std::mutex> data_lck(data_mutex);
		sdata += "Block" + std::to_string(i + 1);
		std::cout << "sdata: " << sdata << std::endl;
		// As mentioned above, we can set this flag as it's protected by the same mutex (data_mutex)
		update_progress = true;
	}

	std::cout << "Fetch sdata has ended\n";

	// Tell the progress bar thread to exit
	// and wake up the processing thread
	std::lock_guard<std::mutex> completed_lck(completed_mutex);
	completed = true;
}

// Progress bar thread
void progress_bar()
{
	size_t len = 0;

	while (true) {
		std::cout << "Progress bar thread waiting for data..." << std::endl;

		// Wait until there is some new data to display
		std::unique_lock<std::mutex> data_lck(data_mutex);
		while (!update_progress) {
			// Hot loop avoidance
			data_lck.unlock();
			std::this_thread::sleep_for(10ms);
			data_lck.lock();
		}

		// Wake up and use the new value
		// Made a copy of the string size, to minimize the amount of time we need the lock
		len = sdata.size();

		// Set the flag back to false
		update_progress = false;
		data_lck.unlock();

		std::cout << "Received " << len << " bytes so far" << std::endl;

		// Terminate when the download has finished
		std::lock_guard<std::mutex> completed_lck(completed_mutex);
		if (completed) {
			std::cout << "Progress bar thread has ended" << std::endl;
			break;
		}
	}
}

void process_data()
{
	std::cout << "Processing thread waiting for data..." << std::endl;

	// Wait until the download is complete
	std::unique_lock<std::mutex> completed_lck(completed_mutex);   // Acquire lock

	while (!completed) {
		completed_lck.unlock();
		std::this_thread::sleep_for(10ms);
		completed_lck.lock();
	}

	completed_lck.unlock();

	std::lock_guard<std::mutex> data_lck(data_mutex);
	std::cout << "Processing sdata: " << sdata << std::endl;

	// Process the data...
}

int main()
{
	// Start the threads
	std::thread fetcher(fetch_data);
	std::thread prog(progress_bar);
	std::thread processor(process_data);

	fetcher.join();
	prog.join();
	processor.join();
}