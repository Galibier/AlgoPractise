#include <iostream>
#include <string>
using namespace std;

// TLE
class SolutionTLE {
 public:
  string minInteger(string num, int k) {
    if (k > num.size() * (num.size() - 1) / 2) {  //先排除特殊情况
      sort(num.begin(), num.end());
      return num;
    }
    if (k <= 0) return num;

    int a;
    char min;
    int j;
    for (int i = 0; i < num.size(); i++) {
      min = num[i];
      a = i;

      for (j = i; j < num.size() && j < i + k + 1; j++) {
        if (num[j] < min) {
          min = num[j];
          a = j;
        }
      }
      for (int t = a; t > i; t--) {
        if (k > 0) {
          char c;
          c = num[t];
          num[t] = num[t - 1];
          num[t - 1] = c;
          k--;
        }

        else
          return num;
      }
    }
    return num;
  }
};

struct BIT {
  vector<int> c;
  BIT(int n) { c.resize(n + 1); }
  void set(int x, int val) {
    for (; x < c.size(); x += x & -x) c[x] += val;
  }

  int get(int x) {
    int ret = 0;
    for (; x; x -= x & -x) ret += c[x];
    return ret;
  }
};

class Solution {
 public:
  string minInteger(string num, int k) {
    int n = num.length();

    vector<deque<int>> p(10);

    BIT bit(n);

    for (int i = 0; i < n; ++i) {
      p[num[i] - '0'].push_back(i + 1);
    }
    vector<bool> use(n + 1);

    vector<char> prefix;

    for (int i = 0; i < n && k; ++i) {
      for (int i = 0; i < 10; ++i)
        if (p[i].size()) {
          int idx = p[i].front();
          int step = idx - 1 - bit.get(idx);
          if (step <= k) {
            k -= step;
            prefix.push_back('0' + i);
            use[idx] = true;
            bit.set(idx, 1);
            p[i].pop_front();
            break;
          }
        }
    }

    string ans;
    for (char c : prefix) ans += c;
    for (int i = 1; i <= n; ++i)
      if (!use[i]) ans += num[i - 1];
    return ans;
  }
};

// 作者：dut200901102
// 链接：https://leetcode-cn.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/solution/tan-xin-shu-zhuang-shu-zu-by-dut200901102/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
  Solution sol = Solution();
  return 0;
}