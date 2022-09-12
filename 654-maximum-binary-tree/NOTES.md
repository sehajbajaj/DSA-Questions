### DFS
​
- The idea is to find the maximum element in the array and make it the root.
- Store the index of the max element in a varibale, say idx.
- Make recursive calls to create the left and right subtrees.
- Left: (start, end) = (start, idx - 1)
- Right: (start, end) = (idx + 1, end)
​
### TC - O(n2) and SC - O(n)