### BFS
​
- The idea is to index the nodes while traversing.
- Maximum width of the tree can be found out by the formula
- rightmost node - leftmost node + 1
- Take a queue of type pair<TreeNode*, int> to store the node and it's index.
- The index of the root is 0. So push {root, 0} in the queue initially.
- While traversing the levels, keep track of the leftmost and rightmost node. Leftmost node lies at the front of the queue and rightmost node lies at back of the queue.
- Keep updating the ans = max(ans, rightmost - leftmost + 1)
- Traverse the level and push the children of the parent node along with their indices.
- Left child = index is 2 * index of parent node + 1
- Right child = index is 2 * index of parent node + 2
​
### TC - O(N) and SC - O(M)