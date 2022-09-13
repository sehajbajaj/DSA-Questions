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
    void inorder(TreeNode* root, int k, int &count, int &result){
        if(root == NULL){
            return;
        }
        
        inorder(root->left, k, count, result);
        count++;
        if(count == k){
            result = root->val;
            return;
        }
        inorder(root->right, k, count, result);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int result, count = 0;
        inorder(root, k, count, result);
        return result;
    }
};