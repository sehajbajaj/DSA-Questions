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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> storeNodes;
        queue<pair<TreeNode*, pair<int, int>>> tree;
        tree.push({root, {0, 0}});
        
        while(!tree.empty()){
            auto p = tree.front();
            tree.pop();
            TreeNode* curr = p.first;
            int hd = p.second.first;
            int level = p.second.second;
            
            storeNodes[hd][level].insert(curr->val);
            
            if(curr->left != NULL){
                tree.push({curr->left, {hd - 1, level + 1}});
            }
            if(curr->right != NULL){
                tree.push({curr->right, {hd + 1, level + 1}});
            }
        }
        
        vector<vector<int>> answer;
        for(auto p : storeNodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            answer.push_back(col);
        }
        return answer;
    }
};