#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int singleNonDuplicate(vector<int> &a) {
    if (a.size() == 1)
      return a[0];
    int l = 0;
    int r = a.size() - 1;
    int m = 0;
    while (l <= r) {
      m = (l + r) / 2;
      cout << m << " ";
      if (m == 0)
        m = 1;
      if (m == a.size() - 1)
        m = a.size() - 2;
      if (m - 1 == 0 && a[m] != a[m - 1])
        return a[m - 1];
      else if (m == a.size() - 2 && a[m] != a[m + 1])
        return a[m + 1];
      else if (a[m] != a[m - 1] && a[m] != a[m + 1])
        return a[m];
      else if (a[m] == a[m - 1]) {
        if (m % 2 == 0) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else if (a[m] != a[m - 1]) {
        if (m % 2 == 0) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
    return a[m];
  }
};

int main() {
  vector<int> v = {3, 3, 7, 7, 10, 11, 11};
  Solution s;
  cout << s.singleNonDuplicate(v);
}
