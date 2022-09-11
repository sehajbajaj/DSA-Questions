### Using DFS
​
- Base conditions: 1. if root1 is null return root2 and if root2 is null return root1.
- Take a variable, say val = 0 initially and keep addint to it the values of the root1 and root2 if any of them is not null.
- Create a new node of value val.
- Make recursive calls for new node's left and right
- Return new node.