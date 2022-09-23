#### BFS or DFS Algo
​
- Using BFS Algo
- We want the number of land cells (1's) surrounded by the boundary.
- 1's connected to the boundary will never be a part of the ans and their neighbouring 1's will also not be the part of the answer.
- We can firstly find the boundary 1s and connect all the neigbouring 1s to it. The ramining 1s will be the ans.
- Applying multisource BFS.
- Traverse the grid to count total number of 1s and mark all the boundary 1s as visited. Also push them into the queue.
​
​
#### TC - O(NxMx4)+O(NxM) and SC - O(NxM)