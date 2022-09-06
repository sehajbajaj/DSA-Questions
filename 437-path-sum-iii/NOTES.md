### Brute Force
​
- Focusing on the line, “The path does not need to start or end at the root or a leaf, …“, we can conclude that we can start from any point.
- In other words, we can restart our counting of the path sum from anywhere we like. We can either:
- start the sum counting from 0 – restarting
- continue the sum from what the parent gave us
- Let’s formalize this. Since we want to search for a path in a tree, we are going to use depth first search (DFS). It takes dfs(root, current_sum, target_sum, reset, resetted)
- where root is the node we are at currently, current_sum is the current path's sum, target_sum is the given sum, reset is a bool variable that tells us if we have to reset the current_sum or not, resetted is a set that helps in optimzing the code to avoid recomputations.
- Keep calculating the count of paths from the parent node and count of paths when current_sum is reset. If the resent request is sent and the current node is already present in the set, it means we are recomputing the sum for that node, to prevent this return 0. Else simply add the current node to the set and continue with the computations
​
### TC - O(N2) and SC - O(N)
​