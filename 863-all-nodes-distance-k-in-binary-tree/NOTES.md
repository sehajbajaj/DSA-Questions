### Using BFS + Parent map + visited set
​
- **The idea is to keep track of the parent node while traversing the tree.**
- Perform BFS and store the parents of the nodes in a map.
- After all the parents are stored, perform DFS.
- Mark the current root visited
- Check if the children of the current root are already not visited then make recursive calls on the left and right children.
- Also, recurively call for helper for the parent node. This step helps to find the nodes at k distance from the target node if the nodes are not in the path from the root to target i.e lie in other subtree.
- Push the node to the answer vector, when k becomes 0.
​
​