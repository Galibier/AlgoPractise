#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string numberToWords(int num) {
    if (num == 0) return small[0];
    string res;
    for (int i = 1000000000, j = 0; i > 0; i /= 1000, j++) {
      if (num >= i) {
        res += get_part(num / i) + big[j] + ' ';
        num %= i;
      }
    }
    while (res.back() == ' ') res.pop_back();
    return res;
  }

 private:
  string get_part(int num) {
    string res;
    if (num >= 100) {
      res += small[num / 100] + " Hundred ";
      num %= 100;
    }
    if (!num) return res;
    if (num >= 20) {
      res += decade[num / 10] + ' ';
      num %= 10;
    }
    if (!num) return res;
    res += small[num] + ' ';
    return res;
  }

  const string small[20] = {"Zero",    "One",       "Two",      "Three",
                            "Four",    "Five",      "Six",      "Seven",
                            "Eight",   "Nine",      "Ten",      "Eleven",
                            "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                            "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  const string decade[10] = {" ",     " ",     "Twenty",  "Thirty", "Forty",
                             "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  const string big[4] = {"Billion", "Million", "Thousand", " "};
};

int main() {
  Solution sol;
  cout << sol.numberToWords(123123123) << endl;
  return 0;
}