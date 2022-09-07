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
    
    int helper(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }
        
        int leftSum = max(0, helper(root->left, ans));
        int rightSum = max(0, helper(root->right, ans));
        int straightPath = root->val + max(leftSum, rightSum);
        ans = max(ans, root->val + leftSum + rightSum);
        
        return straightPath;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};