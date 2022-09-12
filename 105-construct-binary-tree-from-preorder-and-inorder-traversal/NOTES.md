- Preorder traversal - [root, left, right] and Inorder traversal - [left, root, right]
- It's sure that the root of the binary tree will be the first element in the preorder array.
- Now, to construct left and right subtrees for the binary tree we will use recursion.
- The next intuitive step is to locate the root node's value in the inorder array. As the inorder array gives us the [left, root, right], the nodes at the left of the root node's value will form the left subtree and right nodes will form the right subtree. We will use Hashmaps to store the indexes in the inorder array as it gives the value of the index in constant time.
- Mark the index of the root node's value found in inorder array as Inindex. It refers to the current iterating index of the preorder array.
- Once the inorder array index is found, recursive calls are made to construct the left and right subtree.
- Left: (start, end) = (start, inIndex - 1) to find the next root i.e the left subtree's root in the range [start, index just before the current root].
- Right: (start, end) = (inIndex + 1, end) to find the next root i.e the right subtree's root in the range [index just after the current root, end].
​
### TC - O(N) and SC - O(N)