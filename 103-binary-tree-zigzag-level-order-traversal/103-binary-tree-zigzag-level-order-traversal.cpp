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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        
        if(!root){
            return ans;
        }
        
        stack<TreeNode*> s1, s2;
        
        s1.push(root);
        while(!s1.empty() or !s2.empty()){
            while(!s1.empty()){
                TreeNode* curr = s1.top();
                s1.pop();
                
                v.push_back(curr->val);
                if(curr->left){
                    s2.push(curr->left);
                }
                
                if(curr->right){
                    s2.push(curr->right);
                }
            }
            if(v.size()){
                ans.push_back(v);
            }
            v.clear();
            while(!s2.empty()){
                TreeNode* curr = s2.top();
                s2.pop();
                
                v.push_back(curr->val);
                if(curr->right){
                    s1.push(curr->right);
                }
                
                if(curr->left){
                    s1.push(curr->left);
                }
            }
            if(v.size()){
                ans.push_back(v);
            }
            v.clear();
        }
        return ans;
    }
};