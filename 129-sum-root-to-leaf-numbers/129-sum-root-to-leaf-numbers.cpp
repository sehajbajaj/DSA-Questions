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
    
    void solve(TreeNode* root, int num, int &sum){
        if(!root) return;
        
        num = num * 10 + root->val;
        if(root->left == NULL and root->right == NULL){
            sum += num;
            return;
        }
        solve(root->left, num, sum);
        solve(root->right, num, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
};