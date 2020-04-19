#include <iostream>
#include <vector>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int k = 0; k < cases; k++) {
    int n;
    cin >> n;
    vector<int> checkpoints(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> checkpoints[i];
    }

    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
      if (checkpoints[i - 1] < checkpoints[i] and
          checkpoints[i + 1] < checkpoints[i]) {
        cnt++;
      }
    }

    cout << "case #" << k + 1 << ": " << cnt << endl;
  }
  return 0;
}