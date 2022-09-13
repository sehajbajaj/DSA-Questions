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
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        TreeNode* currentNode = root;
        TreeNode* prev;
        while(currentNode != NULL){
            if(currentNode->left != NULL){
                prev = currentNode->left;
                
                while(prev->right != NULL){
                    prev = prev->right;
                }
                prev->right = currentNode->right;
                currentNode->right = currentNode->left;
                currentNode->left = NULL;
            }
            currentNode = currentNode->right;
        }
    }
};