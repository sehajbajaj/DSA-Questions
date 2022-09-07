### DFS
​
- Depth is nothing but the height of the binary tree.
- Height is described as the no. of nodes in the longest path from the root to the leaf node.
- So, we will be calculating the no. of nodes in both the subtrees.
- Counting total no of nodes is -> 1 + no. of nodes in both left and right subtree but since height is denoted by the no. of nodes in lonegest path, we can consider on the longest subtree.
- Height will be 1 + maximum no of nodes returned. (either left subtree or right subtree)
​
### TC - O(N) and SC - O(N)