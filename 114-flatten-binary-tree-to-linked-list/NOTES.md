}
flatten(root->right);
flatten(root->left);
root->right = prev;
root->left = NULL;
prev = root;
}
};
```
​
### Using the idea of Morris Traversal
​
- From the given example, we make an important observation:
- **Rightmost child of left subtree is always connected to current node's immediate right child.**
- Using the above observation, we are gong to solve this question.
- Keep checking if there is a left child for the current node. If the left child exists take a pointer say prev = curr->left.
- Find the rightmost child of the left subtree of the current node. Once, we found the rightmost child update the pointers to form a LL.
- prev->right points to curr->right (observed condition)
- curr->right points to curr->left
- curr->left points to NULL
- Update curr to it's right child
​
### TC - O(N) and SC - O(1)