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
    int helper(TreeNode* root, long long csum, int tsum, bool reset, set<TreeNode*>& resetted) {
        if (!root) return 0;

        if (reset and resetted.find(root) != resetted.end()) {
            return 0;
        }
        if (reset) {
            resetted.insert(root);
        }
        
        csum += root->val;
        int count = 0;

        if (csum == tsum) count++;

        count += helper(root->left, csum, tsum, 0, resetted);
        count += helper(root->right, csum, tsum, 0, resetted);
        count += helper(root->left, 0, tsum, 1, resetted);
        count += helper(root->right, 0, tsum, 1, resetted);
        
        return count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        bool reset = 1;
        set<TreeNode*> resetted;
        return helper(root, 0, targetSum, reset, resetted);
    }
};