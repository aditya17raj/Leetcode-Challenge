/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int &maxSum){
        if(root == nullptr)
            return 0;

        int left = solve(root->left, maxSum);
        int right = solve(root->right, maxSum);

        //condition-1 leftsum+rightsum+cur->val is maximum
        int cnd1 = left + right + root->val;

        //condition-2 either left or right sum is maximum
        int cnd2 = max(left, right) + root->val;

        //condition-3 root node has maximum val
        int cnd3 = root->val;

        maxSum = max( maxSum, (max(cnd1,max(cnd2,cnd3))) );

        return max(cnd2, cnd3);
    }


    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);

        return maxSum;
    }
};