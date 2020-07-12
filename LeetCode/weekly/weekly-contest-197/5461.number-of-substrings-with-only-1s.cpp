#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numSub(string s) {
    int len = s.size();
    if (len == 0) return 0;
    long res = 0;
    long pos = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '1') {
        pos = i;
        while (s[pos] == '1') pos++;
        res = (res + calcu(pos - i + 1)) % mod;
        i = pos - 1;
      }
    }
    res = res % mod;
    return res;
  }

 private:
  constexpr int calcu(long long n) {
    return static_cast<int>(n * (n - 1) / 2 % mod);
  }
  constexpr static int mod = 1000000007;
};

int main() {
  Solution sol = Solution();
  return 0;
}