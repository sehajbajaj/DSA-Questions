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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int maxWidth = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            
            int levelSize = q.size();
            int leftMost = q.front().second;
            int rightMost = q.back().second;
            maxWidth = max(maxWidth, rightMost - leftMost + 1);
            
            for(int i = 0; i < levelSize; i++){
                TreeNode* frontElement = q.front().first;
                long long idx = q.front().second - leftMost;
                q.pop();
                
                if(frontElement->left){
                    q.push({frontElement->left, 2*idx+1});
                }
                
                if(frontElement->right){
                    q.push({frontElement->right, 2*idx+2});
                }
                
            }
        }
        return maxWidth;
    }
};