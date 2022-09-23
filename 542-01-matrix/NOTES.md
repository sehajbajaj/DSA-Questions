#### BFS Algo
​
- For 1's we need the nearest 0's.
- So, if we go level by level as in BFS
- Starting from a 0, 1's at 1st level will have nearest 0 at a distance of 1
- 2nd level 1's will have the nearest 0 at a distance 0.
- Now, we know that this problem can be solved using BFS,
- Requirements: visited matrix, ans matrix to store the ans.
​
#### TC - O(NxM)+O(NxMx4) and SC - O(NxM)