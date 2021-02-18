#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
 public:
  int pos;
  int top;
  string history[5001];
  BrowserHistory(string homepage) : pos(-1), top(0) { visit(homepage); }

  void visit(string url) {
    pos++;
    top = pos;
    history[top++] = url;
  }

  string back(int steps) {
    if (steps > pos) {
      steps = pos;
    }
    pos -= steps;
    return history[pos];
  }

  string forward(int steps) {
    steps = min(steps, top - pos - 1);
    pos += steps;
    return history[pos];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
  BrowserHistory browserHistory = BrowserHistory("leetcode.com");
  browserHistory.visit("google.com");
  browserHistory.visit("facebook.com");
  browserHistory.visit("youtube.com");
  browserHistory.back(1);
  browserHistory.back(1);
  browserHistory.forward(1);
  browserHistory.visit("linkedin.com");
  browserHistory.forward(2);
  browserHistory.back(2);
  browserHistory.back(7);
  return 0;
}