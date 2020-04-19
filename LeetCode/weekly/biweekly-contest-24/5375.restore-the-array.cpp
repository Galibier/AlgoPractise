class Solution {
 public:
  int numberOfArrays(string s, int k) {
    int mo = 1000000007;
    int n = s.size();
    vector<int> f(n + 5, 0);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
      f[i + 1] = 0;
      long long now = 0, base = 1;
      for (int j = i; j >= 0 && j >= i - 15; j--) {
        now += base * (s[j] - '0');
        base *= 10;
        if (now > k) {
          break;
        }
        if (s[j] != '0') {
          (f[i + 1] += f[j]) %= mo;
        }
      }
    }
    return f[n];
  }
};