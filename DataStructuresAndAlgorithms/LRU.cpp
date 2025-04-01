#include <chrono>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;
class LRUCache {
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>>
        hash; // key-> value,iterator
    list<int> lru;

  public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto hash_elem = hash.find(key);
        if (hash_elem != hash.end()) {
            // fetch iterator for the key.
            auto list_itr = hash_elem->second.second;
            // update recency by movingss element to the begining.
            lru.splice(lru.begin(), lru, list_itr);
            return hash_elem->second.first; // return value
        }
        return -1;
    }

    void put(int key, int value) {
        auto hash_index = hash.find(key);
        if (hash_index != hash.end()) {
            auto list_itr = hash_index->second.second;
            // update recency.
            lru.splice(lru.begin(), lru, list_itr);
            if (hash_index->second.first != value) {
                // update the map with new value.
                // lets update both value and the iterator, though the iterator
                // will not be invalidated by splice
                hash[key] = {pair(value, lru.begin())};
            }

        } else {
            if (capacity == hash.size()) {
                // evict last element(i.e with least priority)
                hash.erase(lru.back());
                lru.pop_back();
            }
            // add to list and then to map
            lru.push_front(key);
            hash.insert({key, pair(value, lru.begin())});
        }
    }
    void print() {
        cout << "{ ";
        for (auto i : lru) {
            cout << i << "=" << hash.at(i).first << " ";
        }
        cout << "}" << endl;
    }
};

int main() {
    LRUCache cache(2); // Capacity = 2
    cache.put(1, 1);   // Cache is {1=1}
    printf("cache.put(1, 1)\t"), cache.print();
    cache.put(2, 2); // Cache is { 2=2 1=1 }
    printf("cache.put(2, 2)\t"), cache.print();
    cache.get(1); // Returns 1, cache is { 1=1 2=2 } (1 is now recent)
    printf("cache.get(1)\t"), cache.print();
    cache.put(3, 3); // Cache full, evicts 2, adds 3, cache is { 3=3 1=1 }
    printf("cache.put(3, 3)\t"), cache.print();
    cache.get(2); // Returns -1 (not found), cache is { 3=3 1=1 }
    printf("cache.get(2)\t"), cache.print();
    cache.put(1, 4); // Updates 1, cache is { 1=4 3=3 }
    printf("cache.put(1, 4)\t"), cache.print();
}