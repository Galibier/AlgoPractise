#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<string>> ret;
    map<int, map<string, int>> mp;
    set<string> dishes;
    for (auto order : orders) {
      mp[atoi(order[1].c_str())][order[2]]++;
      dishes.insert(order[2]);
    }

    vector<string> first_line = {"Table"};
    for (auto str : dishes) first_line.push_back(str);
    ret.push_back(first_line);
    for (auto table : mp) {
      vector<string> line{to_string(table.first)};
      for (int i = 1; i < first_line.size(); i++) {
        if (table.second.find(first_line[i]) != table.second.end())
          line.push_back(to_string(table.second[first_line[i]]));
        else
          line.push_back("0");
      }
      ret.push_back(line);
    }
    return ret;
  }
};

int main() {
  vector<vector<string>> orders{
      {"David", "3", "Ceviche"},       {"Corina", "10", "Beef Burrito"},
      {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"},
      {"Carla", "5", "Ceviche"},       {"Rous", "3", "Ceviche"}};
  Solution sol = Solution();
  auto ret = sol.displayTable(orders);
  for (auto line : ret) {
    for (auto str : line) {
      cout << str << ", ";
    }
    cout << endl;
  }
  return 0;
}