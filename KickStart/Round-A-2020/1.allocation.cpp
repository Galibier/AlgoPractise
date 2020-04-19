#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; ++i) {
    int n, b;
    cin >> n >> b;
    vector<int> costs(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> costs[i];
    }
    sort(costs.begin(), costs.end());
    int res = 0, cur = 0;
    for (auto cost : costs) {
      cur += cost;
      if (cur > b) break;
      res++;
    }
    cout << "Case #" << i + 1 << ": " << res << endl;
  }
  return 0;
}