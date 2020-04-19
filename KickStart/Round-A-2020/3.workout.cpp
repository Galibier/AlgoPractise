#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool is_sussess(vector<long long>& times, long long target, long long k) {
  long long cur = 0;
  for (int i = 1; i < times.size(); ++i) {
    long long cur_diff = llabs(times[i] - times[i - 1]);
    if (cur_diff > target) {
      cur += cur_diff / target;
      if (cur_diff % target == 0) {
        cur--;
      }
    }
    if (cur > k) return false;
  }
  return true;
}

int main() {
  int cases = 0;
  cin >> cases;
  for (int t = 0; t < cases; ++t) {
    long long n, k;
    cin >> n >> k;

    vector<long long> times(n, 0);
    long long max_diff = 0;
    for (int i = 0; i < n; ++i) {
      cin >> times[i];
      if (i == 0) continue;
      max_diff = max(max_diff, llabs(times[i] - times[i - 1]));
    }
    long long l = 1, r = max_diff;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (is_sussess(times, mid, k)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << "Case #" << t + 1 << ": " << l << endl;
  }
  return 0;
}