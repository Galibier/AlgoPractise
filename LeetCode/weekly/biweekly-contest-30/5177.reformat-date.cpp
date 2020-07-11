#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string reformatDate(string date) {
    stringstream in(date);
    string day, mon, year, ret;
    in >> day >> mon >> year;
    ret += year + "-";
    for (int i = 0; i < month.size(); i++) {
      if (mon == month[i]) {
        if (i < 9) ret += "0";
        ret += to_string(i + 1) + "-";
      }
    }
    if (day.size() == 3) {
      ret += "0";
    }
    for (int i = 0; isdigit(day[i]); i++) {
      ret += date[i];
    }
    return ret;
  }

 private:
  const vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
};

int main() {
  Solution sol = Solution();
  cout << sol.reformatDate("6th Jun 1933") << endl;
  return 0;
}