/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (28.46%)
 * Likes:    5741
 * Dislikes: 257
 * Total Accepted:    548.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 */

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// @lc code=start
class LRUCache {
    list<int> l;  // store key in the order of recently used
    unordered_map<int, pair<int, list<int>::iterator>> m;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        touch(key);
        return m[key].first;
    }

    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            l.push_front(key);
            while (l.size() > capacity) {
                m.erase(l.back());
                l.pop_back();
            }
        } else {
            touch(key);
        }
        m[key] = {value, l.begin()};
    }

    // move key to the front of the list
    void touch(int key) {
        l.splice(l.begin(), l, m[key].second);
        m[key].second = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache cache(1);

    cache.put(2, 1);
    cout << cache.get(2);
}