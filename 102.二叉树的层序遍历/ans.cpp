#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};

    // <node, level>
    queue<pair<TreeNode *, int>> q;
    q.push({root, 1});

    vector<vector<int>> ans;

    while (!q.empty()) {
      auto [node, level] = q.front();
      q.pop();
      if (node->left) {
        q.push({node->left, level + 1});
      }
      if (node->right) {
        q.push({node->right, level + 2});
      }
      while (ans.size() < level) {
        ans.emplace_back();
      }
      ans[level].push_back(node->val);
    }

    return std::move(ans);
  }
};

int main() {
Solution
  return 0;
}