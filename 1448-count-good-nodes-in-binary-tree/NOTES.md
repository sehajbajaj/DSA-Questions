### Using DFS
​
- Root is always a good node
- Assign maxValue as root's value
- In helper function, keep checking if current node's value is greater than or equal to maxValue then update maxValue, return 1 + no. of nodes in left subtree + no. of nodes in right subtree. We add 1 because the node itself is also a good node.
- And if the node's value is smaller than maxValue then simply return no. of nodes in left and right subtrees.
​
### TC -> O(N) and SC -> O(N)