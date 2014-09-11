
#define NULL 0

  //Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
        {
			return true;
        }

		if ((root->right != NULL && root->val >= minValue(root->right))
			|| (root->left != NULL && maxValue(root->left) >= root->val))
		{
			return false;
		}

		else
		{
			return isValidBST(root->left) && isValidBST(root->right);
		}
    }

	int maxValue(TreeNode *root)
	{
		while(root->right != NULL)
		{
			root = root->right;
		}

		return root->val;
	}

	int minValue(TreeNode *root)
	{
		while(root->left != NULL)
		{
			root = root->left;
		}

		return root->val;
	}
};