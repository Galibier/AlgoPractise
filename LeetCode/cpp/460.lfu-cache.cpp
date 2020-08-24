#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

struct Node {
  int cnt;
  int time;
  int key;
  int value;
  Node(int _cnt, int _time, int _key, int _value)
      : cnt(_cnt), time(_time), key(_key), value(_value) {}

  bool operator<(const Node& rhs) const {
    return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
  }
};

class LFUCache {
  int capacity, time;
  unordered_map<int, Node> key_table;
  set<Node> nodes;

 public:
  LFUCache(int _capacity) {
    capacity = _capacity;
    time = 0;
    key_table.clear();
    nodes.clear();
  }

  int get(int key) {
    if (capacity == 0) return -1;
    auto it = key_table.find(key);
    if (it == key_table.end()) return -1;

    Node cache = it->second;
    nodes.erase(cache);
    cache.cnt += 1;
    cache.time = ++time;
    nodes.insert(cache);
    it->second = cache;
    return cache.value;
  }

  void put(int key, int value) {
    if (capacity == 0) return;
    auto it = key_table.find(key);
    if (it == key_table.end()) {
      if (key_table.size() == capacity) {
        key_table.erase(nodes.begin()->key);
        nodes.erase(nodes.begin());
      }
      Node cache = Node(1, ++time, key, value);
      key_table.insert(make_pair(key, cache));
      nodes.insert(cache);
    } else {
      Node cache = it->second;
      nodes.erase(cache);
      cache.cnt += 1;
      cache.time = ++time;
      cache.value = value;
      nodes.insert(cache);
      it->second = cache;
    }
  }
};

int main() {
  LFUCache cache(2);  // capacity (缓存容量)

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;  // 返回 1
  cache.put(3, 3);               // 去除 key 2
  cout << cache.get(2) << endl;  // 返回 -1 (未找到key 2)
  cout << cache.get(3) << endl;  // 返回 3
  cache.put(4, 4);               // 去除 key 1
  cout << cache.get(1) << endl;  // 返回 -1 (未找到 key 1)
  cout << cache.get(3) << endl;  // 返回 3
  cout << cache.get(4) << endl;  // 返回 4
  return 0;
}