#### We can use any traversal - BFS or DFS
​
- Here, provinces refer to connected components.
- In any traversal technique, there is a single starting point. But what if the graph has connected components then there will be multiple starting points.
- If we figure out the number of starting points which help to traverse the whole graph then we can definitely figure out the number of provinces as well.
- Using DFS -
- Create an adjacency list from the matrix given, and a visited array.
- Perform DFS traversal for no. of nodes but in keep in mind that the dfs traversal will be called for only the starting points as the nodes connected with a particular starting node will be traversed in a single call only.
- Keep a counter variable that counts the no. of traversals = no. of starting nodes = no. of provinces.
​
#### TC - O(N) + O(N+2E) {outer loop + inner loop runs a total of 1 dfs traversal over the graph} and SC - O(N)
​