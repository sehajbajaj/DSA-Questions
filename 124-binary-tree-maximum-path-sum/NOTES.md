### In a path we can only split once
​
#### Perform DFS
For every single node consider it as the top most node and try to find the maximum sum we can get from its left subtree and from its right subtree. So. for any node we have 3 options:
- The node itself
- The node with either of the subtrees
- The node with both the subtrees.
​
Add the maximum of them to the current node's value and we'll get the maximum path sum for that node without splitting. Without splitting means that we are considering just one side of the tree which returns us the maximum sum.
​
But since we can split only once, for every node also check if we split from that node that is combine the node's value with both the left and roght subtrees what answer will we get? If that's the maximum answer that would be the correct path as in example 2 [15, 20, 7]. Basically, a backtracking logic. **for a node, the sum is = node's val + leftsum + rightsum**. This formula is to be applied on every node.
Anyhow, the returning value will be the answer we get without splitting. Since, there cannot be a 3-way path.
​
Do keep in mind that a children for a node can be negative values as well which might reduce the sum so in that case we compare the left child and right child with 0 and maximum of them is added to the root's value. If both the nodes are negative, then on comparing with 0, leftsum and rightsum will also be 0 and adding it to root's value will give just the root's value.
​
​
```c++
// Time complexity = O(n)
// Space complexity = O(h)
int helper(TreeNode* root, int &res){
//we cannot split a leafnode
if(root == NULL){
return 0;
}
//Calculating maximum sum without split
int leftMax = max(0, helper(root->left, res));
int rightMax = max(0, helper(root->right, res));
//Calculating maximum sum with a split from the current node
res = max(res, root->val + leftMax + rightMax);
return root->val + max(leftMax, rightMax); //return the answer we get without splitting.
}
int maxPathSum(TreeNode* root) {
int res = INT_MIN;
int help = helper(root, res);
return res;
}
```
​
​