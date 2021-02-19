#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class AllOne {
 public:
  /** Initialize your data structure here. */
  AllOne() {}

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1.
   */
  void inc(string key) {
    if (mp.count(key) == 0) {
      lst.push_back(make_pair(key, 1));
      mp[key] = prev(lst.end());
      return;
    }
    auto it = mp[key];
    ++(it->second);
    auto pit = prev(it);
    while (it != lst.begin() && it->second > pit->second) {
      iter_swap(it, pit);
      mp[it->first] = it;
      mp[pit->first] = pit;
      pit = prev(pit);
      it = prev(it);
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the
   * data structure. */
  void dec(string key) {
    if (mp.count(key) == 0) {
      return;
    }
    auto it = mp[key];
    --(it->second);
    if (it->second == 0) {
      lst.erase(it);
      mp.erase(key);
      return;
    }
    auto nit = next(it);
    while (nit != lst.end() && nit->second > it->second) {
      iter_swap(it, nit);
      mp[it->first] = it;
      mp[nit->first] = nit;
      nit = next(nit);
      it = next(it);
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    if (lst.empty()) {
      return std::string();
    }
    return lst.begin()->first;
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    if (lst.empty()) {
      return "";
    }
    return prev(lst.end())->first;
  }

 private:
  list<pair<string, int>> lst;
  unordered_map<string, list<pair<string, int>>::iterator> mp;
};

int main() {
  AllOne* obj = new AllOne();
  obj->inc("key1");
  obj->dec("key1");
  string param_3 = obj->getMaxKey();
  string param_4 = obj->getMinKey();
  return 0;
}