#### BFS or DFS algo
​
- We observe that 0s at boundary of the grid cannot be replaced and so do the 0s connected with the boundary 0.
- What we can do is, find all the 0s at the boundary and perform DFS or BFS traversal from there to mark all the 0s connected to them as non replacable and visited.
- Traverse over the grid again and if there are still some 0s left that are not visited, replace them with X.
​
#### TC - O(N) + O(N) + O(NxM) and SC - O(NxM)