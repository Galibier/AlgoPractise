#include <iostream>
#include <vector>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int k = 0; k < cases; k++) {
    long long n, d;
    cin >> n >> d;
    vector<long long> bus_routes(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> bus_routes[i];
    }

    long long mod = d % bus_routes[n - 1];
    bus_routes[n - 1] = d - mod;
    for (int i = n - 2; i >= 0; i--) {
      long long mod1 = d % bus_routes[i];
      long long mod2 = bus_routes[i + 1] % bus_routes[i];
      bus_routes[i] = min(d - mod1, bus_routes[i + 1] - mod2);
    }

    long long ans = d + 1;
    for (int i = 0; i < n; i++) {
      ans = min(ans, bus_routes[i]);
    }

    cout << "case #" << k + 1 << ": " << ans << endl;
  }
  return 0;
}