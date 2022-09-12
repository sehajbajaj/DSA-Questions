### The idea is to use binary tree threading just like we did in inorder traversal using Morris traversal.
​
- Do just the opposite of what we did in inorder traversal.
- Start looking for the right child first.
- If right child is null, add the current node's value to answer vector. Update current to it's right.
- Else, take the prev pointer to current node's right and keep going till its left untile prev->left is not null or not equal to current node.
- If the prev's left becomes null, push the current node's value in the answer vector and also update prev's left pointer to point to the current node to form a link between the predecessor and the current node. Update cureent to its right.
- If the prev's left pointer points to current node, it means the right tree is traversed completely. Break the link and update curr to its left.
​
### TC - O(N) and SC - O(1)