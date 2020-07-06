#include <algorithm>
using namespace std;

class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int overlap_area = 0;
    if (!(E >= C || G <= A || F >= D || H <= B)) {
      int x1 = max(A, E);
      int x2 = min(C, G);
      int y1 = max(B, F);
      int y2 = min(D, H);

      overlap_area = (x2 - x1) * (y2 - y1);
    }
    int area_1 = (C - A) * (D - B);
    int area_2 = (G - E) * (H - F);
    return area_1 + (area_2 - overlap_area);
  }
};

int main() {
  Solution sol = Solution();
  return 0;
}