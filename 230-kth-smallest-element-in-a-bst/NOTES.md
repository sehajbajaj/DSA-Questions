}
inorder(root->left, k, cnt, res);
cnt++;
if(cnt == k){
res = root->val;
return;
}
inorder(root->right, k, cnt, res);
}
int kthSmallest(TreeNode* root, int k) {
int res, count = 0;
inorder(root, k, count, res);
return res;
}
```
​
### 2nd approach
#### Modifying the node structure, having a lcount = 0 and increment it everytime a node is inserted.
​
#### TC->O(h)
#### SC->O(h)
​
```
if(!root){
return NULL;
}
​
if(root->lcount+1==k){
return root;
}
​
if(root->lcount+1 >k){
return fun(root->left, k);
}
​
return fun(root->right, k-locount-1);
```