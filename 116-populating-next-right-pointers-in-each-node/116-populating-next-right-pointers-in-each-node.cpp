/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //Using curr and nxt pointers and connecting the next pointers befor actually traversing the levels
    //TC = O(N) AND SC = O(1)
    Node* connect(Node* root) {
        
        if(root == NULL){
            return root;
        }
        
        Node* curr = root;
        Node* nxt;
        
        if(root != NULL){
            nxt = root->left;
        }else{
            nxt = NULL;
        }
        
        while(curr != NULL and nxt != NULL){
            curr->left->next = curr->right;
            
            if(curr->next){
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
            
            if(curr == NULL){
                curr = nxt;
                nxt = curr->left;
            }
        }
        return root;
    }
};