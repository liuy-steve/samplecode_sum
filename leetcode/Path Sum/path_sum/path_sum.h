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
       return false;
    }

private:
	bool TryNewNode(TreeNode *node)
	{
		if (node == NULL)
		{
			return false;
		}
		if (view_recode_.end() != find(view_recode_.begin(), view_recode_.end(), node))
		{
			view_recode_.push_back(node);
			return true;
		}
		return false;
	}

	bool ScreenNode(TreeNode *node)
	{
		return false;
	}

	bool AddNode(TreeNode *node, int sum)
	{
		if (TryNewNode(node))
		{
			path_statck_.push(node);
			s_sum += node->val;
		}

		if (s_sum == sum)
		{
			return true;
		}

		if (TryNewNode(node))
		{
			return false;
		}

		

		return AddNode(node->left, sum) || AddNode(node->right, sum);
	}

private:
	stack<TreeNode*> path_statck_;
	vector<TreeNode*> view_recode_;
};