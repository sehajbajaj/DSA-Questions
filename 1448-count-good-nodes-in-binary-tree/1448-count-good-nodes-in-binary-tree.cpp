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
    int helper(TreeNode* root, int maxValue){
        if(root == NULL){
            return 0;
        }
        
        if(root->val >= maxValue){
            maxValue = root->val;
            return 1 + helper(root->left, maxValue) + helper(root->right, maxValue);
        }
        return helper(root->left, maxValue) + helper(root->right, maxValue);
    }
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};