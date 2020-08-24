#include <iostream>
#include <vector>
using namespace std;

class Solution {
 private:
  void merge(vector<int>& nums, int start, int mid, int end) {
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) left[i] = nums[start + i];
    for (int j = 0; j < n2; j++) right[j] = nums[mid + 1 + j];
    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
      if (j >= n2 || (i < n1 && left[i] <= right[j])) {
        nums[k] = left[i++];
      } else {
        nums[k] = right[j++];
      }
    }
  }

  int mergesort_and_count(vector<int>& nums, int start, int end) {
    if (start < end) {
      int mid = (start + end) / 2;
      int count = mergesort_and_count(nums, start, mid) +
                  mergesort_and_count(nums, mid + 1, end);
      int j = mid + 1;
      for (int i = start; i <= mid; i++) {
        while (j <= end && nums[i] > nums[j] * 2LL) j++;
        count += j - (mid + 1);
      }
      merge(nums, start, mid, end);
      return count;
    } else {
      return 0;
    }
  }

 public:
  int reversePairs(vector<int>& nums) {
    return mergesort_and_count(nums, 0, nums.size() - 1);
  }
};

int main() {
  Solution sol;
  return 0;
}