### Using BFS Traversal
​
- While traversing a level in the bst
- We run a loop from i = 0 till size of that level in order to traverse that level
- In the for loop, check if i is size - 1 push it in the answer vector. All the nodes on the right side are the last nodes in a particular level and hence the above logic works perfectly.
​
### TC - O(N) and SC - O(w+m) where w is the max width of binary tree and m is the no. of nodes on the right side.