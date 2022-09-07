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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL){
            return true;
        }
        
        if((p == NULL and q != NULL) or (p != NULL and q == NULL)){
            return false;
        }
        
        return (p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL){
            return true;
        }
        
        if((root == NULL and subRoot != NULL) or(root != NULL and subRoot == NULL)){
            return false;
        }
        
        if(isSameTree(root, subRoot)){
            return true;
        }
        
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};