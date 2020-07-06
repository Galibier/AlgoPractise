#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/* 一、Sunday 匹配机
 * 匹配机制非常容易理解
 *    目标字符串Strin
 *    模式串 Patter
 *    当前查询索引 idx （初始为 00
 *    待匹配字符串 str_cut : String [ idx : idx + len(Pattern)
 * 每次匹配都会从 目标字符串中 提取 待匹配字符串与 模式串 进行匹配
 *    若匹配，则返回当前 id
 *    不匹配，则查看 待匹配字符串 的后一位字符 c
 *        若c存在于Pattern中，则 idx = idx + 偏移表[c
 *        否则，idx = idx + len(pattern
 * Repeat Loop 直到 idx + len(pattern) > len(String)
 */

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int hSize = haystack.size();
    int nSize = needle.size();
    unordered_map<char, int> pianyi;
    for (int i = 0; i < nSize; i++) pianyi[needle[i]] = nSize - i;

    int i = 0;
    while (i <= hSize - nSize) {
      if (haystack.substr(i, nSize) == needle)
        return i;
      else {
        if (i + nSize > hSize - 1)
          return -1;
        else {
          if (pianyi.find(haystack[i + nSize]) != pianyi.end()) {
            i += pianyi[haystack[i + nSize]];
          } else {
            i += nSize + 1;
          }
        }
      }
    }

    return -1;
  }
};

class SolutionKMP {
 public:
  int strStr(string haystack, string needle) {
    if (!needle.size()) return 0;
    if (!haystack.size()) return -1;
    int j = -1, i = 0;
    vector<int> b(needle.size() + 1);
    b[i] = j;
    while (i < needle.size()) {
      while (j >= 0 && needle[i] != needle[j]) j = b[j];
      i++, j++;
      b[i] = j;
    }

    j = 0, i = 0;
    while (j < haystack.size()) {
      while (i >= 0 && needle[i] != haystack[j]) i = b[i];
      i++, j++;
      if (i == needle.size()) {
        return j - needle.size();
      }
    }
    return -1;
  }
};

int main() {
  Solution sol = Solution();
  string haystack = "hello", needle = "ll";
  cout << sol.strStr(haystack, needle) << endl;
  haystack = "aaaaa", needle = "bba";
  cout << sol.strStr(haystack, needle) << endl;

  return 0;
}