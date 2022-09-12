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
    unordered_map<int, int> storeInorder;
    int preIndex = 0;
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int start, int end){
        if(start > end){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        
        int inIndex = storeInorder[preorder[preIndex]];
        preIndex++;
        
        root->left = helper(preorder, inorder, start, inIndex - 1);
        root->right = helper(preorder, inorder, inIndex + 1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  
        for(int i = 0; i < inorder.size(); i++){
            storeInorder[inorder[i]] = i; 
        }
        
        return helper(preorder, inorder, 0, inorder.size()-1);
    }
};