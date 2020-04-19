#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
const int bound = 1000000000;
int index = 0;

vector<int> op(string str) {
  vector<int> ret = {0, 0, 0, 0};
  for (index; index < str.size(); index++) {
    if (isdigit(str[index])) {
      int cnt = 0;
      while (isdigit(str[index])) {
        cnt = cnt * 10 + int(str[index] - '0');
        index++;
      }
      index++;
      auto res = op(str);
      for (int j = 0; j < 4; j++) {
        ret[j] += res[j] * cnt;
      }
      continue;
    }
    switch (str[index]) {
      case 'N':
        ret[0]++;
        break;
      case 'S':
        ret[1]++;
        break;
      case 'E':
        ret[2]++;
        break;
      case 'W':
        ret[3]++;
        break;
      case ')':
        return ret;
    }
  }
  return ret;
}

int main() {
  int cases;
  cin >> cases;
  for (int k = 0; k < cases; k++) {
    string input;
    cin >> input;

    index = 0;
    auto ans = op(input);
    int south = (ans[1] - ans[0] + 1);
    int east = (ans[2] - ans[3] + 1);
    if (south < 1) south += bound;
    if (east < 1) east += bound;

    cout << "case #" << k + 1 << ": " << east << " " << south << endl;
  }

  return 0;
}