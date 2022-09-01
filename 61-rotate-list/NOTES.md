### Using length of the linked list.
​
- Traverse over the whole Linked List and calculate length side by side.
- Connect the last node's next to head.
- Calculate rotation = k % len => helps to rotate the list even if it's length is more than k.
- Calculate the no. of skips needed to get the new head and new tail.
- Take a pointer, say newEnd = head and traverse over the list till it reaches the node just before the new head (skips-1).
- Update the head to the new tail's next.
- Assign new tail's next = null.
- Return head.
​
​
### TC -> O(N) and SC -> O(1)