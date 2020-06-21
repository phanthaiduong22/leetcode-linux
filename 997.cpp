// 997
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    if (trust.size() == 0)
      if (N > 1)
        return -1;
      else
        return 1;
    map<int, int> d;
    map<int, bool> noway;
    for (int i = 0; i < trust.size(); i++) {
      d[trust[i][1]]++;
      noway[trust[i][0]] = true;
    }
    map<int, int>::iterator it;
    for (it = d.begin(); it != d.end(); it++) {
      if (noway[it->first] == false and it->second == N - 1)
        return it->first;
    }
    return -1;
  }
};

int main() {
  vector<vector<int>> v = {{1, 3}, {2, 3}};
  Solution s;
  cout << s.findJudge(3, v);
}
