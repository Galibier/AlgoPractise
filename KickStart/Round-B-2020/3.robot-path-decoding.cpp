#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int inf = 1000000000;

struct Point {
  long long cnt;
  long long x;
  long long y;
  Point() : cnt(0), x(0), y(0) {}
};

stack<Point> st;

int main() {
  long long cases;
  cin >> cases;
  for (int k = 0; k < cases; k++) {
    string input;
    cin >> input;

    long long x = 0, y = 0;
    for (int i = 0; i < input.size(); i++) {
      if (isdigit(input[i])) {
        Point t;
        t.cnt = (long long)(input[i] - '0');
        i++;
        t.x = x;
        t.y = y;
        st.push(t);
        continue;
      }
      switch (input[i]) {
        case 'N':
          y--;
          break;
        case 'S':
          y++;
          break;
        case 'E':
          x++;
          break;
        case 'W':
          x--;
          break;
        case ')':
          Point t = st.top();
          st.pop();
          x += (t.cnt - 1) * (x - t.x);
          x %= inf;
          y += (t.cnt - 1) * (y - t.y);
          y %= inf;
      }
    }
    x = (x + inf) % inf;
    y = (y + inf) % inf;

    cout << "case #" << k + 1 << ": " << x + 1 << " " << y + 1 << endl;
  }

  return 0;
}
