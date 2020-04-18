#include <iostream>
#include <vector>
using namespace std;

int findMinFibonacciNumbers(int k) {
  vector<int> fib;
  int fib1 = 1, fib2 = 1, fib3 = 0;
  while (fib3 < k) {
    fib3 = fib1 + fib2;
    fib.push_back(fib3);
    fib1 = fib2;
    fib2 = fib3;
  }

  int cnt = 0;
  for (int i = fib.size() - 1; i >= 0; i--) {
    if (k - fib[i] >= 0) {
      k -= fib[i];
      cnt++;
    }
  }
  if (k == 1) cnt += 1;

  return cnt;
}

int main() {
  for (int i = 0; i < 100; i++) {
    cout << i << " " << findMinFibonacciNumbers(i) << endl;
  }
  return 0;
}