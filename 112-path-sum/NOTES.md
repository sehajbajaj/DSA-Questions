### DFS
​
- Base case: if root is null, return false.
- We can have a helper function to solve the problem
- Keep track of current sum while traversing the tree.
- Once we hit the leaf node, check if current sum is equal to targetSum, return true else return false.
- But if we haven't hit the leaf node yet, we still have to go through all the nodes and any of the left or right path can sum up to targetSum. Return true if either if the left or right calls return true.
​
### TC - O(N) and SC - O(H)