#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right){};
};
class Solution {
public:
  int ans[2][2];
  bool f = false;
  void heightandparent(TreeNode *root, int x, int h, int type) {
    if (f == true)
      return;
    if ((root->left != NULL && root->left->val == x) ||
        (root->right != NULL && root->right->val == x)) {
      ans[type][0] = root->val;
      ans[type][1] = h + 1;
      f = true;
    } else {
      if (root->left != NULL)
        heightandparent(root->left, x, h + 1, type);
      if (root->right != NULL)
        heightandparent(root->right, x, h + 1, type);
    }
  }
  bool isCousins(TreeNode *root, int x, int y) {
    f = false;
    heightandparent(root, x, 0, 0);
    f = false;
    heightandparent(root, y, 0, 1);
    cout << ans[0][0] << " " << ans[0][1] << " " << ans[1][0] << " "
         << ans[1][1] << endl;
    if (ans[0][1] == ans[1][1] && ans[0][0] != ans[1][0])
      return true;
    return false;
  }
};

int main() {
  TreeNode *a = new TreeNode(1);
  a->left = new TreeNode(2);
  a->right = new TreeNode(3);
  a->left->right = new TreeNode(4);
  a->right->right = new TreeNode(5);
  Solution s;
  cout << s.isCousins(a, 4, 5);
}
