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
    int postIndex;
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int start, int end){
        if(start > end){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postIndex]);
        int inIndex = storeInorder[postorder[postIndex]];
        postIndex--;
        
        root->right = helper(inorder, postorder, inIndex + 1, end);
        root->left = helper(inorder, postorder, start, inIndex - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = inorder.size() - 1;
        for(int i = 0; i < inorder.size(); i++){
            storeInorder[inorder[i]] = i;
        }
        
        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};