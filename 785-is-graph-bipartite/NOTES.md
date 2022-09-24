#### BFS or DFS Algo
​
- A bipartite graph is a graph in which no 2 adjacent nodes can be colored with the same color.
- A linear acyclic graph is always bipartite.
- A cyclic graph with even length cycle is always bipartite but a cyclic graph with odd cycle length is never bipartite.
- Starting from any node, we will have to check if the current node is already colored or not. If not colored assign it with a color.
- Also, ensure that the nbrs of the current node has correct (different) color so that no adjacent nodes can be colored with same color.
- The moment we get to a node which is already colored before and that too incorrectly (should be 1 but is 0 or vice versa). It means some other node has already colored it with an incorrect color, return false.
- Return true.
​
#### TC - O(N + 2E) and SC - O(N)