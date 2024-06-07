#include "LFUCache.hpp" 
#include <iostream>

int main() {
	// Create an LFU cache with capacity 3
	LFUCache<int, std::string> cache(3);

	// Put some key-value pairs in the cache
	cache.put(1, "apple");
	cache.put(2, "banana");
	cache.put(3, "cherry");

	// Get a value from the cache
	try {
		std::string value = cache.get(2);
		std::cout << "Retrieved value for key 2: " << value << std::endl;
	} catch (const std::out_of_range& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Put another key-value pair (might evict least frequently used item)
	cache.put(4, "date");

	// Try to get a non-existent key (throws exception)
	try {
		cache.get(5);
	} catch (const std::out_of_range& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
