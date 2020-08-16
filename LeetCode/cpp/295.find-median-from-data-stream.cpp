#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
  priority_queue<int> lo;
  priority_queue<int, vector<int>, greater<int>> hi;

 public:
  void addNum(int num) {
    lo.push(num);

    hi.push(lo.top());
    lo.pop();

    if (lo.size() < hi.size()) {
      lo.push(hi.top());
      hi.pop();
    }
  }

  double findMedian() {
    return lo.size() > hi.size() ? static_cast<double>(lo.top())
                                 : (lo.top() + hi.top()) * 0.5;
  }
};

int main() {
  MedianFinder* obj = new MedianFinder();
  obj->addNum(1);
  obj->addNum(2);
  obj->findMedian();
  obj->addNum(3);
  obj->findMedian();
  return 0;
}