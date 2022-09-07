### Using DFS
​
- What we can do is solve them as 2 trees.
- Check if the root1's left is equal to root2' right and vice - versa.
- The whole process can be done recusively.
​
### TC->O(n)
### SC->O(n)
​
```
bool solve(TreeNode* root1, TreeNode* root2){
if(!root1 and !root2){
return true;
}
if(!root1 or !root2){
return false;
}
return root1->val == root2->val and
solve(root1->left, root2->right) and solve(root1->right, root2->left);
}
bool isSymmetric(TreeNode* root) {
return solve(root, root);
}
```
​
### Can be solved iteratively as well.
- Use 2 queues and perform BFS.
- Push the root in both the queues and pop them and check if both are equal or not and push their left and right children into both the queues as well.