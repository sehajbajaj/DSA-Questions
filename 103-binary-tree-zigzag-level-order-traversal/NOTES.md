### USE 2 STACKS
​
Its kind of a level order traversal but using 2 stacks.
We observe that after every level the direction of printing the nodes is reversed. So after each level we have to make sure that correct order is being printed.
​
1. In s1 push root and its children are pushed in s2.
2. Now the children of nodes in s2 are pushed in s1.
3. The whole process is repeated till the whole tree is traversed.
​
### TC -> O(N)  every node is visited exactly once
### SC -> O(2N)  two stacks are used
​
​