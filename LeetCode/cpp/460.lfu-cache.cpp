#include <iostream>
using namespace std;

class LFUCache {
 public:
  LFUCache(int capacity) {}

  int get(int key) {}

  void put(int key, int value) {}
};

int main() {
  LFUCache cache = new LFUCache(2);  // capacity (缓存容量)

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