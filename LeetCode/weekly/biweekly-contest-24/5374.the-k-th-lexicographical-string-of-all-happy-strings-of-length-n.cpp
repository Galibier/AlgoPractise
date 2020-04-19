#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> res;
int cnt = 0;
string ret = "";

void backtrace(int n, int k, string str) {
  if (str.size() == n) {
    res.push_back(str);
    cnt++;
    if (cnt == k) ret = str;
    return;
  }

  if (str[str.size() - 1] != 'a') backtrace(n, k, str + "a");
  if (str[str.size() - 1] != 'b') backtrace(n, k, str + "b");
  if (str[str.size() - 1] != 'c') backtrace(n, k, str + "c");
}

string getHappyString(int n, int k) {
  cnt = 0;
  ret = "";
  backtrace(n, k, "a");
  backtrace(n, k, "b");
  backtrace(n, k, "c");
  return ret;
}

int main() {
  cout << getHappyString(1, 3) << endl;
  cout << getHappyString(1, 4) << endl;
  cout << getHappyString(3, 9) << endl;
  cout << getHappyString(2, 7) << endl;
  cout << getHappyString(10, 100) << endl;
  return 0;
}