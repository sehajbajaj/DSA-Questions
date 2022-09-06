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
    vector<vector<int>> ans;
    
    void findPaths(TreeNode* root, int targetSum, vector<int> &list){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL and root->right == NULL and root->val == targetSum){
            list.push_back(root->val);
            ans.push_back(list);
            list.pop_back();
            return;
        }
        
        if(root->left){
            list.push_back(root->val);
            findPaths(root->left, targetSum - root->val, list);
            list.pop_back();
        }
        if(root->right){
            list.push_back(root->val);
            findPaths(root->right, targetSum - root->val, list);
            list.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> list;
        
        findPaths(root, targetSum, list);
        return ans;
    }
};