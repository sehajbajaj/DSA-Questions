### DFS - recursive
​
- If root is null, the shortest path from root to leaf node or the minimum depth will be 0.
- If there is only 1 node in the tree that is there is no left child or right child. It is a leaf node the minimum depth will be 1.
- Considering the above two conditions, the question can be solved using recursion.
- Call for the left subtree and add 1 to the answer returned (depth increased).
- Call for right subtree and add 1 to the answer returned.
- else Return 1  + min(leftcall, rightcall)
​
### TC -> O(N) and SC -> O(H) where h is the height of the tree.
​
### BFS - level order traversal
​
- While doing the level order check for the following conditions
- If the node is a leaf node, return depth which is initially 1.
- If there is a left child, push it in the queue
- if there is a right child, push it in the queue.
- Keep incrementing the depth after each level.
​
### TC -> O(N) and SC -> O(w) where w is the max width of binary tree