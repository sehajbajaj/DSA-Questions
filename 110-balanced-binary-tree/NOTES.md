### DFS
​
- The idea is to check for a balanced tree while calculating heigth of the binary tree.
- A balanced tree is a tree when leftHeight - rightHeight lies in the range of -1, 0, 1.
- If at any point the tree becomes unbalanced return -1. Also, check if the left or the right subtree returns a -1 then immediately return -1 without making further computations.
​
### TC - O(N) and SC - O(N)