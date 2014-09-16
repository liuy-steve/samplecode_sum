#include <vector>
#include <stack>
#include <algorithm>
using std::vector;
using std::stack;
using std::find;
/**
 * Definition for binary tree */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
static int s_sum  = 0;
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
		
		if (root == NULL)
		{
			return false;
		}

		if (sum == root->val && root->left == NULL && root->right == NULL)
		{
			return true;
		}

		int sum_left = sum - root->val;
		return hasPathSum(root->left, sum_left) || hasPathSum(root->right, sum_left);
    }

};