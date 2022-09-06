### DFS
​
- If root is null, return empty vector.
- Helper Function
- base case: if the node is a leaf node, check if root's value is equal to target sum or you can also check if target sum - root->val is 0, push the list in the ans vector. Pop the last element in list to backtrack to check the other paths as well.
- We have 2 options, either consider the left child or the right child.
- Considering left child, push it's value in the list and make a call. After computations, make sure to pop the left child from the list to back track.
- Repeat the same for the right child.
​
### TC - O(N) and SC - O(H)