class Solution {
 public:
  int expectNumber(vector<int>& scores) {
    set<int> st(scores.begin(), scores.end());
    return st.size();
  }
};