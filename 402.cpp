#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    string ans = "";
    for (int i = 1; i < num.size(); i++) {
      if (k > 0) {
        if (num[i - 1] > num[i])
          k--;
        else
          ans += num[i - 1];
      } else
        ans += num[i - 1];
    }
    if (k == 0)
      ans += num[num.size() - 1];
    bool take = 0;
    string res = "";
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] != '0' && take == 0) {
        take = 1;
      }

      if (take == 1)
        res += ans[i];
    }
    if (res == "")
      return "0";
    else
      return res;
  }
};

int main() {
  Solution s;
  cout << s.removeKdigits("10", 2);
}
