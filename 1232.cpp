#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
  bool checkStraightLine(vector<vector<int>>& coordinates)
  {
    double temp = coordinates[1][1] - coordinates[0][1];
    double temp1 = coordinates[1][0] - coordinates[0][0];
    double a = temp / temp1;
    double b = coordinates[0][1] - a * coordinates[0][0];

    bool ans = true;
    for (int i = 1; i < coordinates.size(); i++)
      if (coordinates[i][0] != coordinates[i - 1][0]) {
        ans = false;
        break;
      }
    if (ans) return true;
    for (int i = 1; i < coordinates.size(); i++)
      if (coordinates[i][1] != coordinates[i - 1][1]) {
        ans = false;
        break;
      }
    if (ans) return true;
    for (int i = 2; i < coordinates.size(); i++) {
      if (coordinates[i][1] != coordinates[i][0] * a + b) return false;
    }
    return true;
  }
};
int main()
{
  vector<vector<int>> v = {{0, 0}, {0, 1}, {0, -1}};
  Solution s;
  cout << s.checkStraightLine(v);
}
