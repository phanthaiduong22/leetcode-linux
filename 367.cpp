#include <iostream>

using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    long long l = 1, r = num;
    long long m, ans = num;
    while (l <= r) {
      m = r - (r - l) / 2;
      if (m * m == num)
        return true;
      else if (m * m > num)
        r = m - 1;
      else
        l = m + 1;
    }
    return false;
  }
};

int main() {
  Solution s;
  cout << s.isPerfectSquare(9);
}
