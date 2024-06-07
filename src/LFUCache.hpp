#ifndef LFUCACHE_HPP
#define LFUCACHE_HPP

#include <iostream>
#include <unordered_map>
#include <list>
#include <stdexcept>

struct CacheNode; // Forward declaration

template <typename KeyType, typename ValueType>
class LFUCache {
	public:
		struct CacheNode {
			KeyType key;
			ValueType value;
			size_t frequency;
			typename std::list<CacheNode>::iterator it;

			CacheNode() = default;
			CacheNode(const KeyType& k, const ValueType& v, size_t f, typename std::list<CacheNode>::iterator i)
				: key(k), value(v), frequency(f), it(i) {}
		};

	private:

		std::unordered_map<KeyType, CacheNode> cacheMap;
		std::unordered_map<size_t, std::list<CacheNode>> frequencyMap;
		size_t capacity;

	public:
		LFUCache(size_t capacity) : capacity(capacity) {}

		void put(const KeyType& key, const ValueType& value) {
			if (capacity == 0) return;

			auto it = cacheMap.find(key);
			if (it != cacheMap.end()) {
				// Update existing node's value and frequency
				it->second.value = value;
				increaseFrequency(it->second);
			} else {
				// Create a new node
				if (cacheMap.size() == capacity) {
					evictLFU();
				}
				CacheNode newNode {key, value, 1, frequencyMap[1].begin()};
				cacheMap[key] = newNode;
				frequencyMap[1].push_front(newNode);
			}
		}

		ValueType get(const KeyType& key) {
			auto it = cacheMap.find(key);
			if (it == cacheMap.end()) {
				throw std::out_of_range("Key not found in cache");
			}
			increaseFrequency(it->second);
			return it->second.value;
		}

	private:
		void increaseFrequency(CacheNode& node) {
			size_t oldFreq = node.frequency;
			auto& freqList = frequencyMap[oldFreq];
			freqList.erase(node.it);

			if (freqList.empty()) {
				frequencyMap.erase(oldFreq);
			}

			node.frequency++;
			frequencyMap[node.frequency].push_front(node);
			node.it = frequencyMap[node.frequency].begin();
		}

		void evictLFU() {
			auto& lfuList = frequencyMap.begin()->second;
			auto lfuIter = lfuList.back();
			cacheMap.erase(lfuIter.key);
			lfuList.pop_back();

			if (lfuList.empty()) {
				frequencyMap.erase(1); // Remove empty list
			}
		}
};

#endif // LFUCACHE_HPP
