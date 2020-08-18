#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class RandomizedCollection {
 public:
  /** Initialize your data structure here. */
  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    recs.push_back(val);
    bool res = ump.find(val) == ump.end();

    int index = recs.size() - 1;
    ump[val].insert(index);

    return res;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    bool res = ump.find(val) != ump.end() && ump[val].size() > 0;
    if (!res) {
      return res;
    }

    int lastindex = recs.size() - 1;
    int lastVal = recs.back();

    int deleteIndex = *ump[val].begin();
    ump[val].erase(ump[val].begin());
    if (ump[val].size() == 0) {
      ump.erase(val);
    }

    if (deleteIndex != lastindex) {
      ump[lastVal].erase(lastindex);
      ump[lastVal].insert(deleteIndex);
      recs[deleteIndex] = lastVal;
    }
    recs.pop_back();

    return res;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    if (recs.size() == 0) return -1;
    int index = rand() % recs.size();
    return recs[index];
  }

 private:
  unordered_map<int, unordered_set<int> > ump;
  vector<int> recs;
};

int main() {
  // 初始化一个空的集合。
  RandomizedCollection collection;
  // 向集合中插入 1 。返回 true 表示集合不包含 1 。
  cout << collection.insert(1) << endl;
  // 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
  cout << collection.insert(1) << endl;
  // 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
  cout << collection.insert(2) << endl;
  // getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
  cout << collection.getRandom() << endl;
  // 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
  cout << collection.remove(1) << endl;
  // getRandom 应有相同概率返回 1 和 2 。
  cout << collection.getRandom() << endl;
  return 0;
}