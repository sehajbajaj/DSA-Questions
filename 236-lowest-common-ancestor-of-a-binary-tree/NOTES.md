### DFS
​
- LCA of p and q is the lowest common ancestor.
- The conditions to be taken care of are:
- Both p and q lie in the same side of the tree i.e in the same subtree then the answer will be the node encountered first.
- Both p and q lie in different subtrees. The answer will be the root itself because that is their closest link.
- Both p and q are null, the answer is null.
​
### TC - O(N) and SC - O(N)