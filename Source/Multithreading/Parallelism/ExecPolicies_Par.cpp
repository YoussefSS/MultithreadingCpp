// Example of parallel execution policy with data race
// Requires C++17 compiler
#include <algorithm>
#include <vector>
#include <iostream>
#include <execution>

namespace se = std::execution;

int main() {
	std::vector<int> vec(20'000);

	// To fix the data race, use an atomic int or mutex
	int count = 0;

	std::for_each(se::par, vec.begin(), vec.end(),
		[&count](int& x) { x = ++count; }
	);

	std::sort(vec.begin(), vec.end());

	for (auto i : vec)
		std::cout << i << ',';
	std::cout << '\n';
}