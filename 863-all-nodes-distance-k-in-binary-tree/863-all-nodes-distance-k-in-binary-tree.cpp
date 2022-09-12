/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*> &parentMap, unordered_set<TreeNode*> &visited, vector<int> &result){
        if(root == NULL){
            return;
        }
        
        if(visited.count(root) == 1){
            return;
        }
        
        if(k == 0){
            result.push_back(root->val);
            return;
        }
        visited.insert(root);
        helper(root->left, k - 1, parentMap, visited, result);
        helper(root->right, k - 1, parentMap, visited, result);
        helper(parentMap[root], k - 1, parentMap, visited, result);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                TreeNode* frontElement = q.front();
                q.pop();
                
                if(frontElement->left != NULL){
                    q.push(frontElement->left);
                    parentMap[frontElement->left] = frontElement;
                }
                if(frontElement->right != NULL){
                    q.push(frontElement->right);
                    parentMap[frontElement->right] = frontElement;
                }
            }
        }
        
        unordered_set<TreeNode*> visited;
        vector<int> result;
        
        helper(target, k, parentMap, visited, result);
        return result;
    }
};