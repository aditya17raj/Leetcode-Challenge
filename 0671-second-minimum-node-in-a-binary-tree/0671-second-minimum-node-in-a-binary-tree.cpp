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
    void traverse(TreeNode* root, set<int> &st){
        if(root == nullptr){
            return;
        }

        traverse(root->left, st);
        st.insert(root->val);
        traverse(root->right, st);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        traverse(root, st);

        if(st.size() == 1)
            return -1;

        int cnt=2;
        for(auto it:st){
            cnt--;
            if(cnt == 0)
                return it;
        }

        return -1;
    }
};