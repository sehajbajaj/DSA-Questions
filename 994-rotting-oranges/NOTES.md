#### BFS Algo
​
- We observe a BFS algorithm because we want the rotten oranges to rot their neighbours at the same time. To ensure this, visit the guys at the same level.
- We need a queue that stores the indexes of the oranges along with the time taken for the orange to get rotten. (Use pairs)
- We need a visiting matrix to store that the current orange is visited and to ensure its not computed again.
- Since, we the fresh oranges can be rotten 4 directionally, maintain 2 extra direction arrays.
​
#### TC - O(NxM)+O(NxMx4) and SC - O(NxM)