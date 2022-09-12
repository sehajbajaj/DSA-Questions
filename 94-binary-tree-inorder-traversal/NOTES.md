#### A binary tree is threaded by making all right child pointers that would normally be null point to the inorder successor of the node (if it exists), and all left child pointers that would normally be null point to the inorder predecessor of the node.
​
- Morris traversal does not use any extra space to do inorder traversal of binary tree.
- Inorder traversal follows [left, root, right] path.
- Starting from root, we visit the left subtree and then we come back to the root again and then visit the left subtree.
- WHY DO WE NEED STACK OR RECURSION? Because when we are going from the root to left child, we need a way to come back to root to process it and this is what is achieved with the help of a stack where we keep pushing the nodes into the stack and popping them and recursion alse does the same.
- **The morris traversal anyhow solves this problem of going back in constant time**
- What we do is, find inorder predecessor of the current node before even going on the left subtree.
- Connect that to the current node in order to establish a link between the inorder predecessor and the node and then go on the left subtree.
- This way since the link exists we have a way to come back to the original node.
- Case 1: When the current node has no left subtree. In this scenario, there is nothing to be traversed on the left side, so we simply print the value of the current node and move to the right of the current node.
- Case 2: When there is a left subtree and the right-most child of this left subtree is pointing to null. In this case we need to set the right-most child to point to the current node, instead of NULL and move to the left of the current node.
- Case 3: When there is a left subtree and the right-most child of this left-subtree is already pointing to the current node. In this case we know that the left subtree is already visited so we need to print the value of the current node and move to the right of the current node.
​
To summarize, at a node whether we have to move left or right is determined whether the node has a left subtree. If it doesn’t we move to the right. If there is a left subtree then we see its rightmost child. If the rightmost child is pointing to NULL, we move the current node to its left. If the rightmost child is already pointing towards the current node, we remove that link and move to the right of the current node. We will stop the execution when the current points to null and we have traversed the whole tree.
​