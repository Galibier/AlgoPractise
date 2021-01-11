#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.size() == 0 || !wordSet.count(endWord)) {
      return 0;
    }

    unordered_set<string> visited, beginvisited, endvisited;
    beginvisited.insert(beginWord);
    endvisited.insert(endWord);

    int step = 1;
    while (!beginvisited.empty() && !endvisited.empty()) {
      if (beginvisited.size() > endvisited.size()) {
        unordered_set<string> temp = beginvisited;
        beginvisited = endvisited;
        endvisited = temp;
      }
      unordered_set<string> nextLevelvisited;
      for (string word : beginvisited) {
        if (changeWordEveryoneLetter(word, endvisited, visited, wordSet,
                                     nextLevelvisited))
          return step + 1;
      }
      beginvisited = nextLevelvisited;
      step++;
    }
    return 0;
  }

  bool changeWordEveryoneLetter(string word, unordered_set<string> endvisited,
                                unordered_set<string>& visited,
                                unordered_set<string> wordSet,
                                unordered_set<string>& nextLevelvisited) {
    for (int i = 0; i < word.length(); i++) {
      char originChar = word[i];
      for (char c = 'a'; c <= 'z'; c++) {
        if (originChar == c) {
          continue;
        }
        word[i] = c;
        if (wordSet.count(word)) {
          if (endvisited.count(word)) {
            return true;
          }
          if (!visited.count(word)) {
            nextLevelvisited.insert(word);
            visited.insert(word);
          }
        }
      }
      word[i] = originChar;
    }
    return false;
  }
};

int main() {
  Solution sol;
  return 0;
}