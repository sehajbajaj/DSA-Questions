/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void treeToString(TreeNode* root, string &s){
        if(root == NULL){
            s += to_string(1005);
            s += ' ';
            return;
        }
        
        s += to_string(root->val);
        s += ' ';
        treeToString(root->left, s);
        treeToString(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s = "";
        treeToString(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    int i = 0;
    TreeNode* stringToTree(string &s){
        if(i == s.length()){
            return NULL;
        }
        
        string t="";
        while(i < s.length() and s[i] != ' '){
            t += s[i];
            i++;
        }
        i++;
        int val = stoi(t);
        if(val == 1005){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(val);
        root->left = stringToTree(s);
        root->right = stringToTree(s);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        return stringToTree(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));