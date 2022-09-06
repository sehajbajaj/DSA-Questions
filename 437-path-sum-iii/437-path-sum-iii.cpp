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
    void helper(TreeNode* root, long long csum, int tsum, int& ans, unordered_map<long long, int>& mark) {
        if (!root) return;
        
        csum += root->val;
        if(csum == tsum){
            ans++;
        }
        ans += mark[csum];
        long long goal = csum + tsum;
        mark[goal] += 1;
        helper(root->left, csum, tsum, ans, mark);
        helper(root->right, csum, tsum, ans, mark);
        mark[goal] -= 1;
}
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> mark;
        helper(root, 0, targetSum, ans, mark);
        return ans;
    }
};